#ifndef _AFD_HPP_
#define _AFD_HPP_

#include "Automata.hpp"

class AFD : public Automata{
public:
  AFD(std::string archivo, std::string tipo):Automata(archivo, tipo){};
  AFD(std::vector<Estado*> estados, std::vector<char> alfabeto, Estado* estadoInicial, std::vector<Transicion*> tablaDeTransiciones):Automata(estados, alfabeto, estadoInicial, tablaDeTransiciones){};
  bool cambiarDeEstadoAFD(std::vector<Estado*> estados, std::vector<Transicion*> tablaDeTransiciones, Estado* estadoActual, std::string cadena, char simbolo, int indice);
};

#endif

