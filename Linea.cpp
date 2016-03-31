#include "Linea.h"
#include <iostream>

using namespace std;

Linea::Linea(){}

Linea::Linea(int x1, int x2, int y1, int y2)
{
	this-> x1 = x1;
	this-> x2 = x2;
	this-> y1 = y1;
	this-> y2 = y2;
}

void Linea::set_coords(int x1, int x2, int y1, int y2)
{
	this-> x1 = x1;
	this-> x2 = x2;
	this-> y1 = y1;
	this-> y2 = y2;
}

int Linea::get_x1()
{
	return x1;
}

int Linea::get_x2()
{
	return x2;
}

int Linea::get_y1()
{
	return y1;
}

int Linea::get_y2()
{
	return y2;
}


