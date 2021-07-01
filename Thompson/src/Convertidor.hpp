#ifndef __CONVERTIDOR_HPP__
#define __CONVERTIDOR_HPP__

#include <stdio.h>
#include <stdlib.h>

#include "Expresion.hpp"
#include "Arbol.hpp"
#include "Pila.hpp"


class Convertidor{
	private:
		Expresion exp;
		Arbol *arbolSintactico;
	public:
		void expresionPostFija(char*);
		void construirArbol(void);
		void dibujarArbol(void);
		void construirAutomata(void);
		void dibujarAutomata(void);	
		void marcarEstados(void);	
};

#endif
