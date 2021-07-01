#ifndef __ARBOL_HPP__
#define __ARBOL_HPP__

#include <stdio.h>

#include "Dato.hpp"

static int countInordenPosicion=1;
static int countAutomata=1;

class Arbol{
	private:
		Dato d;
		Arbol *hojaIzquierda;
		Arbol *hojaDerecha;
	public:
		Arbol();

		bool insertar(Arbol**,char);
		void inorden(Arbol*);

		void setLabelDOT(Arbol*,FILE*);
		void postordenConstruir(Arbol*,FILE*);
		void construirAutomata(Arbol*);
		void setLabelAFNDOT(Arbol*,FILE*);
		void dibujarAutomata(Arbol*,FILE*);
		
		void setDato(char);

		char getDato(void);

		void setPosicion(int);
		int getPosicion();
		void setIni(int);
		int  getIni(void);
		void setFin(int);
		int  getFin(void);
		void setEstadoInicial(int,int);
		void setEstadoFinal(int,int);
		int getEstadoInicial(int);
		int getEstadoFinal(int);
};

#endif
