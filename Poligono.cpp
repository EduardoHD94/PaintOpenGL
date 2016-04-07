#include "Poligono.h"
#include <iostream>

using namespace std;

Poligono::Poligono(){}

Poligono::Poligono(int x, int radioX, int y, int radioY, int vertices, int size, bool punteada, float r, float g, float b)
{
	this-> x = x;
	this-> y = y;
	this-> radioX = radioX;
	this-> radioY = radioY; 
	this-> vertices = vertices;
	this-> size = size;
	this-> punteada = punteada;
	this-> r = r;
	this-> g = g;
	this-> b = b;
}

int Poligono::get_size()
{
	return size;
}

bool Poligono::get_punteada()
{
	return punteada;
}

int Poligono::get_vertices()
{
	return vertices;
}
float Poligono::get_r()
{
	return r;
}
float Poligono::get_g()
{
	return g;
}
float Poligono::get_b()
{
	return b;
}
void Poligono::set_coords(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Poligono::set_color(float r, float g, float b)
{
	r = r / 255;
	g = g / 255;
	b = b / 255;
	glColor3f(r, g, b);
}
void Poligono::dibujaPoligono()
{
	int rx= x - radioX; 
    int ry = y - radioY;
    rx= pow(rx,2);
    ry = pow (ry,2);
    int radius = sqrt(rx+ry);

	  double PI = 3.14;
      int xa[vertices],ya[vertices];
      double alfa = (2 * PI )/vertices;

      for (int a=0 ; a<vertices ; a++)
      {
           xa[a] = x + (radius * cos((a-1)*alfa));
           ya[a] = y + (radius * sin((a-1)*alfa));

      }

      for(int a=0;a<vertices;a++)
      {
      	if(punteada)
      	{	
	        if(a==vertices-1)
	        {
	        	set_color(r,g,b);
	        	glLineStipple(3,0xeeee);  
				glEnable(GL_LINE_STIPPLE);
	        	glLineWidth(size);
	        	glBegin(GL_LINES);
					glVertex2f(xa[a],ya[a]);
					glVertex2f(xa[0],ya[0]);
				glEnd();
				glDisable(GL_LINE_STIPPLE);
	        }
	        else
	        {
	        	set_color(r,g,b);
	        	glLineStipple(3,0xeeee);  
				glEnable(GL_LINE_STIPPLE);
	        	glLineWidth(size);
	        	glBegin(GL_LINES);
					glVertex2f(xa[a],ya[a]);
					glVertex2f(xa[a+1],ya[a+1]);
				glEnd();
				glDisable(GL_LINE_STIPPLE);
	        }
	    }
	    else
	    {
	    	if(a==vertices-1)
	        {
	        	set_color(r,g,b);
	        	glLineWidth(size);
	        	glBegin(GL_LINES);
					glVertex2f(xa[a],ya[a]);
					glVertex2f(xa[0],ya[0]);
				glEnd();
				
	        }
	        else
	        {
	        	set_color(r,g,b);
	        	glLineWidth(size);
	        	glBegin(GL_LINES);
					glVertex2f(xa[a],ya[a]);
					glVertex2f(xa[a+1],ya[a+1]);
				glEnd();
	        }
	    }
      }
}

int Poligono::get_x()
{
	return x;
}

int Poligono::get_y()
{
	return y;
}
int Poligono::get_radioX()
{
	return radioX;
}

int Poligono::get_radioY()
{
	return radioY;
}

