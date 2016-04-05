#include "Punto.h"
#include <iostream>
#include <GL/glut.h>


using namespace std;

Punto::Punto(){}

Punto::Punto(int x, int y)
{
	this-> x = x;
	this-> y = y;
}

Punto::~Punto()
{
	cout << "Punto eliminado" << endl;
}

void Punto::set_coords(int x, int y)
{
	this-> x = x;
	this-> y = y;

}

void Punto::dibujaPunto()
{
  this-> x = y;
	this-> y = x;

}

int Punto::get_x()
{
	return x;
}

int Punto::get_y()
{
	return y;
}

