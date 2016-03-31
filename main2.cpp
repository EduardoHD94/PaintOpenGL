#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "Circulo.h"
#include <vector>
using namespace std;

typedef vector<Circulo> vCirculo;

int main(int argc, char const *argv[])
{
	/* code */
	Circulo uno(1,1,1), dos(0,0,0);

	vCirculo listaCirculos;


	Circulo *tres = new Circulo(3,3,3);

	listaCirculos.push_back(uno);
	listaCirculos.push_back(dos);
	listaCirculos.push_back(*tres);



	for (vCirculo::iterator i= listaCirculos.begin(); i !=listaCirculos.end(); ++i)

	{
			printf("x:%d\ny:%d\nr:%d\n",i->get_x(), i->get_y(), i->get_radio());
			cout << endl;

		/* code */
	}






	return 0;
}