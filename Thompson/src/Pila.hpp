#ifndef __PILA_HPP__
#define __PILA_HPP__

#include <iostream>

#include "Nodo.hpp"

class Pila{
	private:
		Nodo *ultimo;
	public:
		Pila();
		void push(char);
		void pop();
		char top();
		bool esVacia();
};

#endif