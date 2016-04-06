#include "Color.h"
#include <iostream> 

using namespace std;

Color::Color(){}

Color::Color(float r, float g, float b)
{
	this-> r = r;
	this-> g = g;
	this-> b = b;
}

Color::Color(float r, float g, float b, float a)
{
	this-> r = r;
	this-> g = g;
	this-> b = b;
	this-> a = a;
}

Color::~Color()
{
	cout << "Color creado en: " << endl;
	cout << "(" << r << "," << g << "," << b << ")" << endl;
    cout << "Color terminado" << endl << endl;
}

void Color::set_color(float r, float g, float b)
{
	this-> r = r;
	this-> g = g;
	this-> b = b;
}

void Color::set_color(float r, float g, float b, float a)
{
	this-> r = r;
	this-> g = g;
	this-> b = b;
	this-> a = a;
}

float Color::get_r()
{
	return r;
}
float Color::get_g()
{
	return g;
}
float Color::get_b()
{
	return b;
}

float Color::get_a()
{
	return a;
}
