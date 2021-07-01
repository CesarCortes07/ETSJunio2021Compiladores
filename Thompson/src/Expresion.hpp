#ifndef __EXPRESION_HPP__
#define __EXPRESION_HPP__

#include <string>

class Expresion{
	private:		
		std::string exp;
	public:
		bool estaVacia();	
		int tamExp();
		char extraer(int);
		void concatenar(char);
		void concatenar(char*);
		void concatenar(std::string,Expresion,std::string);
};

#endif
