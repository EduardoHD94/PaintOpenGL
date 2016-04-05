#include "Linea.h"
#include <iostream>

using namespace std;

Linea::Linea(){}

Linea::Linea(int x1, int x2, int y1, int y2, bool punteada)
{
	this-> x1 = x1;
	this-> x2 = x2;
	this-> y1 = y1;
	this-> y2 = y2;
	this-> punteada = punteada;
}

Linea::~Linea()
{
	cout << "Linea creada en: " << endl;
	cout << "(" << x1 << "," << y1 << ")" << endl;
	cout << "Linea eliminada" << endl << endl;
}

void Linea::set_coords(int x1, int x2, int y1, int y2)
{
	this-> x1 = x1;
	this-> x2 = x2;
	this-> y1 = y1;
	this-> y2 = y2;
}

void Linea::dibujaLinea(int size)
{
	if(punteada)
	{
		glLineStipple(3,0xeeee);  
		glEnable(GL_LINE_STIPPLE);
		glLineWidth(size);
		glBegin(GL_LINE_STRIP);
			glVertex2f(x2, y2);
			glVertex2f(x1, y1);
		glEnd();
		glDisable(GL_LINE_STIPPLE);

	}
	else
	{
		glLineWidth(size);
		glBegin(GL_LINES);
			glVertex2f(x2, y2);
			glVertex2f(x1, y1);
		glEnd();
	}
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


