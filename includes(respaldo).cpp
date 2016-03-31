#ifndef INCLUDES_H
#define INCLUDES_H

#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <iostream>
#include "Render.h"
#include "Circulo.h"
#include "Cuadrilatero.h"
#include "Linea.h"
#include "Punto.h"
#include "Triangulo.h"

using namespace std;

GLrender->sizei wh = 600, ww = 800,wx,wy, wx1=800, wy1=600;/*display window render->size*/

Render *render = new Render();

int draw;  /* to store draw option*/
int m, n;
int pol;
int i, j, k;
float textx,texty, textz=0.0;

int save=0;

char* image;

int count=0;
int sub_menu;
float posx, posy;
void *currentfont;
FILE *fptr;
char fname[20];
int s=0;
int wel=2;

void myReshape(GLrender->sizei w, GLrender->sizei h) /* RESHAPE FUNCTION */
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



void display()
{
	render->set_color_background(1.0,1.0,1.0,1.0);
	render->draw_toolbar();
	render->draw_palette();
	render->draw_toolbox();
	render->draw_btn_line();
	render->draw_btn_triangle();
	render->draw_btn_rectangle();
	render->draw_btn_pencil();
	render->draw_btn_eraser();
	render->draw_btn_pencil2();
	render->draw_btn_circle(9*wh/120, 16.5*wh/20, wh/60);		/* to draw CIRCLE OPTION on tool bar */
    render->draw_btn_air_brush();
	render->draw_btn_fill_color();
	render->draw_btn_brush();
	render->set_font(GLUT_BITMAP_HELVETICA_12);
	//glColor3f(0, 0, 1);
	//render->drawstring(26*wh/60,wh/20,0.0,"",0,0,1);
//	glColor3f(0, 0, 0);
	render->drawstring(6*wh/60, 58*wh/60, 0.0, "Open",0,0,0);
	render->drawstring(12*wh/60, 58*wh/60, 0.0, "Save",0,0,0);
	render->drawstring(18*wh/60, 58*wh/60, 0.0, "Clear",0,0,0);

	glFlush();
	//glReadBuffer(GL_FRONT);
	//glReadPixels(wh/10+2, wh/10, ww-wh/10-2, wh-wh/10-wh/20-1,GL_RGB, GL_UNSIGNED_BYTE, image); /* to read pixels from buffer to memory */
	//posx=wh/10+2;
	//posy=wh/10;
	//}

}

void myMouse(int btn, int state, int x, int y)
{
	GLfloat r, r1, r2;
	int num1=0, num2=0;

	int i1, i2;
	int flag2;

	flag2=0;


	if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
	{
		/* to SELECT A  COLOR */


		if(wel==1)
		{
			wel=2;
			display();
		}


		if(6*wh/60<x && x<8*wh/60 && wh/60<wh-y && wh-y<wh/20)
			glColor3f(0, 0, 0);


		else if(6*wh/60<x && x<8*wh/60 && wh/20<wh-y && wh-y<wh/12)
			glColor3f(1, 1, 1);


		else if(8*wh/60<x && x<10*wh/60 && wh/60<wh-y && wh-y<wh/20)
	         glColor3f(0, 0, 1);


		else if(8*wh/60<x && x<10*wh/60 && wh/20<wh-y && wh-y<wh/12)
		     glColor3f(1, 0, 1);


		else if(10*wh/60<x && x<12*wh/60 && wh/60<wh-y && wh-y<wh/20)
		     glColor3f(1, 1, 0);


		else if(10*wh/60<x && x<12*wh/60 && wh/20<wh-y && wh-y<wh/12)
		     glColor3f(1, 0, 0);


		else if(12*wh/60<x && x<14*wh/60 && wh/60<wh-y && wh-y<wh/20)
			 glColor3f(0, 1, 0);


		else if(12*wh/60<x && x<14*wh/60 && wh/20<wh-y && wh-y<wh/12)
		     glColor3f(0, 1, 1);


		else if(14*wh/60<x && x<16*wh/60 && wh/60<wh-y && wh-y<wh/20)
			 glColor3f(0.5, 0.5, 0);

		else if(14*wh/60<x && x<16*wh/60 && wh/20<wh-y && wh-y<wh/12)
			 glColor3f(0.1, 0.4, 0.6);

		else if(16*wh/60<x && x<18*wh/60 && wh/60<wh-y && wh-y<wh/20)
			 glColor3f(0.4, 0.1, 0.1);

		else if(16*wh/60<x && x<18*wh/60 && wh/20<wh-y && wh-y<wh/12)
			 glColor3f(0.9, 0.1, 0.5);


		else if(18*wh/60<x && x<20*wh/60 && wh/60<wh-y && wh-y<wh/20)
			 glColor3f(0.5, 0.1, 0.5);

		else if(18*wh/60<x && x<20*wh/60 && wh/20<wh-y && wh-y<wh/12)
			glColor3f(0.3, 0.1, 0.5);

		else if(20*wh/60<x && x<22*wh/60 && wh/60<wh-y && wh-y<wh/20)
			 glColor3f(0.0, 0.5, 0.1);

		else if(20*wh/60<x && x<22*wh/60 && wh/20<wh-y && wh-y<wh/12)
			 glColor3f(0.9, 0.8, 0.0);


		else if(22*wh/60<x && x<24*wh/60 && wh/60<wh-y && wh-y<wh/20)
			 glColor3f(0.7, 0.0, 0.0);


		else if(22*wh/60<x && x<24*wh/60 && wh/20<wh-y && wh-y<wh/12)
			 glColor3f(0.5, 0.5, 0.5);


		                /*end select color */


		             /* to select WHAT TO  DRAW */

		if(2<x && x<wh/20 && 18*wh/20<wh-y && wh-y<wh-(wh/20)-1)                    /* selected option is PENCIL*/
			draw=1;


		else if(wh/20<x && x<wh/10-2 && 18*wh/20<wh-y && wh-y<wh-(wh/20)-1)         /* selected option is LINE */
		{

			render->reset();
			draw=2;
		}


		else if(2<x && x<wh/20 && 17*wh/20<wh-y && wh-y<18*wh/20)                    /* selected option is TRIANGLE */

		{
			render->reset();
			draw=3;
		}


		else if(wh/20<x && x<wh/10-2 && 17*wh/20<wh-y && wh-y<18*wh/20)               /* selected option is RECTANGLE */
		{

			render->reset();
			draw=4;
		}


		else if(2<x && x<wh/20 && 16*wh/20<wh-y && wh-y<17*wh/20)                     /* selected option is POLYGON */
		{

			render->reset();
			draw=5;
		}


		else if(wh/20<x && x<wh/10-2 && 16*wh/20<wh-y && wh-y<17*wh/20)               /* selected option is CIRCLE */
		{
			render->reset();
			draw=6;
		}


		else if(2<x && x<wh/20 && 15*wh/20<wh-y && wh-y<16*wh/20)                      /* selected option is AIRBRUSH */
		{

			render->reset();
			draw=7;
		}


		else if(wh/20<x && x<wh/10-2 && 15*wh/20<wh-y && wh-y<16*wh/20)                /* selected option is ERASER */
		{
			render->reset();
			draw=8;
		}



		else if(2<x && x<wh/20 && 14*wh/20<wh-y && wh-y<15*wh/20)                      /* selected option is COLOR FILL */
		{

			render->reset();
			draw=9;
		}


		else if(wh/20<x && x<wh/10-2 && 14*wh/20<wh-y && wh-y<15*wh/20)                /* selected option is PAINT BRUSH */
		{
			render->reset();
			draw=10;
		}





		 if(draw==1)         /* to draw using a  PENCIL  */
			{
				if(pol==1)
				{
					m++;
					render->a[m][0]='$';
					render->a[m][1]='$';

					pol=0;
				}

				if(x>wh/10+1 && wh/10<wh-y && wh-y<wh-31)
					glutMotionFunc(drawpoint);

			}


		 else if(draw==2)  /* to draw a LINE */
		{
			if(pol==1)
				{
					m++;
					render->a[m][0]='$';
					render->a[m][1]='$';

					pol=0;
				}


			if(x>wh/10+1 && wh/10<wh-y && wh-y<wh-31)
			{
					render->drawpoint(x, y);

					render->a2=render->a1;
					render->b2=render->b1;

					render->a1=x;
					render->b1=wh-y;


					if(render->a1>wh/10+1 && wh/10<render->b1 && render->b1<wh-31)
					{
						if(render->a2>wh/10+1 && wh/10<render->b2 && render->b2<wh-31)
						{
							glLineWidth(render->size);
							glBegin(GL_LINES);
								glVertex2f(render->a2, render->b2);
								glVertex2f(render->a1, render->b1);
							glEnd();

							render->reset();

						}
					}
			}

		}


		else if(draw==3)  /* to draw a TRIANGLE */
		 {
			if(pol==1)
				{
					m++;
					render->a[m][0]='$';
					render->a[m][1]='$';

					pol=0;
				}



			if(x>wh/10+1 && wh/10<wh-y && wh-y<wh-31)
				{
					render->drawpoint(x, y);


					render->a3=render->a2;
					render->b3=render->b2;

					render->a2=render->a1;
					render->b2=render->b1;

					render->a1=x;
					render->b1=wh-y;





					if(render->a1>wh/10+1 && wh/10<render->b1 && render->b1<wh-31)
					{
						if(render->a2>wh/10+1 && wh/10<render->b2 && render->b2<wh-31)
						{
							if(render->a3>wh/10+1 && wh/10<render->b3 && render->b3<wh-31)

							{
									glLineWidth(render->size);
								glBegin(GL_LINE_LOOP);
									glVertex2f(render->a3, render->b3);
									glVertex2f(render->a2, render->b2);
									glVertex2f(render->a1, render->b1);
								glEnd();

							m++;
							render->a[m][0]=render->a3;
							render->a[m][1]=render->b3;

							m++;
							render->a[m][0]=render->a2;
							render->a[m][1]=render->b2;

							m++;
							render->a[m][0]=render->a1;
							render->a[m][1]=render->b1;

							m++;
							render->a[m][0]='$';
							render->a[m][1]='$';






							render->reset();
							}
						}
					}
				}

		}


			else if(draw==4)  /* to draw a RECTANGLE */
		 {

				if(pol==1)
				{
					m++;
					render->a[m][0]='$';
					render->a[m][1]='$';

					pol=0;
				}

				if(x>wh/10+1 && wh/10<wh-y && wh-y<wh-31)
				{
					render->drawpoint(x, y);

					render->a2=render->a1;
					render->b2=render->b1;

					render->a1=x;
					render->b1=wh-y;


                  if(render->a1>wh/10+1 && wh/10<render->b1 && render->b1<wh-31)
					{
						if(render->a2>wh/10+1 && wh/10<render->b2 && render->b2<wh-31)
						{
								glLineWidth(render->size);
							glBegin(GL_LINE_LOOP);
								glVertex2f(render->a2, render->b2);
								glVertex2f(render->a1, render->b2);
								glVertex2f(render->a1, render->b1);
								glVertex2f(render->a2, render->b1);
							glEnd();


							m++;
							render->a[m][0]=render->a2;
							render->a[m][1]=render->b2;

							m++;
							render->a[m][0]=render->a1;
							render->a[m][1]=render->b2;

							m++;
							render->a[m][0]=render->a1;
							render->a[m][1]=render->b1;


							m++;
							render->a[m][0]=render->a2;
							render->a[m][1]=render->b1;

							m++;
							render->a[m][0]='$';
							render->a[m][1]='$';


							render->reset();

						}
					}
				}

		}


		else if(draw==5)  /* to draw a POLYGON */
			{

				pol=1;
				if(x>wh/10+1 && wh/10<wh-y && wh-y<wh-31)
				{
					render->drawpoint(x, y);

					render->a2=render->a1;
					render->b2=render->b1;

					render->a1=x;
					render->b1=wh-y;

					m++;
					render->a[m][0]=x;
					render->a[m][1]=wh-y;




					if(render->a1>wh/10+1 && wh/10<render->b1 && render->b1<wh-31)
					{
						if(render->a2>wh/10+1 && wh/10<render->b2 && render->b2<wh-31)
						{
								glLineWidth(render->size);
							glBegin(GL_LINES);
								glVertex2f(render->a2, render->b2);
								glVertex2f(render->a1, render->b1);
							glEnd();
						}
					}

				}



		}

		else if(draw==6)    /* to draw a CIRCLE */
		{
			if(pol==1)
				{
					m++;
					render->a[m][0]='$';
					render->a[m][1]='$';

					pol=0;
				}


			if(x>wh/10+1 && wh/10<wh-y && wh-y<wh-31)
			{
					render->drawpoint(x, y);

					render->a2=render->a1;
					render->b2=render->b1;

					render->a1=x;
					render->b1=wh-y;

					if(render->a1>wh/10+1 && wh/10<render->b1 && render->b1<wh-31)
					{
						if(render->a2>wh/10+1 && wh/10<render->b2 && render->b2<wh-31)
						{
							r=sqrt((render->a1-render->a2)*(render->a1-render->a2)+(render->b1-render->b2)*(render->b1-render->b2));
							draw_circle(render->a2, render->b2, r);

							n++;
							render->b[n][0]=render->a2;
							render->b[n][1]=render->b2;

							n++;
							render->b[n][0]=render->a1;
							render->b[n][1]=render->b1;

							n++;
							render->b[n][0]='$';
							render->b[n][1]='$';

							render->reset();

						}
					}
			}
		}



		else if(draw==7)  /* to draw a AIRBRUSH */
		{
			if(pol==1)
				{
					m++;
					render->a[m][0]='$';
					render->a[m][1]='$';

					pol=0;
				}

			if(x>wh/10+1 && wh/10<wh-y && wh-y<wh-31)
			 {
				 for(i=0;i<60;i++)
				 {
                     j=rand()%17;
					 k=rand()%17;
					 render->drawpoint(x+j,y+k);
                 }



			 }
		}


		else if(draw==9)  /* to FILL A POLYGON with the selected color */
		{
			if(pol==1)
				{
					m++;
					render->a[m][0]='$';
					render->a[m][1]='$';

					pol=0;
				}


		if(x>wh/10+1 && wh/10<wh-y && wh-y<wh-31)
			 {
				y=wh-y;


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
						for(i1=i;render->b[i1][0]!='$';i1++)
						{
							num2++;
						}
						num1=i;

						r1=sqrt((render->b[num1][0]-render->b[num2][0])*(render->b[num1][0]-render->b[num2][0])+(render->b[num1][1]-render->b[num2][1])*(render->b[num1][1]-render->b[num2][1]));
						r2=sqrt((render->b[num1][0]-x)*(render->b[num1][0]-x)+(render->b[num1][1]-y)*(render->b[num1][1]-y));


						if(r2<r1)
						{



							for(i2=0;i2<r1;i2=i2+2)
							{
								render->fill=1;
								draw_circle(render->b[num1][0], render->b[num1][1], i2);
							}
							render->fill=0;

							flag2=1;
						}

						i=num2+1;
					}
				}

			}
		}




		if(draw==8) /* to ERASE */

		{
			if(pol==1)
				{
					m++;
					render->a[m][0]='$';
					render->a[m][1]='$';

					pol=0;
				}

			if(x>wh/10+1 && wh/10<wh-y && wh-y<wh-31)
					glutMotionFunc(eraser);
		 }

		else if(draw==10)
		{
			if(pol==1)
				{
					m++;
					render->a[m][0]='$';
					render->a[m][1]='$';

					pol=0;
				}


			if(x>wh/10+1 && wh/10<wh-y && wh-y<wh-31)

				glutMotionFunc(paint);

		}





		else if(x>wh/10+1 && wh/10<wh-y && wh-y<wh-31)
			glutMotionFunc(drawpoint);


		if(x>=6*wh/60 && x<=12*wh/60 && wh-y>=57*wh/60 && wh-y<=wh)  /* to OPEN an existing FILE */
		{

			save=2;

			render->set_font(GLUT_BITMAP_9_BY_15);
			glColor3f(0, 0, 0);

			//drawstring(40*wh/60, 58*wh/60, 0.0, "Enter filename: ");
			textx=60*wh/60;
			texty=58*wh/60;




		}



		else if(x>=12*wh/60 && x<=18*wh/60 && wh-y>=57*wh/60 && wh-y<=wh) /* to SAVE the current image onto a FILE */
		{
			save=1;

			render->set_font(GLUT_BITMAP_9_BY_15);
			glColor3f(0, 0, 0);
			textx=60*wh/60;
			texty=58*wh/60;



		}


		else if(x>=18*wh/60 && x<=24*wh/60 && wh-y>=57*wh/60 && wh-y<=wh) /* to CLEAR the DRAWING AREA */
		{

				for(i=1;i<=m;i++)
					render->a[i][0]=render->a[i][1]=0;




				for(i=1;i<=n;i++)
					render->b[i][0]=render->b[i][1]=0;

				m=n=0;


				count=0;
				display();
		}




		palette(wh/30, 2*wh/30, 2*wh/30, 2*wh/30, 2*wh/30, wh/30, wh/30, wh/30);  /* to display SELECTED COLOUR */

		glFlush();


		glReadBuffer(GL_FRONT);


		glReadPixels(wh/10+2, wh/10, ww-wh/10-2, wh-wh/10-wh/20-1,GL_RGB, GL_UNSIGNED_BYTE, image);

		posx=wh/10+2;
		posy=wh/10;



  }

	if(btn==GLUT_LEFT_BUTTON && state==GLUT_UP)
	{
		glReadBuffer(GL_FRONT);


		glReadPixels(wh/10+2, wh/10, ww-wh/10-2, wh-wh/10-wh/20-1,GL_RGB, GL_UNSIGNED_BYTE, image);

		posx=wh/10+2;
		posy=wh/10;
	}

}

#endif