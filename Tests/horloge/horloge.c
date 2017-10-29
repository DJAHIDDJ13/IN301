#include <uvsqgraphics.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#define PI 3.1415926535
#define R 100

int main(){
	init_graphics(300, 300);
	fill_screen(noir);
	int i=0;
	while(i<1000){
		fill_screen(noir);
		
		int h = heure()%12;
		int m = minute();
		int s = (int) seconde();
		
		POINT center = {150, 150};
		POINT pH = {(int)(center.x + 0.8*R*cos(-(2*PI/12*h)+PI/2)) ,(int)(center.y + 0.8*R*sin(-(2*PI/12*h)+PI/2))};
		POINT pM = {(int)(center.x + 0.88*R*cos(-(2*PI/60*m)+PI/2)) ,(int)(center.y + 0.88*R*sin(-(2*PI/60*m)+PI/2))};
		POINT pS = {(int)(center.x + 0.92*R*cos(-(2*PI/60*s)+PI/2)) ,(int)(center.y + 0.92*R*sin(-(2*PI/60*s)+PI/2))};
		draw_circle(center, R, blanc);
		
		draw_line(center ,pH ,blanc);
		draw_line(center ,pM ,blanc);
		draw_line(center ,pS ,blanc);
		attendre(1000);
		i++;
	}
	exit(0);
}
