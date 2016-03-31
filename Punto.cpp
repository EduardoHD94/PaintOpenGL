#include "Punto.h"
#include <iostream>

using namespace std;

Punto::Punto(){}

Punto::Punto(int x, int y)
{
	this-> x = x;
	this-> y = y;
}

void Punto::set_coords(int x, int y)
{
	this-> x = x;
	this-> y = y;

}

int Punto::get_x()
{
	return x;
}

int Punto::get_y()
{
	return y;
}

