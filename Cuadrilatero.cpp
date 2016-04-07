#include "Cuadrilatero.h"
#include <iostream>
using namespace std;

Cuadrilatero::Cuadrilatero(){}

Cuadrilatero::Cuadrilatero(int x1, int x2, int y1, int y2, int size, bool punteada, float r, float g, float b)
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

Cuadrilatero::~Cuadrilatero()
{
	cout << "Cuadrilatero creado en: " << endl;
	cout << "(" << x1 << "," << y1 << ")\n(" << x2 << "," << y2 << ")" << endl;
	cout << "Size: " << size << endl;
	cout << "punteada" << punteada << endl;
	cout << "RGB " << r << " " << g << " " <<b<<endl;
    cout << "Cuadrilatero eliminado" << endl << endl;
}

int Cuadrilatero::get_size(){return size;}

bool Cuadrilatero::get_punteada(){return punteada;}

float Cuadrilatero::get_r()
{
	return r;
}
float Cuadrilatero::get_g()
{
	return g;
}
float Cuadrilatero::get_b()
{
	return b;
}

void Cuadrilatero::set_color(float r, float g, float b)
{
	r = r / 255;
	g = g / 255;
	b = b / 255;
	glColor3f(r, g, b);
};


void Cuadrilatero::set_coords(int x1, int x2, int y1, int y2, int size)
{
	this-> x1 = x1;
	this-> x2 = x2;
	this-> y1 = y1;
	this-> y2 = y2;
	this-> size = size;
}

void Cuadrilatero::dibujaCuadrilatero()
{

	if(punteada)
	{
		set_color(r,g,b);
		glLineStipple(3,0xeeee);  
		glEnable(GL_LINE_STIPPLE);
		glLineWidth(size);
		glBegin(GL_LINE_LOOP);
			glVertex2f(x2, y2);
			glVertex2f(x1, y2);
			glVertex2f(x1, y1);
			glVertex2f(x2, y1);
		glEnd();
		glDisable(GL_LINE_STIPPLE);
	}
	else
	{
		set_color(r,g,b);
		glLineWidth(size);
		glBegin(GL_LINE_LOOP);
			glVertex2f(x2, y2);
			glVertex2f(x1, y2);
			glVertex2f(x1, y1);
			glVertex2f(x2, y1);
		glEnd();
	}
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
