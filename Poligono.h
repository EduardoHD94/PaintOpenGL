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
	int x, y;
	int radioX, radioY; 
	int vertices;
	int size;
	bool punteada;
public:
	Poligono(int,int,int,int,int, int, bool);
	Poligono();
	void set_coords(int, int);
	//void set_radio(int, int);
	void dibujaPoligono();
	int get_x();
	int get_y();
	int get_radioX();
	int get_radioY();
};

#endif