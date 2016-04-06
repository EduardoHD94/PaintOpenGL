#include "Circulo.h"
#include <iostream>

using namespace std;

Circulo::Circulo(){}

Circulo::Circulo(int p, int q, int r, int size)
{
	this-> p = p;
	this-> q = q;
	this-> r = r;
	this-> size = size;
}

void Circulo::set_coords(int x, int y)
{
	this->p = x;
	this->q = y;
}

void Circulo::dibujaCirculo()
{
	float d = 1-r;
	float x = 0;
	float y = r;

	while(y>x)
	{
		plotpixels(p, q, x, y);
		if(d<0) d+=2*x+3;
		else
		{
			d+=2*(x-y)+5;
			--y;
		}
		++x;
	}
	plotpixels(p, q, x, y);
}

void Circulo::plotpixels(float p, float q, float x, float y)
{
	draw_pixel(x+p, y+q);
	draw_pixel(-x+p, y+q);
	draw_pixel(x+p, -y+q);
	draw_pixel(-x+p, -y+q);


	draw_pixel(y+p, x+q);
	draw_pixel(-y+p, x+q);
	draw_pixel(y+p, -x+q);
	draw_pixel(-y+p, -x+q);
}

void Circulo::draw_pixel(float x, float y)                           
{
	int wh = 600;
	if(x>wh/10+1 && wh/10<y && y<wh-31)
  	{
			glPointSize(size);
			glBegin(GL_POINTS);
				glVertex2f(x, y);
			glEnd();
	}
}

int Circulo::get_p()
{
	return p;
}

int Circulo::get_q()
{
	return q;
}
int Circulo::get_r()
{
	return r;
}