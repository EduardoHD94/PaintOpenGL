#include "includes.h"

int main(int argc, char **argv)
{	 
	glutInit(&argc,argv);							
    glutInitDisplayMode (GLUT_SINGLE| GLUT_RGB);	// Activar modo Display de OpenGl
	glutInitWindowSize(render->ww,render->wh);		// establecer el tamanio de la ventana
	glutInitWindowPosition(100, 100);				// establecer la posicion donde se dibujara la pantalla
	glutCreateWindow("Editor de Graficos");			// Titulo del Paint (Ventana)
	glutReshapeFunc(myReshape);						// Cambia tamano de la ventana
	glutDisplayFunc(display);						// despliega la ventana del Paint
	glutMouseFunc(mouse);							// llama la funcion mouse para registrar cada actividad del mouse
	render->loop();
    return 0;
}