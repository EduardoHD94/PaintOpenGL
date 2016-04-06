#ifndef CIRCULO_H
#define CIRCULO_H 

#include <iostream>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

using namespace std;

class Circulo
{
private:
	int x; 
	int y;
	int r;
	int size;
	bool punteada;
public:
	Circulo(int,int,int,int, bool);
	Circulo();
	void set_coords(int, int);
	void dibujaCirculo();
	void plotpixels(float, float, float, float);
	void draw_pixel(float, float);
	int get_x();
	int get_y();
	int get_r();
};

#endif