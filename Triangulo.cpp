#include "Triangulo.h"
#include <iostream> 

using namespace std;

Triangulo::Triangulo(){}

Triangulo::Triangulo(int x1, int x2, int x3, int y1, int y2, int y3)
{
	this-> x1 = x1;
	this-> x2 = x2;
	this-> x3 = x3;
	this-> y1 = y1;
	this-> y2 = y2;
	this-> y3 = y3;
}

Triangulo::~Triangulo()
{
	cout << "Triangulo creado en: " << endl;
	cout << "(" << x1 << "," << y1 << ")\n(" << x2 << "," << y2 << ")\n(" << x3 << "," << y3 << ")" << endl;
    cout << "Triangulo eliminado" << endl;
}

void Triangulo::set_coords(int x1, int x2, int x3, int y1, int y2, int y3)
{
	this-> x1 = x1;
	this-> x2 = x2;
	this-> x3 = x3;
	this-> y1 = y1;
	this-> y2 = y2;
	this-> y3 = y3;
}

void Triangulo::dibujaTriangulo(int size)
{
	glLineWidth(size);
	glBegin(GL_LINE_LOOP);
		glVertex2f(x3, y3);
		glVertex2f(x2, y2);
		glVertex2f(x1, y1);
	glEnd();
}


int Triangulo::get_x1()
{
	return x1;
}
int Triangulo::get_x2()
{
	return x2;
}
int Triangulo::get_x3()
{
	return x3;
}

int Triangulo::get_y1()
{
	return y1;
}

int Triangulo::get_y2()
{
	return y2;
}

int Triangulo::get_y3()
{
	return y3;
}