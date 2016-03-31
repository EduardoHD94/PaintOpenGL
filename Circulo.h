#ifndef CIRCULO_H
#define CIRCULO_H 

#include <iostream>
#include <stdlib.h>
using namespace std;

class Circulo
{
private:
	int x;
	int y;
	int radio;
public:
	Circulo(int,int,int);
	Circulo();
	void set_coords(int, int);
	void set_radio(int);
	int get_x();
	int get_y();
	int get_radio();

};

#endif