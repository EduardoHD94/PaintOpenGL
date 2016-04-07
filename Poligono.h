#ifndef POLIGONO_H
#define POLIGONO_H 

#include <iostream>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
using namespace std;

class Poligono
{
private:
	bool punteada;
	float r,g,b;
	int radioX, radioY; 
	int size;
	int vertices;
	int x, y;
public:

	//void set_radio(int, int);
	int get_radioX();
	int get_radioY();
	int get_x();
	int get_y();
	int get_size();

	bool get_punteada();
	
	float get_r();
	float get_g();
	float get_b();
	int get_vertices();

	Poligono();
	Poligono(int,int,int,int,int, int, bool, float,float,float);
	void dibujaPoligono();
	void set_color(float, float, float);
	void set_coords(int, int);
};

#endif