#include "Subconjunto.hpp"

void Subconjunto::iniciarAlgoritmo(){
    int i = 0, k = 0;   
    AFN afn("afn.txt","AFN");   
    cout << "Se cargo el siguiente automata AFN:" << endl;
    afn.toString("AFN");
    cout << endl;
    cout << "/*****************************/" << endl << endl;
    cout << "Inicia el algoritmo..." << endl;
    generarTablaDePreprocesamiento(afn);   
    procesarEstadoInicial(afn);
    while(i < (int)subconjuntos.size()){
        for(int j = 0 ; j < (int)afn.automata_alfabeto.size() ; j++){
            moverConSimbolo(subconjuntos[i],afn.automata_alfabeto[j]); 
            sort(kernel.begin(),kernel.end());  
            if(kernel.size() > 0 && !existeElKernel()){ 
                cout << "Mover (Q" << i << ", " << afn.automata_alfabeto[j] << ")" << endl;
                agregarKernel(); 
                aplicarCerraduraEpsilon(kernels[k],afn.automata_tablaDeTransiciones); 
                k++; 
                sort(subconjunto.begin(),subconjunto.end());
                if(!existeElSubconjunto()){ 
                    agregarSubconjunto(); 
                    agregarTransicionAFD(i,(int)subconjuntos.size()-1,afn.automata_alfabeto[j]);
                }else{ 
                    subconjunto.clear(); 
                    agregarTransicionAFD(i,subconjuntoActual,afn.automata_alfabeto[j]);  
                    k--; 
                    kernels.erase(kernels.begin()+k); 
                }
            }else{ 
                if(kernel.size() > 0){ 
                    cout << "Mover (Q" << i << ", " << afn.automata_alfabeto[j] << ")" << endl;
                    imprimirMoverConSimbolo();
                    agregarTransicionAFD(i,kernelActual,afn.automata_alfabeto[j]); 
                    kernel.clear();
                }
            }
        }
        i++; 
    }
    generarEstados();   
    generarArchivo(&afn);  
    limpiarVectores(); 
    cout << "Termino el algoritmo." << endl << endl;
}

void Subconjunto::procesarEstadoInicial(AFN afn){
    estadoInicial = afn.obtenerEstadoInicial()->numeroDeEstado; 
    estadoFinal = afn.obtenerEstadosFinales().at(0)->numeroDeEstado;   
    aplicarCerraduraEpsilon(estadoInicial,afn.automata_tablaDeTransiciones);    
    sort(subconjunto.begin(),subconjunto.end()); 
    agregarSubconjunto(); 

void Subconjunto::limpiarVectores(){
    estadosAFD.clear();
    transicionesAFD.clear();
    tablaDePreprocesamiento.clear();
    subconjunto.clear();
    subconjuntos.clear();
    kernel.clear();
    kernels.clear();
}


void Subconjunto::generarArchivo(AFN *afn){
    ofstream archivo("afd.txt");
    if(archivo.is_open()){
        int j;
        j = afn->automata_alfabeto.size();
        archivo << j << endl;
        for(int i = 0 ; i < j ; i++){
            archivo << afn->automata_alfabeto[i] << endl;
        }
        j = estadosAFD.size();
        archivo << j << endl;
        for(int i = 0 ; i < j ; i++){
            if(estadosAFD[i]->esFinal){
                archivo << "s" << endl;
            }
            else{
                archivo << "n" << endl;
            }
        }
        j = transicionesAFD.size();
        archivo << j << endl;
        for(int i = 0 ; i < j ; i++){
            archivo << transicionesAFD[i]->estadoActual << endl;
            archivo << transicionesAFD[i]->estadoDeTransicion << endl;
            archivo << transicionesAFD[i]->simboloDeTransicion << endl;
        }
    }
}

void Subconjunto::generarEstados(){
    for(int i = 0 ; i < (int)subconjuntos.size() ; i++){
        estadosAFD.reserve(1);
        if(estaEnElSubconjunto(estadoFinal,subconjuntos[i])){ 
          
            estadosAFD.push_back(new Estado(i,true));
        }
        else{
        
            estadosAFD.push_back(new Estado(i,false));
        }
    }
}

void Subconjunto::agregarTransicionAFD(int estado1, int estado2, char simbolo){
    transicionesAFD.reserve(1);
    transicionesAFD.push_back(new Transicion(estado1,estado2,simbolo));
}

bool Subconjunto::existeElSubconjunto(){
    int j = subconjuntos.size();
    vector<int> diferencia;
    vector<int>::iterator it;
    for(int i = 0 ; i < j ; i++){
        if(subconjunto.size() == subconjuntos[i].size()){
            diferencia.reserve(subconjunto.size()*2);
            it = set_difference(subconjunto.begin(),subconjunto.end(),subconjuntos[i].begin(),subconjuntos[i].end(),diferencia.begin());
            diferencia.resize(it-diferencia.begin());
            if(diferencia.size() == 0){
                subconjuntoActual = i;
                return true;
            }
            else{
                diferencia.clear();
            }
        }
    }
    return false;
}

bool Subconjunto::existeElKernel(){
    int j = kernels.size();
    vector<int> diferencia;
    vector<int>::iterator it;
    for(int i = 0 ; i < j ; i++){
        if(kernel.size() == kernels[i].size()){
            diferencia.reserve(kernel.size()*2);
            it = set_difference(kernel.begin(),kernel.end(),kernels[i].begin(),kernels[i].end(),diferencia.begin());
            diferencia.resize(it-diferencia.begin());
            if(diferencia.size() == 0){
                kernelActual = i+1;
                return true;
            }
            else{
                diferencia.clear();
            }
        }
    }
    return false;
}

void Subconjunto::agregarSubconjunto(){
    subconjuntos.reserve(1);
    subconjuntos.push_back(subconjunto);
    imprimirCerraduraEpsilon();
    subconjunto.clear();
}

void Subconjunto::agregarKernel(){
    kernels.reserve(1);
    kernels.push_back(kernel);
    imprimirMoverConSimbolo();
    kernel.clear();
}

void Subconjunto::imprimirCerraduraEpsilon(){
    cout << "\tCerradura-E: {";
    for(int i = 0 ; i < (int)subconjunto.size() ; i++){
        if(i != (int)subconjunto.size()-1){
            cout << subconjunto[i] << ",";
        }
        else{
            cout << subconjunto[i];
        }
    }
    cout << "}" << endl;
}

void Subconjunto::imprimirMoverConSimbolo(){
    cout << "\tKernel: {";
    for(int i = 0 ; i < (int)kernel.size() ; i++){
        if(i != (int)kernel.size()-1){
            cout << kernel[i] << ",";
        }
        else{
            cout << kernel[i];
        }
    }
    cout << "}" << endl;
}

void Subconjunto::generarTablaDePreprocesamiento(AFN afn){
    for(int i = 0 ; i < (int)afn.automata_tablaDeTransiciones.size() ; i++){
        if(!afn.automata_tablaDeTransiciones[i]->esTransicionEpsilon){
            tablaDePreprocesamiento.reserve(1);
            tablaDePreprocesamiento.push_back(afn.automata_tablaDeTransiciones[i]);
        }
    }
}

void Subconjunto::moverConSimbolo(vector<int> misubconjunto, char simbolo){
    for(int i = 0 ; i < (int)misubconjunto.size() ; i++){
        for(int j = 0 ; j < (int)tablaDePreprocesamiento.size() ; j++){
            if(tablaDePreprocesamiento[j]->estadoActual == misubconjunto[i]){
                if(tablaDePreprocesamiento[j]->simboloDeTransicion == simbolo){
                    if(!estaEnElSubconjunto(tablaDePreprocesamiento[j]->estadoDeTransicion,kernel)){                 
                        kernel.reserve(1);
                        kernel.push_back(tablaDePreprocesamiento[j]->estadoDeTransicion);
                       }
                }
            }
        }
    }
}

bool Subconjunto::estaEnElSubconjunto(int estado, vector<int> misubconjunto){
    int j = misubconjunto.size();
    for(int i = 0 ; i < j ; i++){
        if(misubconjunto[i] == estado){
            return true;
        }
    }
    return false;
}


void Subconjunto::aplicarCerraduraEpsilon(int numeroDeEstado, vector<Transicion*> tablaDeTransiciones){
    int i;
    int k = tablaDeTransiciones.size();
    if(!estaEnElSubconjunto(numeroDeEstado,subconjunto)){
        subconjunto.reserve(1);
        subconjunto.push_back(numeroDeEstado);
    }
      for(i = 0 ; i < k ; i++){
        if(tablaDeTransiciones[i]->estadoActual == numeroDeEstado){
          if(tablaDeTransiciones[i]->simboloDeTransicion == 'E'){
            if(!estaEnElSubconjunto(tablaDeTransiciones[i]->estadoDeTransicion,subconjunto)){
                aplicarCerraduraEpsilon(tablaDeTransiciones[i]->estadoDeTransicion,tablaDeTransiciones);
            }
          }
        }
    }
}


void Subconjunto::aplicarCerraduraEpsilon(vector<int> miSubconjunto, vector<Transicion*> tablaDeTransiciones){
    int i;
    int k = tablaDeTransiciones.size();
    for(int j = 0 ; j < (int)miSubconjunto.size() ; j++){
        if(!estaEnElSubconjunto(miSubconjunto[j],subconjunto)){
            subconjunto.reserve(1);
            subconjunto.push_back(miSubconjunto[j]);
        }
    }
    for(int j = 0 ; j < (int)miSubconjunto.size() ; j++){
        for(i = 0 ; i < k ; i++){
            if(tablaDeTransiciones[i]->estadoActual == miSubconjunto[j]){
                if(tablaDeTransiciones[i]->simboloDeTransicion == 'E'){
                    if(!estaEnElSubconjunto(tablaDeTransiciones[i]->estadoDeTransicion,subconjunto)){
                        aplicarCerraduraEpsilon(tablaDeTransiciones[i]->estadoDeTransicion,tablaDeTransiciones);
                    }
                }
            }
        }
    }
}