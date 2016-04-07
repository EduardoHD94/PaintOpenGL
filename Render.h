#ifndef RENDER_H
#define RENDER_H


#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

class Render
{ 
private:

public:	
	bool punteada;
	float a1, a2, a3, b1, b2, b3;
	float a[100][2], v[100][2];
	int fill;
	int flag, flag1;
	int r, g, b;
	int size, vertices;
	int wh;
	int ww;
	int wx1;
	int wx;
	int wy1; 
	int wy;
	void *currentFont;
	Render();
	~Render();
	int get_ww();
	int get_wh();
	void reset();
	void loop();
	void set_ww(int);
	void set_wh(int);
	void set_color(float, float, float);
	void set_color_background(float, float, float, float);
	void set_font(void *);
	void detect_point(int, int, int, int);
	void edgedetect(float, float, float, float, int *, int *);
	void eraser(int, int);
	void paint(int, int);
	void palette(float, float,float,float,float,float,float,float);
	void scanfill(int, int);

	void plotpixels(float, float, float, float);
	void plotpixels1(float, float, float, float);
	
	void draw_toolbar();
	void draw_palette();
	void draw_toolbox();
	void draw_circle(float, float, float);
	
	void draw_pixel(float, float);
	void draw_pixel1(float, float);
	void drawpoint(int,int); 
	//Botones dibujados en el toolbar
	void draw_btn_air_brush();
	void draw_btn_background();
	void draw_btn_brush();
	void draw_btn_circle();
	void draw_btn_circle(float, float, float);
	void draw_btn_decrement();
	void draw_btn_dotted_line();
	void draw_btn_eraser();
	void draw_btn_fill_color();
	void draw_btn_increment();
	void draw_btn_line();
	void draw_btn_pencil();
	void draw_btn_pencil2();
	void draw_btn_poligono();
	void draw_btn_rectangle();
	void draw_btn_show_size();
	void draw_btn_show_vertex();
	void draw_btn_solid_line();
	void draw_btn_triangle();
	void draw_btn_vertex_decrement();
	void draw_btn_vertex_increment();
	void draw_size();
	void draw_vertex();
	void regularPolygon(int, int, int);
	//Size
	void decrement_size();
	void increment_size();
	//Numero de vertices
	void decrement_vertex();
	void increment_vertex();
	//dibujar una cadena
	void drawstring(float,float,float,string,float,float,float);

	//Linea punteada
	void lineaPunteada(bool);

/*
	void draw_lines(float,float,bool);
	void draw_triangle(float,float,float,float,float,float,int);
	void draw_rectangle(float,float,float,float,int);
*/	


};

#endif