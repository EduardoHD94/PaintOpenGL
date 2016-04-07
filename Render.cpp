
#include "Render.h"
#include <GL/glut.h>
#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

using namespace std;

Render::Render()
{
	wh  = 600; 
	ww  = 800;
	wx1 = 800;
	wy1 = 600;
	size = 1;
	vertices = 5;
	fill = 0;
	flag = 0;
	a1 = a2 = a3 = b1 = b2 = b3 = 0;
	punteada = false;
	r = 255;
	g = 255;
	b = 255;
}	



int Render::get_wh()
{
	return wh;
}

int Render::get_ww()
{
	return ww;
}

void Render::reset()
{
	a1 = a2 = a3 = b1 = b2 = b3 = 0;
}

void Render::set_ww(int ww)
{
	this->ww = ww;
}

void Render::set_wh(int wh)
{
	this->wh = wh;
}

void Render::loop()
{
    glutMainLoop();
}

void Render::palette(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4) /* to draw the COLOR PALETTE */
{
	glBegin(GL_QUADS);
		glVertex2f(x1, y1);
		glVertex2f(x2, y2);
		glVertex2f(x3, y3);
		glVertex2f(x4, y4);
	glEnd();
}

void Render::edgedetect(float x1, float y1, float x2, float y2, int *le, int *re) 
{
	float mx, x, temp;

	if((y2-y1)<0)
	{
		temp=y1;
		y1=y2;
		y2=temp;

		temp=x1;
		x1=x2;
		x2=temp;
	}

	if((y2-y1)!=0)
		mx=(x2-x1)/(y2-y1);
	else
		mx=x2-x1;

	x=x1;

	for(int i=y1;i<=y2;i++)
	{
		if(x<(float)le[i])
			le[i]=(int)x;
		if(x>(float)re[i])
			re[i]=(int)x;
		x+=mx;
	}
}


/* Llenar poligono mediante algoritmo de scaneo de linea*/
void Render::scanfill(int num1, int num2)        
{
	int le[1000], re[1000];
	int p, q;
	int bottom, top;

	for(p=0;p<wh;p++)
	{
		le[p]=ww;
		re[p]=0;
	}

	for(p=num1;p<num2;p++)
	{
		edgedetect(a[p][0], a[p][1], a[p+1][0], a[p+1][1], le, re);
	}

	edgedetect(a[num2][0], a[num2][1], a[num1][0], a[num1][1], le, re);

	for(q=0;q<wh;q++)
		le[q]=le[q]+1;

	bottom=0;
	while(re[bottom]<le[bottom])
		bottom++;

	bottom++;

	top=wh-1;
	while(re[top]<le[top])
		top--;


	for(q=bottom;q<top;q++)
	{
		if(le[q]<=re[q])
		{
			for(p=(int)le[q];p<(int)re[q];p++)
				draw_pixel(p, q);
		}
	}
}

void Render::eraser(int x, int y)
{
	y = wh-y;

	set_color(255, 255, 255);

	if(x>wh/10+1 && wh/10<y && y<wh-31)
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

void Render::paint(int x, int y)
{
	y = wh-y;

	if(x>wh/10+1 && wh/10<y && y<wh-31)
	{
			glBegin(GL_POLYGON);
	 			glVertex2f(x, y);
				glVertex2f(x+4+size, y);
	 			glVertex2f(x+4+size, y+4+size);
	    	glVertex2f(x, y+4+size);
			glEnd();
		glFlush();
	}
}

void Render::detect_point(int num1, int num2, int x, int y) 
{
	int le[1000], re[1000];
	int p, q;

	for(p=0;p<wh;p++)
	{
		le[p]=ww;
		re[p]=0;
	}

	for(p=num1;p<num2;p++)
	{
		edgedetect(a[p][0], a[p][1], a[p+1][0], a[p+1][1], le, re);
	}

	edgedetect(a[num2][0], a[num2][1], a[num1][0], a[num1][1], le, re);

	for(q=0;q<wh;q++)
	{
		if(le[q]<=re[q])
		{
			for(p=(int)le[q];p<(int)re[q];p++)
			{
				if(x==p && y==q)
					flag=num1;
			}
		}
	}
}

void Render::set_color(float r, float g, float b)
{
	r = r / 255;
	g = g / 255;
	b = b / 255;
	glColor3f(r, g, b);
}

void Render::set_color_background(float r, float g, float b, float a)
{
	r = r / 255;
	g = g / 255;
	b = b / 255;
	a = a / 255;
	glClearColor(r,g,b,a);
	glClear(GL_COLOR_BUFFER_BIT);
}

void Render::set_font(void *font)
{
	currentFont=font;
}

void Render::drawstring(float x,float y,float z,string s, float r, float g, float b)
{
	glRasterPos3f(x,y,z);

	for (string::iterator i = s.begin(); i != s.end(); ++i)
	{
		glutBitmapCharacter(currentFont,*i);
		
	}
	set_color(r,g,b);
}


void Render::draw_toolbar()
{

	set_color(207, 219, 173);
	glPointSize(1);
	glLineWidth(1);
	glRectf(0,wh/10+1,wh/10,wh-(wh/20)-1);      /* dibujar barra de herramientas */
	glRectf(0, 0, ww, wh/10);                 /* dibujar area de color */
	glRectf(0,wh-(wh/20), ww, wh);              /* dibujar area de menu*/
}
void Render::draw_palette()
{
	set_color(0, 0, 0);
	palette(6*wh/60+1, wh/60, 6*wh/60+1, wh/20-1, 8*wh/60-1, wh/20-1, 8*wh/60-1, wh/60);
	
	set_color(255, 255, 255);
	palette(6*wh/60+1, wh/20+1, 6*wh/60+1, wh/12, 8*wh/60-1, wh/12, 8*wh/60-1, wh/20+1);

	set_color(239, 223, 132);
	palette(8*wh/60+1, wh/60, 8*wh/60+1, wh/20-1, 10*wh/60-1, wh/20-1, 10*wh/60-1, wh/60);

	set_color(232, 99, 113);
	palette(8*wh/60+1, wh/20+1, 8*wh/60+1, wh/12, 10*wh/60-1, wh/12, 10*wh/60-1, wh/20+1);

	set_color(80, 186, 188);
	palette(10*wh/60+1, wh/60, 10*wh/60+1, wh/20-1, 12*wh/60-1, wh/20-1, 12*wh/60-1, wh/60);

	set_color(161, 185, 196);
	palette(10*wh/60+1, wh/20+1, 10*wh/60+1, wh/12, 12*wh/60-1, wh/12, 12*wh/60-1, wh/20+1);

	set_color(241, 144, 86);
	palette(12*wh/60+1, wh/60, 12*wh/60+1, wh/20-1, 14*wh/60-1, wh/20-1, 14*wh/60-1, wh/60);

	set_color(180, 231, 254);
	palette(12*wh/60+1, wh/20+1, 12*wh/60+1, wh/12, 14*wh/60-1, wh/12, 14*wh/60-1, wh/20+1);

	set_color(203, 143, 244);
	palette(14*wh/60+1, wh/60, 14*wh/60+1, wh/20-1, 16*wh/60-1, wh/20-1, 16*wh/60-1, wh/60);

	set_color(51, 255, 90);
	palette(14*wh/60+1, wh/20+1, 14*wh/60+1, wh/12, 16*wh/60-1, wh/12, 16*wh/60-1, wh/20+1);

	set_color(254, 139, 180);
	palette(16*wh/60+1, wh/60, 16*wh/60+1, wh/20-1, 18*wh/60-1, wh/20-1, 18*wh/60-1, wh/60);

	set_color(248, 214, 36);
	palette(16*wh/60+1, wh/20+1, 16*wh/60+1, wh/12, 18*wh/60-1, wh/12, 18*wh/60-1, wh/20+1);

	set_color(248, 85, 94);
	palette(18*wh/60+1, wh/60, 18*wh/60+1, wh/20-1, 20*wh/60-1, wh/20-1, 20*wh/60-1, wh/60);

	set_color(76, 106, 141);
	palette(18*wh/60+1, wh/20+1, 18*wh/60+1, wh/12, 20*wh/60-1, wh/12, 20*wh/60-1, wh/20+1);

	set_color(188, 217, 85);
	palette(20*wh/60+1, wh/60, 20*wh/60+1, wh/20-1, 22*wh/60-1, wh/20-1, 22*wh/60-1, wh/60);

	set_color(248, 214, 139);
	palette(20*wh/60+1, wh/20+1, 20*wh/60+1, wh/12, 22*wh/60-1, wh/12, 22*wh/60-1, wh/20+1);

	set_color(255, 171, 69);
	palette(22*wh/60+1, wh/60, 22*wh/60+1, wh/20-1, 24*wh/60-1, wh/20-1, 24*wh/60-1, wh/60);

	set_color(152, 102, 41);
	palette(22*wh/60+1, wh/20+1, 22*wh/60+1, wh/12, 24*wh/60-1, wh/12, 24*wh/60-1, wh/20+1);

}


void Render::draw_circle(float p, float q, float r)
{
	float d = 1-r;
	float x = 0;
	float y = r;

	while(y>x)
	{
		plotpixels(p, q, x, y);
		if(d<0) d+=2*x+3;
		else
		{
			d+=2*(x-y)+5;
			--y;
		}
		++x;
	}
	plotpixels(p, q, x, y);
}

void Render::plotpixels(float p, float q, float x, float y)
{
	draw_pixel(x+p, y+q);
	draw_pixel(-x+p, y+q);
	draw_pixel(x+p, -y+q);
	draw_pixel(-x+p, -y+q);


	draw_pixel(y+p, x+q);
	draw_pixel(-y+p, x+q);
	draw_pixel(y+p, -x+q);
	draw_pixel(-y+p, -x+q);

}

void Render::plotpixels1(float p, float q, float x, float y)
{
	draw_pixel1(x+p, y+q);
	draw_pixel1(-x+p, y+q);
	draw_pixel1(x+p, -y+q);
	draw_pixel1(-x+p, -y+q);


	draw_pixel1(y+p, x+q);
	draw_pixel1(-y+p, x+q);
	draw_pixel1(y+p, -x+q);
	draw_pixel1(-y+p, -x+q);
}

void Render::draw_toolbox()
{
	set_color(208, 210, 198);
	glBegin(GL_QUADS);                            
		glVertex2f(2, wh-(wh/20)-1);
		glVertex2f(wh/10-2, wh-(wh/20)-1);
		glVertex2f(wh/10-2,7*wh/20);
		glVertex2f(2, 7*wh/20);
	glEnd();

	
	set_color(0, 0, 0);
	glBegin(GL_LINE_LOOP);                            
		glVertex2f(2, wh-(wh/20)-1);
		glVertex2f(wh/10-2, wh-(wh/20)-1);
		glVertex2f(wh/10-2,7*wh/20);
		glVertex2f(2, 7*wh/20);
	glEnd();

	set_color(0, 0, 0);
	glBegin(GL_LINES);
		glVertex2f(wh/20, wh-(wh/20)-1);
		glVertex2f(wh/20, 11*wh/20);

		glVertex2f(2, 18*wh/20);
		glVertex2f(wh/10-2, 18*wh/20);

		glVertex2f(2, 17*wh/20);
		glVertex2f(wh/10-2, 17*wh/20);

		glVertex2f(2, 16*wh/20);
		glVertex2f(wh/10-2, 16*wh/20);
	
		glVertex2f(2, 15*wh/20);
		glVertex2f(wh/10-2, 15*wh/20);

		glVertex2f(2, 14*wh/20);
		glVertex2f(wh/10-2, 14*wh/20);

		glVertex2f(2, 13*wh/20);
		glVertex2f(wh/10-2, 13*wh/20);

		glVertex2f(2, 12*wh/20);
		glVertex2f(wh/10-2, 12*wh/20);

		glVertex2f(2, 11*wh/20);
		glVertex2f(wh/10-2, 11*wh/20);

		glVertex2f(2, 10*wh/20);
		glVertex2f(wh/10-2, 10*wh/20);

		glVertex2f(2, 9*wh/20);
		glVertex2f(wh/10-2, 9*wh/20);

		glVertex2f(2, 8*wh/20);
		glVertex2f(wh/10-2, 8*wh/20);
	glEnd();
	
}

void Render::draw_pixel(float x, float y)                           
{
	if(x>wh/10+1 && wh/10<y && y<wh-31)
  	{
		if(fill==1)
			glPointSize(2);
		else
			glPointSize(size);
		glBegin(GL_POINTS);
			glVertex2f(x, y);
		glEnd();
	}
}



void Render::draw_pixel1(float x, float y)
{
	set_color(115, 29, 29);
	glBegin(GL_POINTS);
		glVertex2f(x, y);
	glEnd();	
}

void Render::drawpoint(int x, int y)
{
	y=wh-y;

	if(x>wh/10+1 && wh/10<y && y<wh-31)
	{ 
		glPointSize(size);
		glBegin(GL_POINTS);
			glVertex2f(x, y); 
		glEnd();
		glFlush();
	}
}

void Render::draw_btn_line()
{
	glBegin(GL_LINES);                           
		glVertex2f(4*wh/60, 18.8*wh/20);
		glVertex2f(5*wh/60, 18.2*wh/20);
	glEnd();
}

void Render::draw_btn_circle()
{
	float p = 9*wh/120;
	float q = 16.5*wh/20;
	float r = wh/60;
	int d = 1-(int)r;
	int x = 0;
	int y = (int)r;

	while(y>x)
	{
		plotpixels1(p, q, x, y);
		if(d<0)
			d+=2*x+3;
		else
		{
			d+=2*(x-y)+5;
			--y;
		}
		++x;
	}
	plotpixels1(p, q, x, y);

}

void Render::draw_btn_triangle()
{
	set_color(242, 93, 80);
	glBegin(GL_TRIANGLE_FAN);                         
		glVertex2f(wh/40, 17.8*wh/20);
		glVertex2f(wh/120, 17.2*wh/20);
		glVertex2f(5*wh/120, 17.2*wh/20);
	glEnd();

	set_color(0, 0, 0);
	glBegin(GL_LINE_LOOP);                              
		glVertex2f(wh/40, 17.8*wh/20);
		glVertex2f(wh/120, 17.2*wh/20);
		glVertex2f(5*wh/120, 17.2*wh/20);
	glEnd();
}


void Render::draw_btn_rectangle()
{
	set_color(67, 202, 217);
	glBegin(GL_TRIANGLE_FAN);                          
		glVertex2f(7*wh/120, 17.8*wh/20);
		glVertex2f(11*wh/120-2, 17.8*wh/20);
		glVertex2f(11*wh/120-2, 17.2*wh/20);
		glVertex2f(7*wh/120, 17.2*wh/20);
	glEnd();

	set_color(0, 0, 0);
	glBegin(GL_LINE_LOOP);                          
		glVertex2f(7*wh/120, 17.8*wh/20);
		glVertex2f(11*wh/120-2, 17.8*wh/20);
		glVertex2f(11*wh/120-2, 17.2*wh/20);
		glVertex2f(7*wh/120, 17.2*wh/20);
	glEnd();
}

void Render::draw_btn_pencil()
{
	set_color(0, 0, 0);

	glBegin(GL_TRIANGLES);                          
		glVertex2f(3*wh/120-1, 18.10*wh/20);
		glVertex2f(wh/60+2, 18.3*wh/20);
		glVertex2f(2*wh/60-4, 18.3*wh/20);
	glEnd();

	set_color(229, 225, 14);
	glBegin(GL_QUADS);
		glVertex2f(wh/60+2, 18.3*wh/20);
		glVertex2f(wh/60+2, 18.8*wh/20);
		glVertex2f(2*wh/60-4, 18.8*wh/20);
		glVertex2f(2*wh/60-4, 18.3*wh/20);
	glEnd(); 

	set_color(0, 0, 0);
	glBegin(GL_LINE_LOOP);
		glVertex2f(wh/60+2, 18.3*wh/20);
		glVertex2f(wh/60+2, 18.8*wh/20);
		glVertex2f(2*wh/60-4, 18.8*wh/20);
		glVertex2f(2*wh/60-4, 18.3*wh/20);
	glEnd(); 
}

void Render::draw_btn_pencil2()
{

	set_color(0, 0, 0);

	glBegin(GL_LINE_LOOP);                          
		glVertex2f(wh/120, 16.2*wh/20);
		glVertex2f(5*wh/120, 16.2*wh/20);
		glVertex2f(5*wh/120, 16.4*wh/20);
		glVertex2f(3*wh/120, 16.4*wh/20);
		glVertex2f(4*wh/120, 16.8*wh/20);
		glVertex2f(2*wh/120, 16.8*wh/20);
	glEnd();

}
void Render::draw_btn_eraser()
{
	set_color(120, 125, 217);
	glBegin(GL_QUADS);                              
		glVertex2f(3.2*wh/60, 15.7*wh/20);
		glVertex2f(5.1*wh/60, 15.7*wh/20);
		glVertex2f(5.5*wh/60, 15.3*wh/20);
		glVertex2f(3.6*wh/60, 15.3*wh/20);
	glEnd();

	set_color(242, 153, 177);
	glBegin(GL_QUADS);                              
		glVertex2f(4.2*wh/60, 15.7*wh/20);
		glVertex2f(5.1*wh/60, 15.7*wh/20);
		glVertex2f(5.5*wh/60, 15.3*wh/20);
		glVertex2f(4.6*wh/60, 15.3*wh/20);
	glEnd();
}

void Render::draw_btn_brush()
{
	glPointSize(1);

	set_color(242, 110, 68);
	glBegin(GL_QUADS);                                 
		glVertex2f(7*wh/120, 14.45*wh/20);
		glVertex2f(10*wh/120, 14.45*wh/20);
		glVertex2f(10*wh/120, 14.55*wh/20);
		glVertex2f(7*wh/120, 14.55*wh/20);
	glEnd();

	set_color(0, 0, 0);

	glBegin(GL_LINES);
		glVertex2f(10*wh/120, 14.45*wh/20);
		glVertex2f(11*wh/120, 14.4*wh/20);

		glVertex2f(10*wh/120, 14.55*wh/20);
		glVertex2f(11*wh/120, 14.6*wh/20);

		glVertex2f(10*wh/120, 14.47*wh/20);
		glVertex2f(11*wh/120, 14.47*wh/20);

		glVertex2f(10*wh/120, 14.53*wh/20);
		glVertex2f(11*wh/120, 14.53*wh/20);

	glEnd();
}

void Render::draw_btn_fill_color()
{
	set_color(229, 196, 74);
	glBegin(GL_QUADS);                              
		glVertex2f(2*wh/120, 14.6*wh/20);
		glVertex2f(3*wh/120+1, 14.2*wh/20);
		glVertex2f(5*wh/120-2, 14.35*wh/20);
		glVertex2f(4*wh/120-4, 14.75*wh/20);
	glEnd();

	set_color(0, 0, 0);
	glBegin(GL_LINE_LOOP);                              
		glVertex2f(2*wh/120, 14.6*wh/20);
		glVertex2f(3*wh/120+1, 14.2*wh/20);
		glVertex2f(5*wh/120-2, 14.35*wh/20);
		glVertex2f(4*wh/120-4, 14.75*wh/20);
	glEnd();


	set_color(0, 0, 0);
	glPointSize(3);
	glBegin(GL_POINTS);
		glVertex2f(2*wh/120-2, 14.6*wh/20-2);
	glEnd();
	glPointSize(1.5);
	glBegin(GL_POINTS);
		glVertex2f(2*wh/120-2, 14.6*wh/20-6);
	glEnd();
}

void Render::draw_btn_air_brush()
{
	for(int i=0;i<40;i++)
	{
		int j=rand()%15;
		int k=rand()%15;
		glBegin(GL_POINTS);
			glVertex2f(wh/120+j,15.8*wh/20-k);
		glEnd();
    }
}

void Render::draw_btn_increment()
{
	set_color(0, 0, 0);
	glBegin(GL_LINES);                              
		glVertex2f(3.3*wh/120, 13.2*wh/20);
		glVertex2f(3.3*wh/120, 13.85*wh/20);
	glEnd();

	set_color(0, 0, 0);
	glBegin(GL_LINES);                              
		glVertex2f(1.3*wh/120, 13.5*wh/20);
		glVertex2f(5.3*wh/120, 13.5*wh/20);
	glEnd();
}

void Render::draw_btn_decrement()
{
	set_color(0, 0, 0);
	glBegin(GL_LINES);                              
		glVertex2f(7.3*wh/120, 13.5*wh/20);
		glVertex2f(10.5*wh/120, 13.5*wh/20);
	glEnd();
}

void Render::draw_btn_solid_line()
{
	set_color(0, 0, 0);
	glBegin(GL_TRIANGLE_FAN);                          
		glVertex2f(1.3*wh/120, 12.5*wh/20);
		glVertex2f(5.3*wh/120, 12.5*wh/20);

		glVertex2f(5.3*wh/120, 12.55*wh/20);
		glVertex2f(1.3*wh/120, 12.55*wh/20);
	glEnd();
}

void Render::draw_btn_dotted_line()
{
	set_color(0, 0, 0);
	glBegin(GL_LINES);                              
		glVertex2f(7.3*wh/120, 12.5*wh/20);
		glVertex2f(8.1*wh/120, 12.5*wh/20);
		glVertex2f(8.4*wh/120, 12.5*wh/20);
		glVertex2f(9.0*wh/120, 12.5*wh/20);
		glVertex2f(9.3*wh/120, 12.5*wh/20);
		glVertex2f(9.9*wh/120, 12.5*wh/20);
		glVertex2f(10.2*wh/120, 12.5*wh/20);
		glVertex2f(10.8*wh/120, 12.5*wh/20);
	glEnd();	
}

void Render::draw_btn_vertex_increment()
{
	set_color(0, 0, 0);
	glBegin(GL_TRIANGLE_FAN);                         
		glVertex2f(1.3*wh/120, 11.4*wh/20);
		glVertex2f(3.1*wh/120, 11.7*wh/20);
		glVertex2f(4.9*wh/120, 11.4*wh/20);
	glEnd();
}

void Render::draw_btn_vertex_decrement()
{
	set_color(0, 0, 0);
	glBegin(GL_TRIANGLE_FAN);                         
		glVertex2f(7.0*wh/120, 11.7*wh/20);
		glVertex2f(9.0*wh/120, 11.4*wh/20);
		glVertex2f(10.6*wh/120, 11.7*wh/20);
	glEnd();	
}

void Render::draw_btn_show_size()
{
	drawstring(1.1*wh/120, 10.4*wh/20, 0.0, "size: ",0,0,0);
}

void Render::draw_btn_show_vertex()
{
	drawstring(1.3*wh/120, 9.4*wh/20, 0.0, "lados: ",0,0,0);
}

void Render::draw_btn_poligono()
{
	regularPolygon(6.0*wh/120, 8.5*wh/20,10);
}

void Render::draw_btn_background()
{
	palette(wh/30, 10.8*wh/30,2*wh/30, 10.8*wh/30, 2*wh/30, 11.8*wh/30, wh/30, 11.8*wh/30); 
}

void Render::regularPolygon(int x, int y, int radius)
{	  
	  double PI = 3.14;
      int xa[vertices],ya[vertices];
      double alfa = (2 * PI )/vertices;


      for (int a=0 ; a<vertices ; a++)
      {
           xa[a] = x + (radius * cos((a-1)*alfa));
           ya[a] = y + (radius * sin((a-1)*alfa));

      }

      for(int a=0;a<vertices;a++)
      {
        if(a==vertices-1)
        {
        	glBegin(GL_LINES);
				glVertex2f(xa[a],ya[a]);
				glVertex2f(xa[0],ya[0]);
			glEnd();
        }
        else
        {
        	glBegin(GL_LINES);
				glVertex2f(xa[a],ya[a]);
				glVertex2f(xa[a+1],ya[a+1]);
			glEnd();
        }
      }

}	


void Render::draw_size()
{
	string s;
	stringstream out;
	out << size;
	s = out.str();
	drawstring(7.0*wh/120, 10.4*wh/20, 0.0, s,0,0,0);
}

void Render::draw_vertex()
{
	string ss;
	stringstream out2;
	out2 << vertices;
	ss = out2.str();
	drawstring(8.0*wh/120, 9.4*wh/20, 0.0, ss,0,0,0);	
}

void Render::increment_vertex()
{	
	if(vertices == 8)
		vertices = 8;
	else
		vertices++;
}

void Render::decrement_vertex()
{
	if(vertices == 5)
		vertices = 5; 
	else
		vertices--;
}

void Render::increment_size()
{
	size++;
}

void Render::decrement_size()
{
	if(size == 1)
		size = 1;
	else
		size--;
}
/*
void Render::draw_lines(float a1, float a2, bool punteada)
{
	if(punteada)
	{
	glLineStipple(3,0xeeee);  
	glEnable(GL_LINE_STIPPLE);
	glLineWidth(size);
	glBegin(GL_LINE_STRIP);
		glVertex2f(a2, b2);
		glVertex2f(a1, b1);
	glEnd();
	}
	else
	{
		glLineWidth(size);
		glBegin(GL_LINES);
			glVertex2f(a2, b2);
			glVertex2f(a1, b1);
		glEnd();
	}
	reset();
}

void Render::draw_triangle(float a1, float a2, float a3, float b1, float b2, float b3, int m)
{
	glLineWidth(size);
	glBegin(GL_LINE_LOOP);
		glVertex2f(a3, b3);
		glVertex2f(a2, b2);
		glVertex2f(a1, b1);
	glEnd();
	m++;
	a[m][0]=a3;
	a[m][1]=b3;
	m++;
	a[m][0]=a2;
	a[m][1]=b2;
	m++;
	a[m][0]=a1;
	a[m][1]=b1;
	m++;
	a[m][0]='$';
	a[m][1]='$';
	reset();
}

void Render::draw_rectangle(float a1, float a2, float b1, float b2, int m)
{
	glLineWidth(size);
	glBegin(GL_LINE_LOOP);
		glVertex2f(a2, b2);
		glVertex2f(a1, b2);
		glVertex2f(a1, b1);
		glVertex2f(a2, b1);
	glEnd();
	m++;
	a[m][0]=a2;
	a[m][1]=b2;
	m++;
	a[m][0]=a1;
	a[m][1]=b2;
	m++;
	a[m][0]=a1;
	a[m][1]=b1;
	m++;
	a[m][0]=a2;
	a[m][1]=b1;
	m++;
	a[m][0]='$';
	a[m][1]='$';
	reset();
}
*/

void Render::lineaPunteada(bool punteada)
{
	this->punteada = punteada;	
	cout << punteada << endl;
}