#ifndef POLIGONO_H
#define POLIGONO_H 

#include <iostream>
#include <stdlib.h>
using namespace std;

class Poligono
{
private:
	int x, y;
	int radio;
	int vertices;
	int size;
	bool punteada;
public:
	Circulo(int,int,int,int,int,bool);
	Circulo();
	void set_coords(int, int);
	void set_radio(int, int);
	void dibujaPoligono(int);
	int get_x();
	int get_y();
	int get_radio();

};

#endif