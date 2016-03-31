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
	int wh;
	int ww;
	int wx;
	int wy;
	int wx1;
	int wy1;
	void *currentFont;
	
//
	int size;
	int fill;
	int flag, flag1;
	float a1, a2, a3, b1, b2, b3;
	float a[100][2], b[100][2];
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
	//colorbutton
	void palette(float, float,float,float,float,float,float,float);
	void edgedetect(float, float, float, float, int *, int *);
	void scanfill(int, int);
	void eraser(int, int);
	void paint(int, int);
	void detect_point(int, int, int, int);


	void plotpixels(float, float, float, float);
	void plotpixels1(float, float, float, float);
	
	void draw_toolbar();
	void draw_palette();
	void draw_toolbox();

	void draw_circle(float, float, float);
	
	void draw_pixel(float, float);
	void draw_pixel1(float, float);
	
	void drawpoint(int,int); 
	//Buttons
	void draw_btn_line();
	void draw_btn_circle(float, float, float);
	void draw_btn_triangle();
	void draw_btn_circle();
	void draw_btn_rectangle();
	void draw_btn_pencil();
	void draw_btn_eraser();
	void draw_btn_pencil2();
	void draw_btn_brush();
	void draw_btn_fill_color();
	void draw_btn_air_brush();
	void draw_btn_increment();
	void draw_btn_decrement();

	void increment_size();
	void decrement_size();

	//TEXT
	void drawstring(float,float,float,string,float,float,float);


	 /* to draw the COLOR PALETTE */

};

#endif