#ifndef __DATO_HPP__
#define __DATO_HPP__

#include <iostream>

class Dato{
	private:
		char d;
		int posicion;
		int eIni;
		int eFin;
		int estadoInicial[2];
		int estadoFinal[2];
	public:
		Dato();
		char getDato();
		void setDato(char);
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
