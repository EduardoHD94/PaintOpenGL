#ifndef INCLUDES_H
#define INCLUDES_H

#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include "Render.h"
#include "Circulo.h"
#include "Cuadrilatero.h"
#include "Linea.h"
#include "Punto.h"
#include "Triangulo.h"
#include "Color.h"
#include "Poligono.h"
#include <vector>

 
#define ESPACIADO 0xeeee
using namespace std;

//GLsizei wh = 600, ww = 800,wx,wy, wx1=800, wy1=600;/*display window render->size*/

Render *render = new Render();

//Triangulo *uno = new Triangulo(100, 100, 130,  130, 160, 160);
//Triangulo *dos = new Triangulo(200, 200, 230,  230, 260, 260);


int draw;  /* to store draw option*/
int m, n;
int pol;
int i, j, k;

float textx,texty, textz=0.0;

int save=0;
int contador = 0;

char* image;
bool punteada = false;

int count=0;
int sub_menu;
float posx, posy;
void *currentfont;
FILE *fptr;
char fname[20];
int s=0;
int wel=2;

/*Vectores*/
vector<Triangulo> v_Triangulos;
vector<Cuadrilatero> v_Cuadrilateros;
vector<Circulo> v_Circulos;
vector<Linea> v_Lineas;
vector<Punto> v_Puntos;
vector<Poligono> v_Poligonos;
/*FinVectores*/

void eraser(int x, int y)  /* ERASER function */
{
	y=render->wh-y;

	render->set_color(255, 255, 255);

	if(x>render->wh/10+1 && render->wh/10<y && y<render->wh-31)
	{
			glBegin(GL_POLYGON);
	 			glVertex2f(x, y);
				glVertex2f(x+5, y);
	 			glVertex2f(x+5, y+5);
	    	glVertex2f(x, y+5);
			glEnd();
		glFlush();
	}
}

/* PAINT BRUSH function */
void paint(int x, int y) 
{
	y=render->wh-y;
	if(x>render->wh/10+1 && render->wh/10<y && y<render->wh-31)
	{
			glBegin(GL_POLYGON);
	 			glVertex2f(x, y);
				glVertex2f(x+4+render->size, y);
	 			glVertex2f(x+4+render->size, y+4+render->size);
	    	glVertex2f(x, y+4+render->size);
			glEnd();
		glFlush();
	}
}

/* to draw point */
void drawpoint(int x, int y)       
{
	y=render->wh-y;

	if(x>render->wh/10+1 && render->wh/10<y && y<render->wh-31)
	{
		glPointSize(render->size);
		glBegin(GL_POINTS);
			glVertex2f(x, y);
			glEnd();
		glFlush();
	}
}

/* RESHAPE FUNCTION */
void myReshape(GLsizei w, GLsizei h) 
{
    glMatrixMode(GL_PROJECTION);
   	glLoadIdentity();
   	glOrtho(0.0, (GLdouble)w, 0.0, (GLdouble)h, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glViewport(0,0,w,h);
   	glFlush();
	render->set_ww(w);
   	render->set_wh(h);
	glutPostRedisplay();
}


void guardaImagen (char filename[160], int x, int y)
{
	long imageSize = x * y * 3;
	unsigned char *data = new unsigned char[imageSize];
	glReadPixels(0,0,x,y, GL_BGR,GL_UNSIGNED_BYTE,data);// split x and y sizes into bytes
	int xa= x % 256;
	int xb= (x-xa)/256;int ya= y % 256;
	int yb= (y-ya)/256;//assemble the header
	unsigned char header[18]={0,0,2,0,0,0,0,0,0,0,0,0,(char)xa,(char)xb,(char)ya,(char)yb,24,0};

	fstream File(filename, ios::out | ios::binary);
	File.write (reinterpret_cast<char *>(header), sizeof (char)*18);
	File.write (reinterpret_cast<char *>(data), sizeof (char)*imageSize);
	File.close();

	delete[] data;
	data=NULL;
}


void display()
{

	system("clear");
	render->set_color_background(render->r,render->g,render->b,255);
	render->draw_toolbar();
	render->draw_palette();
	render->draw_toolbox();
	render->draw_btn_line();
	render->draw_btn_triangle();
	render->draw_btn_rectangle();
	render->draw_btn_pencil();
	render->draw_btn_eraser();
	render->draw_btn_pencil2();
	render->draw_btn_circle();		 
    render->draw_btn_air_brush();
	render->draw_btn_fill_color();
	render->draw_btn_brush();
	render->draw_btn_increment();
	render->draw_btn_decrement();
	render->draw_btn_solid_line();
	render->draw_btn_dotted_line();
	render->draw_btn_vertex_increment();
	render->draw_btn_vertex_decrement();
	render->draw_btn_show_size();
	render->draw_btn_show_vertex();
	render->draw_btn_poligono();
	render->draw_size();
	render->draw_vertex();
	render->set_font(GLUT_BITMAP_HELVETICA_12);
	//render->drawstring(6*render->wh/60, 58*render->wh/60, 0.0, "Abrir",0,0,0);
	render->drawstring(12*render->wh/60, 58*render->wh/60, 0.0, "Guardar",0,0,0);
	render->drawstring(18*render->wh/60, 58*render->wh/60, 0.0, "Borrar",0,0,0);

	for(unsigned int i = 0; i < v_Triangulos.size(); i++){
        v_Triangulos.at(i).dibujaTriangulo();
    }

    for(unsigned int i = 0; i < v_Cuadrilateros.size(); i++){
        v_Cuadrilateros.at(i).dibujaCuadrilatero();
    }

    for(unsigned int i = 0; i < v_Lineas.size(); i++){
        v_Lineas.at(i).dibujaLinea();
    }

	 for(unsigned int i = 0; i < v_Puntos.size(); i++){
        v_Puntos.at(i).dibujaPunto(4);
    }

	 for(unsigned int i = 0; i < v_Poligonos.size(); i++){
        v_Poligonos.at(i).dibujaPoligono();
    }
	 for(unsigned int i = 0; i < v_Circulos.size(); i++){
        v_Circulos.at(i).dibujaCirculo();
    }

	glFlush();
}

void mouse(int btn, int state, int x, int y)
{
	GLfloat r, r1, r2;
	int num1=0, num2=0;

	int i1, i2;
	int flag2;

	flag2=0;


	if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
	{

		if(6*render->wh/60<x && x<8*render->wh/60 && render->wh/60<render->wh-y && render->wh-y<render->wh/20)
		{	
			render->set_color(0, 0, 0);
			render->r = 0;
			render->b = 0;
			render->g = 0;
		}

		else if(6*render->wh/60<x && x<8*render->wh/60 && render->wh/20<render->wh-y && render->wh-y<render->wh/12)
		{
			render->set_color(255, 255, 255);
			render->r = 255;
			render->g = 255;
			render->b = 255;
		}

		else if(8*render->wh/60<x && x<10*render->wh/60 && render->wh/60<render->wh-y && render->wh-y<render->wh/20)
		{
	         render->set_color(239, 223, 132);
	         render-> r = 239;
	         render-> g = 223;
	         render-> b = 132;
		}

		else if(8*render->wh/60<x && x<10*render->wh/60 && render->wh/20<render->wh-y && render->wh-y<render->wh/12)
		{
		     render->set_color(232, 99, 113);
		     render-> r = 232;
		     render-> g = 99;
		     render-> b = 113;
		}

		else if(10*render->wh/60<x && x<12*render->wh/60 && render->wh/60<render->wh-y && render->wh-y<render->wh/20)
		{
		     render->set_color(80, 186, 188);
		     render-> r = 80;
		     render-> g = 186;
		     render-> b = 188;
		}

		else if(10*render->wh/60<x && x<12*render->wh/60 && render->wh/20<render->wh-y && render->wh-y<render->wh/12)
		{
		     render->set_color(161, 185, 196);
		     render-> r = 161;
		     render-> g = 185;
		     render-> b = 196;
		}

		else if(12*render->wh/60<x && x<14*render->wh/60 && render->wh/60<render->wh-y && render->wh-y<render->wh/20)
		{
			 render->set_color(241, 144, 86);
			 render-> r = 241;
			 render-> g = 144;
			 render-> b = 86;
		}

		else if(12*render->wh/60<x && x<14*render->wh/60 && render->wh/20<render->wh-y && render->wh-y<render->wh/12)
		{
		     render->set_color(180, 231, 254);
			 render-> r = 180;
			 render-> g = 231;
			 render-> b = 254;
		}

		else if(14*render->wh/60<x && x<16*render->wh/60 && render->wh/60<render->wh-y && render->wh-y<render->wh/20)
		{
			 render->set_color(203, 143, 244);
			render-> r = 203;
			 render-> g = 143;
			 render-> b = 244;
		}

		else if(14*render->wh/60<x && x<16*render->wh/60 && render->wh/20<render->wh-y && render->wh-y<render->wh/12)
		{
			 render->set_color(51, 255, 90);
			render-> r = 51;
			 render-> g = 255;
			 render-> b = 90;
		}

		else if(16*render->wh/60<x && x<18*render->wh/60 && render->wh/60<render->wh-y && render->wh-y<render->wh/20)
		{
			 render->set_color(254, 139, 180);
			render-> r = 254;
			 render-> g = 139;
			 render-> b = 180;
		}

		else if(16*render->wh/60<x && x<18*render->wh/60 && render->wh/20<render->wh-y && render->wh-y<render->wh/12)
		{
			 render->set_color(248, 214, 36);
			 render-> r = 248;
			 render-> g = 214;
			 render-> b = 36;
		}

		else if(18*render->wh/60<x && x<20*render->wh/60 && render->wh/60<render->wh-y && render->wh-y<render->wh/20)
		{
			 render->set_color(248, 85, 94);
			 render-> r = 248;
			 render-> g = 85;
			 render-> b = 94;
		}

		else if(18*render->wh/60<x && x<20*render->wh/60 && render->wh/20<render->wh-y && render->wh-y<render->wh/12)
		{
			render->set_color(76, 106, 141);
			render-> r = 76;
			 render-> g = 106;
			 render-> b = 141;
		}

		else if(20*render->wh/60<x && x<22*render->wh/60 && render->wh/60<render->wh-y && render->wh-y<render->wh/20)
		{
			 render->set_color(188, 217, 85);
			 render-> r = 188;
			 render-> g = 217;
			 render-> b = 85;
		}

		else if(20*render->wh/60<x && x<22*render->wh/60 && render->wh/20<render->wh-y && render->wh-y<render->wh/12)
		{
			 render->set_color(248, 214, 139);
			 render->r = 248;
			 render->g = 214;
			 render->b = 139;
		}

		else if(22*render->wh/60<x && x<24*render->wh/60 && render->wh/60<render->wh-y && render->wh-y<render->wh/20)
		{
			 render->set_color(255, 171, 69);
			 render->r = 255;
			 render->g = 171;
			 render->b = 69;
		}

		else if(22*render->wh/60<x && x<24*render->wh/60 && render->wh/20<render->wh-y && render->wh-y<render->wh/12)
		{
			 render->set_color(152, 102, 41);
			 render->r = 152;
			 render->g = 102;
			 render->b = 41;
		}


		/*end select color */

		/* to select render->whAT TO  DRAW */

		/* selected option is PENCIL*/
		if(2<x && x<render->wh/20 && 18*render->wh/20<render->wh-y && render->wh-y<render->wh-(render->wh/20)-1)                   
			draw=1;

		/* selected option is LINE */
		else if(render->wh/20<x && x<render->wh/10-2 && 18*render->wh/20<render->wh-y && render->wh-y<render->wh-(render->wh/20)-1)       
		{
			render->reset();
			draw=2;
		}

		/* selected option is TRIANGLE */
		else if(2<x && x<render->wh/20 && 17*render->wh/20<render->wh-y && render->wh-y<18*render->wh/20)                    
		{
			render->reset();
			draw=3;
		}

		/* selected option is RECTANGLE */
		else if(render->wh/20<x && x<render->wh/10-2 && 17*render->wh/20<render->wh-y && render->wh-y<18*render->wh/20)               
		{
			render->reset();
			draw=4;
		}

		/* selected option is POLYGON */
		else if(2<x && x<render->wh/20 && 16*render->wh/20<render->wh-y && render->wh-y<17*render->wh/20)                   
		{
			render->reset();
			draw=5;
		}

		/* selected option is CIRCLE */
		else if(render->wh/20<x && x<render->wh/10-2 && 16*render->wh/20<render->wh-y && render->wh-y<17*render->wh/20)           
		{
			render->reset();
			draw=6;
		}

		/* selected option is AIRBRUSH */
		else if(2<x && x<render->wh/20 && 15*render->wh/20<render->wh-y && render->wh-y<16*render->wh/20)                 
		{
			render->reset();
			draw=7;
		}

		 /* selected option is ERASER */
		else if(render->wh/20<x && x<render->wh/10-2 && 15*render->wh/20<render->wh-y && render->wh-y<16*render->wh/20)               
		{
			render->reset();
			draw=8;
		}

		  /* selected option is COLOR FILL */
		else if(2<x && x<render->wh/20 && 14*render->wh/20<render->wh-y && render->wh-y<15*render->wh/20)                    
		{

			render->reset();
			draw=9;
		}

		/* selected option is PAINT BRUSH */
		else if(render->wh/20<x && x<render->wh/10-2 && 14*render->wh/20<render->wh-y && render->wh-y<15*render->wh/20)            
		{
			render->reset();
			draw=10;
		}

		/*Incrementar tamaño*/
		else if(2<x && x<render->wh/20 && 13*render->wh/20<render->wh-y && render->wh-y<14*render->wh/20)                    
		{
			render->reset();
			render->increment_size();
			display();
		}

		/*Decremantar tamaño*/
		else if(render->wh/20<x && x<render->wh/10-2 && 13*render->wh/20<render->wh-y && render->wh-y<14*render->wh/20)            
		{
			render->reset();
			render->decrement_size();
			display();
		}
		/*Seleccionar linea continua*/
		else if(2<x && x<render->wh/20 && 12*render->wh/20<render->wh-y && render->wh-y<13*render->wh/20)                    
		{
			render->reset();
			render->lineaPunteada(false);
		}

		/*Seleccionar linea punteada*/
		else if(render->wh/20<x && x<render->wh/10-2 && 12*render->wh/20<render->wh-y && render->wh-y<13*render->wh/20)            
		{
			render->reset();
			render->lineaPunteada(true);
		}

				/*Seleccionar linea continua*/
		else if(2<x && x<render->wh/20 && 11*render->wh/20<render->wh-y && render->wh-y<12*render->wh/20)                    
		{
			render->reset();
			render->increment_vertex();
			display();
		}

		/*Seleccionar linea punteada*/
		else if(render->wh/20<x && x<render->wh/10-2 && 11*render->wh/20<render->wh-y && render->wh-y<12*render->wh/20)            
		{
			render->reset();
			render->decrement_vertex();
			display();
		}

		/*Seleccionar Poligono lados*/
		else if(2<x && x<render->wh/20 && 8*render->wh/20<render->wh-y && render->wh-y<9*render->wh/20)                    
		{
			render->reset();
			draw = 11;
		}

		/*Seleccionar Poligono lados*/
		else if(render->wh/20<x && x<render->wh/10-2 && 8*render->wh/20<render->wh-y && render->wh-y<9*render->wh/20)            
		{
			render->reset();
			draw = 11;
		}

		/*Seleccionar color background*/
		else if(2<x && x<render->wh/20 && 7*render->wh/20<render->wh-y && render->wh-y<8*render->wh/20)                    
		{
			render->reset();
			display();
			
		}

		/*Seleccionar color background*/
		else if(render->wh/20<x && x<render->wh/10-2 && 7*render->wh/20<render->wh-y && render->wh-y<8*render->wh/20)            
		{
			render->reset();
			display();
		}

		 if(draw==1)         /* to draw using a  PENCIL  */
		{
			if(x>render->wh/10+1 && render->wh/10<render->wh-y && render->wh-y<render->wh-31)
				glutMotionFunc(drawpoint);

		}

		 else if(draw==2)  /* to draw a LINE */
		{

			if(x>render->wh/10+1 && render->wh/10<render->wh-y && render->wh-y<render->wh-31)
			{
				render->drawpoint(x, y);
				render->a2=render->a1;
				render->b2=render->b1;
				render->a1=x;
				render->b1=render->wh-y;       

				if(render->a1>render->wh/10+1 && render->wh/10<render->b1 && render->b1<render->wh-31)
				{
					if(render->a2>render->wh/10+1 && render->wh/10<render->b2 && render->b2<render->wh-31)
					{
						if(punteada)
						{
							Linea linea(render->a1,render->a2,render->b1,render->b2,render->size,render->punteada);
							v_Lineas.push_back(linea);
							render->reset();
							display();
							//render->draw_lines(render->a1,render->a2,punteada);
						}
						else
						{
							Linea linea(render->a1,render->a2,render->b1,render->b2,render->size,render->punteada);
							v_Lineas.push_back(linea);
							render->reset();
							display();
							//render->draw_lines(render->a1,render->a2,punteada);
						}
					}
				}
			}

		}


		else if(draw==3)  /* to draw a TRIANGLE */
		{
			if(x>render->wh/10+1 && render->wh/10<render->wh-y && render->wh-y<render->wh-31)
			{
				render->drawpoint(x, y);
				render->a3 = render->a2;
				render->b3 = render->b2;
				render->a2 = render->a1;
				render->b2 = render->b1;
				render->a1 = x;
				render->b1 = render->wh-y;
				if(render->a1 > render->wh/10+1 && render->wh/10 < render->b1 && render->b1 < render->wh-31)
				{
					if(render->a2 > render->wh/10+1 && render->wh/10 < render->b2 && render->b2 < render->wh-31)
					{
						if(render->a3 > render->wh/10+1 && render->wh/10 < render->b3 && render->b3 < render->wh-31)
						{
							//render->draw_triangle(render->a1,render->a2,render->a3,render->b1,render->b2,render->b3,m);
							Triangulo triangulo(render->a1,render->a2,render->a3,render->b1,render->b2,render->b3,render->size,render->punteada, render->r, render->g, render->b);
							v_Triangulos.push_back(triangulo);
							render->reset();
							display();

						}
					}
				}
			}
		}

		/* to draw a RECTANGLE */
		else if(draw==4)  
		{

			if(x>render->wh/10+1 && render->wh/10<render->wh-y && render->wh-y<render->wh-31)
			{
				render->drawpoint(x, y);
				render->a2 = render->a1;
				render->b2 = render->b1;
				render->a1 = x;
				render->b1 = render->wh-y;
                if(render->a1 > render->wh/10+1 && render->wh/10 < render->b1 && render->b1 < render->wh-31)
				{
					if(render->a2 > render->wh/10+1 && render->wh/10 < render->b2 && render->b2 < render->wh-31)
					{
						//render->draw_rectangle(render->a1,render->a2,render->b1,render->b2,m);
						Cuadrilatero cuadrilatero(render->a1,render->a2,render->b1,render->b2,render->size,render->punteada);
						v_Cuadrilateros.push_back(cuadrilatero);
						render->reset();
						display();
					}
				}
			}
		}


		/* to draw a POLYGON */
		else if(draw==5)  
		{
			//pol=1;
			if(x>render->wh/10+1 && render->wh/10<render->wh-y && render->wh-y<render->wh-31)
			{
				render->drawpoint(x, y);
				render->a2=render->a1;
				render->b2=render->b1;
				render->a1=x;
				render->b1=render->wh-y;
				m++;
				render->a[m][0]=x;
				render->a[m][1]=render->wh-y;

				if(render->a1>render->wh/10+1 && render->wh/10<render->b1 && render->b1<render->wh-31)
				{
					if(render->a2>render->wh/10+1 && render->wh/10<render->b2 && render->b2<render->wh-31)
					{
						contador++;
						glLineWidth(render->size);
						glBegin(GL_LINES);
							glVertex2f(render->a2, render->b2);
							glVertex2f(render->a1, render->b1);
						glEnd();
						cout << contador << endl;
					}
				}
			}
		}

		/* to draw a CIRCLE */
		else if(draw==6)   
		{

			if(x>render->wh/10+1 && render->wh/10<render->wh-y && render->wh-y<render->wh-31)
			{
				render->drawpoint(x, y);
				render->a2=render->a1;
				render->b2=render->b1;
				render->a1=x;
				render->b1=render->wh-y;
				if(render->a1>render->wh/10+1 && render->wh/10<render->b1 && render->b1<render->wh-31)
				{
					if(render->a2>render->wh/10+1 && render->wh/10<render->b2 && render->b2<render->wh-31)
					{
						r=sqrt((render->a1-render->a2)*(render->a1-render->a2)+(render->b1-render->b2)*(render->b1-render->b2));
						Circulo circulo(render->a2,render->b2,r,render->size);
						v_Circulos.push_back(circulo);
						/*
						n++;
						render->v[n][0]=render->a2;
						render->v[n][1]=render->b2;
						n++;
						render->v[n][0]=render->a1;
						render->v[n][1]=render->b1;
						n++;
						render->v[n][0]='$';
						render->v[n][1]='$';*/
						render->reset();
						display();
					}
				}
			}
		}

		/* to draw a AIRBRUSH */
		else if(draw==7)  
		{
			if(x>render->wh/10+1 && render->wh/10<render->wh-y && render->wh-y<render->wh-31)
			{
				for(i=0;i<60;i++)
				{
                	j=rand()%17;
					k=rand()%17;
					render->drawpoint(x+j,y+k);
                }
			}
		}

		/* to FILL A POLYGON with the selected color */
		else if(draw==9)  
		{
			if(x>render->wh/10+1 && render->wh/10<render->wh-y && render->wh-y<render->wh-31)
			{
				y=render->wh-y;
				render->flag1=0;
				for(i=1;i<=m;i++)
				{
					num2=i-1;
					for(i1=i;render->a[i1][0]!='$';i1++)
					{
						num2++;
					}
					num1=i;
					render->detect_point(num1, num2, x, y);

					if(render->flag!=0)
					{
						render->scanfill(num1, num2);
						render->flag=0;
						render->flag1=1;
					}
					i=num2+1;
				}

				if(render->flag1==0 && flag2==0)
				{
					for(i=1;i<=n;i++)
					{
						num2=i-1;
						for(i1=i;render->v[i1][0]!='$';i1++)
						{
							num2++;
						}
						num1=i;

						r1=sqrt((render->v[num1][0]-render->v[num2][0])*(render->v[num1][0]-render->v[num2][0])+(render->v[num1][1]-render->v[num2][1])*(render->v[num1][1]-render->v[num2][1]));
						r2=sqrt((render->v[num1][0]-x)*(render->v[num1][0]-x)+(render->v[num1][1]-y)*(render->v[num1][1]-y));

						if(r2<r1)
						{
							for(i2=0;i2<r1;i2=i2+2)
							{
								render->fill=1;
								render->draw_circle(render->v[num1][0], render->v[num1][1], i2);
							}
							render->fill=0;

							flag2=1;
						}

						i=num2+1;
					}
				}

			}
		}

		/* to ERASE */
		if(draw==8)
		{
			if(x>render->wh/10+1 && render->wh/10<render->wh-y && render->wh-y<render->wh-31)
				glutMotionFunc(eraser);
		}

		else if(draw==10)
		{
			if(x>render->wh/10+1 && render->wh/10<render->wh-y && render->wh-y<render->wh-31)
				glutMotionFunc(paint);

		}

		/* to draw a Poligono */
		else if(draw==11)  
		{
			if(x>render->wh/10+1 && render->wh/10<render->wh-y && render->wh-y<render->wh-31)
			{
				//render->drawpoint(x, y);
				render->a2=render->a1;
				render->b2=render->b1;
				render->a1=x;
				render->b1=render->wh-y;       

				if(render->a1>render->wh/10+1 && render->wh/10<render->b1 && render->b1<render->wh-31)
				{
					if(render->a2>render->wh/10+1 && render->wh/10<render->b2 && render->b2<render->wh-31)
					{
						if(punteada)
						{
							Poligono poligono(render->a1, render->a2, render->b1, render->b2,render->vertices, render->size, render->punteada);
							v_Poligonos.push_back(poligono);

							//Linea linea(render->a1,render->a2,render->b1,render->b2,render->size,render->punteada);
							//v_Lineas.push_back(linea);
							//render->regularPolygon2(render->a1, render->a2, render->b1, render->b2);//, render->b2);
							render->reset();
							display();
							//render->draw_lines(render->a1,render->a2,punteada);
						}
						else
						{
							Poligono poligono(render->a1, render->a2, render->b1, render->b2,render->vertices, render->size, render->punteada);
							v_Poligonos.push_back(poligono);
							render->reset();
							display();
							//render->draw_lines(render->a1,render->a2,punteada);
						}
					}
				}
			}
		}

		else if(x>render->wh/10+1 && render->wh/10<render->wh-y && render->wh-y<render->wh-31)
			glutMotionFunc(drawpoint);


		if(x>=6*render->wh/60 && x<=12*render->wh/60 && render->wh-y>=57*render->wh/60 && render->wh-y<=render->wh)  /* to OPEN an existing FILE */
		{

			save=2;
			render->set_font(GLUT_BITMAP_9_BY_15);
			render->set_color(0, 0, 0);
			//drawstring(40*render->wh/60, 58*render->wh/60, 0.0, "Enter filename: ");
			textx=60*render->wh/60;
			texty=58*render->wh/60;
		}


		/* to SAVE the current image onto a FILE */
		else if(x>=12*render->wh/60 && x<=18*render->wh/60 && render->wh-y>=57*render->wh/60 && render->wh-y<=render->wh)
		{
			save=1;

			/*render->set_font(GLUT_BITMAP_9_BY_15);
			render->set_color(0, 0, 0);
			textx=60*render->wh/60;
			texty=58*render->wh/60; */
			//guardaImagen("Imagen.tga",800,600);
		}


		/* to CLEAR the DRAWING AREA */
		else if(x>=18*render->wh/60 && x<=24*render->wh/60 && render->wh-y>=57*render->wh/60 && render->wh-y<=render->wh) 
		{

			for(i=1;i<=m;i++)
				render->a[i][0]=render->a[i][1]=0;


			v_Lineas.clear();
			v_Cuadrilateros.clear();
			v_Triangulos.clear();
			v_Puntos.clear();
			v_Circulos.clear(); 
			v_Poligonos.clear(); 
			render->lineaPunteada(false);

			for(i=1;i<=n;i++)
				render->v[i][0]=render->v[i][1]=0;
				m=n=0;
				count=0;
				render->size = 1;
				display();
		}

		render->palette(render->wh/30, 2*render->wh/30, 2*render->wh/30, 2*render->wh/30, 2*render->wh/30, render->wh/30, render->wh/30, render->wh/30);  /* to display SELECTED COLOUR */
		render->draw_btn_background();
		glFlush();
		glReadBuffer(GL_FRONT);
		glReadPixels(render->wh/10+2, render->wh/10, render->ww-render->wh/10-2, render->wh-render->wh/10-render->wh/20-1,GL_RGB, GL_UNSIGNED_BYTE, image);
		posx=render->wh/10+2;
		posy=render->wh/10;

  }

	if(btn==GLUT_LEFT_BUTTON && state==GLUT_UP)
	{
		glReadBuffer(GL_FRONT);
		glReadPixels(render->wh/10+2, render->wh/10, render->ww-render->wh/10-2, render->wh-render->wh/10-render->wh/20-1,GL_RGB, GL_UNSIGNED_BYTE, image);
		posx=render->wh/10+2;
		posy=render->wh/10;
	}

}

#endif
