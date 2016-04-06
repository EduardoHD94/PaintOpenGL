
#ifndef COLOR_H
#define COLOR_H 

#include <iostream>
#include <stdlib.h>
#include <GL/glut.h>

using namespace std;

class Color
{
private:
	float r, g, b,a;
	bool punteada;
public:
	Color(float, float, float);
	Color(float, float, float, float);
	Color();
	~Color();
	void set_color(float, float,float);
	void set_color(float, float,float,float);
	float get_r();
	float get_g();
	float get_b();
	float get_a();


};

#endif