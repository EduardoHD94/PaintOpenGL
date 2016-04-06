
#ifndef CUADRILATERO_H
#define CUADRILATERO_H 

#include <iostream>
#include <stdlib.h>
#include <GL/glut.h>

using namespace std;

class Cuadrilatero
{
private:
	int x1,x2;
	int y1,y2;
	int size;
	bool punteada;
public:
	Cuadrilatero(int, int, int, int, int,bool);
	Cuadrilatero();
	~Cuadrilatero();
	void set_coords(int, int, int, int, int);
	void dibujaCuadrilatero();
	int get_x1();
	int get_x2();
	int get_y1();
	int get_y2();

};

#endif