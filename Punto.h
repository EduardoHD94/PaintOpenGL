#ifndef PUNTO_H
#define PUNTO_H 

#include <iostream>
#include <stdlib.h>
using namespace std;

class Punto
{
private:
	int x, y;
public:
	Punto(int,int);
	Punto();
	~Punto();
	void set_coords(int, int);
	int get_x();
	int get_y();


};


#endif