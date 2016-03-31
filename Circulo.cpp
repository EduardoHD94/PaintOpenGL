#include "Circulo.h"
#include <iostream>

using namespace std;

Circulo::Circulo(){}

Circulo::Circulo(int x, int y, int radio)
{
	this-> x = x;
	this-> y = y;
	this-> radio = radio;
}

void Circulo::set_coords(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Circulo::set_radio(int radio)
{
	this->radio = radio;

}


int Circulo::get_x()
{
	return x;
}

int Circulo::get_y()
{
	return y;
}
int Circulo::get_radio()
{
	return radio;
}