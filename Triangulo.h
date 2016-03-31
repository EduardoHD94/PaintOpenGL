#include <iostream>
#include <stdlib.h>
using namespace std;

class Triangulo
{
private:
	int x1, x2, x3;
	int y1, y2, y3;
public:
	Triangulo(int,int,int,int,int,int);
	Triangulo();
	~Triangulo();
	void set_coords(int, int, int, int, int, int);
	int get_x1();
	int get_x2();
	int get_x3();
	int get_y1();
	int get_y2();
	int get_y3();
};