#include "includes.h"

int main(int argc, char **argv)
{	 
	glutInit(&argc,argv);
    glutInitDisplayMode (GLUT_SINGLE| GLUT_RGB);
	glutInitWindowSize(render->ww,render->wh);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Editor de Graficos");	
	glutReshapeFunc(myReshape);
	glutDisplayFunc(display);
	glutMouseFunc(myMouse);
	render->loop();
    return 0;
}