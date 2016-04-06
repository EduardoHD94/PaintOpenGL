#include "Circulo.h"
#include <iostream>

using namespace std;

Circulo::Circulo(){}

Circulo::Circulo(int x, int y, int r, int size, bool punteada)
{
	this-> x = x;
	this-> y = y;
	this-> r = r;
	this-> size = size;
	this-> punteada = punteada;
}

void Circulo::set_coords(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Circulo::dibujaCirculo()
{
	float d = 1-r;
	float x2 = 0;
	float y2 = r;

	while(y>x)
	{
		plotpixels(x, y, x2, y2);
		if(d<0) d+=2*x+3;
		else
		{
			d+=2*(x-y)+5;
			--y;
		}
		++x;
	}
	plotpixels(x, y, x2, y2);
}

void Circulo::plotpixels(float p, float q, float x3, float y3)
{
	draw_pixel(x3+p, y3+q);
	draw_pixel(-x3+p, y3+q);
	draw_pixel(x3+p, -y3+q);
	draw_pixel(-x3+p, -y3+q);


	draw_pixel(y3+p, x3+q);
	draw_pixel(-y3+p, x3+q);
	draw_pixel(y3+p, -x3+q);
	draw_pixel(-y3+p, -x3+q);
}

void Circulo::draw_pixel(float X, float Y)                           
{
	int wh = 600;
	if(X>wh/10+1 && wh/10<Y && Y<wh-31)
  	{
			glPointSize(size);
			glBegin(GL_POINTS);
				glVertex2f(X, Y);
			glEnd();
	}
}

int Circulo::get_x()
{
	return x;
}

int Circulo::get_y()
{
	return y;
}
int Circulo::get_r()
{
	return r;
}