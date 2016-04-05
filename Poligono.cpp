#include "Poligono.h"
#include <iostream>

using namespace std;

Poligono::Poligono(){}

Poligono::Poligono(int x, int y, int radio, int vertices, int size, bool punteada)
{
	this-> x = x;
	this-> y = y;
	this-> radio = radio;
	this-> vertices = vertices;
	this-> size = size;
	this-> punteada = punteada;
}

void Poligono::set_coords(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Poligono::set_radio(int radio)
{
	this->radio = radio;

}

void Poligono::dibujaPoligono()
{
	cout << "Poligono " << endl;
}

int Poligono::get_x()
{
	return x;
}

int Poligono::get_y()
{
	return y;
}
int Poligono::get_radio()
{
	return radio;
}
