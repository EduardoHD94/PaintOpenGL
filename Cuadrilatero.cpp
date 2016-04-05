#include "Cuadrilatero.h"
#include <iostream>
using namespace std;

Cuadrilatero::Cuadrilatero(){}

Cuadrilatero::Cuadrilatero(int x1, int x2, int y1, int y2)
{
	this-> x1 = x1;
	this-> x2 = x2;
	this-> y1 = y1;
	this-> y2 = y2;
}

Cuadrilatero::~Cuadrilatero()
{

    cout << "Cuadrilatero eliminado" << endl;
}

void Cuadrilatero::set_coords(int x1, int x2, int y1, int y2)
{
	this-> x1 = x1;
	this-> x2 = x2;
	this-> y1 = y1;
	this-> y2 = y2;
}

void Cuadrilatero::dibujaCuadrilatero(int size)
{
	glLineWidth(size);
	glBegin(GL_LINE_LOOP);
		glVertex2f(x2, y2);
		glVertex2f(x1, y2);
		glVertex2f(x1, y1);
		glVertex2f(x2, y1);
	glEnd();
}

int Cuadrilatero::get_x1()
{
	return x1;
}

int Cuadrilatero::get_x2()
{
	return x2;
}

int Cuadrilatero::get_y1()
{
	return y1;
}

int Cuadrilatero::get_y2()
{
	return y2;
}
