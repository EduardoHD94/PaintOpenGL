#include "Linea.h"
#include <iostream>

using namespace std;

Linea::Linea(){}

Linea::Linea(int x1, int x2, int y1, int y2, int size, bool punteada, float r, float g, float b)
{
	this-> x1 = x1;
	this-> x2 = x2;
	this-> y1 = y1;
	this-> y2 = y2;
	this-> size = size;
	this-> punteada = punteada;
	this-> r = r;
	this-> g = g;
	this-> b = b;
}


Linea::~Linea()
{
	cout << "Linea creada en: " << endl;
	cout << "(" << x1 << "," << y1 << ")" << endl;
	cout << "Size: " << size << " Punteada: " << punteada << endl;
	cout << "Linea eliminada" << endl << endl;
}

bool Linea::get_punteada()
{
	return punteada;
}

int Linea::get_size()
{
 return size;
}

float Linea::get_r()
{
	return r;
}
float Linea::get_g()
{
	return g;
}
float Linea::get_b()
{
	return r;
}

void Linea::set_coords(int x1, int x2, int y1, int y2)
{
	this-> x1 = x1;
	this-> x2 = x2;
	this-> y1 = y1;
	this-> y2 = y2;
}

void Linea::set_color(float r, float g, float b)
{
	r = r / 255;
	g = g / 255;
	b = b / 255;
	glColor3f(r, g, b);

}
void Linea::dibujaLinea()
{
	if(punteada)
	{
		set_color(r,g,b);
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
		set_color(r,g,b);
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


