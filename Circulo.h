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
	int p; 
	int q;
	int r;
	int size;
public:
	Circulo(int,int,int,int);
	Circulo();
	void set_coords(int, int);
	void dibujaCirculo();
	void plotpixels(float, float, float, float);
	void draw_pixel(float, float);
	int get_p();
	int get_q();
	int get_r();
};

#endif