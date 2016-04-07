#ifndef LINEA_H
#define LINEA_H

#include <iostream>
#include <stdlib.h>
#include <GL/glut.h>

using namespace std;

class Linea
{
private:
	int x1, x2;
	int y1, y2;
	int size;
	bool punteada;
	float r,g,b;
public:
	Linea(int,int,int,int,int,bool,float,float,float);
	Linea();
	~Linea();
	void set_coords(int, int, int, int);
	void dibujaLinea();
	void set_color(float,float,float);
	int get_x1();
	int get_x2();
	int get_y1();
	int get_y2();
	int get_size();
	float get_r();
	float get_g();
	float get_b();
	bool get_punteada();

};

#endif