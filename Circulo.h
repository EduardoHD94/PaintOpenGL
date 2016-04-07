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
	float rr,g,b;
public:
	Circulo(int,int,int,int,float,float,float);
	Circulo();
	void set_coords(int, int);
	void set_color(float,float,float);
	void dibujaCirculo();
	void plotpixels(float, float, float, float);
	void draw_pixel(float, float);
	int get_p();
	int get_q();
	int get_radio();
	int get_size();
	float get_r();
	float get_g();
	float get_b();

};

#endif