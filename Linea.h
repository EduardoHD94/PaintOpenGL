#ifndef LINEA_H
#define LINEA_H

#include <iostream>
#include <stdlib.h>
#include <GL/glut.h>

using namespace std;

class Linea
{
private:
	int x1;
	int y1;
	int x2;
	int y2;
	bool punteada;
public:
	Linea(int,int,int,int,bool);
	Linea();
	~Linea();
	void set_coords(int, int, int, int);
	void dibujaLinea(int);
	int get_x1();
	int get_x2();
	int get_y1();
	int get_y2();

};

#endif