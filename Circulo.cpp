#include "Circulo.h"
#include <iostream>

using namespace std;

Circulo::Circulo(){}

Circulo::Circulo(int x, int y, int radiox, int radioy)
{
	this-> x = x;
	this-> y = y;
	this-> radiox = radiox;
	this-> radioy = radioy;
}

void Circulo::set_coords(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Circulo::set_radio(int radiox, int radioy)
{
	this->radiox = radiox;
	this->radioy = radioy;

}

void Circulo::dibujaCirculo(int size)
{

}

int Circulo::get_x()
{
	return x;
}

int Circulo::get_y()
{
	return y;
}
int Circulo::get_radiox()
{
	return radiox;
}
int Circulo::get_radioy()
{
	return radioy;
}