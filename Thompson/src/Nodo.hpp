#ifndef __NODO_HPP__
#define __NODO_HPP__

class Nodo {
	private:
		char valor;
		Nodo *siguiente;
	public:
		Nodo(char,Nodo*);
		Nodo* getSiguiente();
		char getValor();
};
 
#endif
