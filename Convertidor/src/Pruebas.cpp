#include "Pruebas.hpp"
using namespace std;

Pruebas::Pruebas(){};

bool Pruebas::buscarSimbolo(vector<char> alfabeto, char simbolo){
  int k = alfabeto.size();
  for(int i = 0; i < k ; i++){
    if(alfabeto[i] == simbolo)
      return true;
  }
  return false;
}

vector<char> Pruebas::definirAlfabeto(int numeroDeSimbolos){
  vector<char> alfabetoAux; 
  char simbolo;
  for(int i = 0; i < numeroDeSimbolos; i++){   
    cout << "\nIngresa el simbolo " << i << ": ";
    cin >> simbolo;
    alfabetoAux.reserve(1);
    alfabetoAux.push_back(simbolo);
  }
  return alfabetoAux;   
}

vector<Estado*> Pruebas::agregarEstados(int numeroDeEstados){
  char esFinal; 
  vector<Estado*> estados; 
  for(int i = 0; i < numeroDeEstados; i++){
    if(i != 0){
      cout << "Estado q" << i << endl;
      cout << "\tEs estado final? (s/n) : ";
      cin >> esFinal;
      if(esFinal == 's' || esFinal == 'S'){
        estados.reserve(1);
        estados.push_back(new Estado(i,true));
      }
      else if(esFinal == 'n' || esFinal == 'N'){
          estados.reserve(1);
          estados.push_back(new Estado(i,false));
      }
    }
    else{
      cout << "\nEstado inicial q0" << endl;
      estados.reserve(1);
      estados.push_back(new Estado(i,false));
    }
  }
  return estados;
}
