#include "Circulo.h"
#include <iostream>

using namespace std;

Circulo::Circulo(){}

Circulo::Circulo(int p, int q, int r, int size, float rr, float g, float b)
{
	this-> p = p;
	this-> q = q;
	this-> r = r;
	this-> size = size;
	this-> rr = rr;
	this-> g = g;
	this-> b = b;
}

/*Obtener la variable r de RGB*/
float Circulo::get_r()
{
	return rr;
}

float Circulo::get_g()
{
	return g;
}

float Circulo::get_b()
{
	return b;
}

void Circulo::set_color(float rr, float g, float b)
{
	rr = rr / 255;
	g = g / 255;
	b = b / 255;
	glColor3f(rr, g, b);
};


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
  			set_color(rr,g,b);
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
int Circulo::get_radio()
{
	return r;
}

int Circulo::get_size(){ return size;}