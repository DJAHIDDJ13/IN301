#include <uvsqgraphics.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_POINTS 120 //has to be multiple of three
#define PI 3.1415
const int width = 400, height = 400;
POINT lerp(POINT a, POINT b, float lerpAmount);
void drawVertices(POINT *vertices, int NBR_POINTS); 
int main(void){
	init_graphics(width, height);
	fill_screen(blanc);
	int radius = 50;
	//creating circle points
	POINT circlePoints[MAX_POINTS];
	for(int i=0; i<MAX_POINTS; i++){
		circlePoints[i].x = ((int)width/2) + cos(i    * (2*PI)/MAX_POINTS) * radius;
		circlePoints[i].y = ((int)width/2) +sin((i+1) * (2*PI)/MAX_POINTS) * radius;
		printf("%d; %d\n", circlePoints[i].x, circlePoints[i].y);
	}
	//draw circle using points
	drawVertices(circlePoints, MAX_POINTS);
	//creating triangle points
	POINT trianglePoints[MAX_POINTS];
	int pointsPerLine = MAX_POINTS/3;
	//main vertices
	trianglePoints[0] = circlePoints[0];
	trianglePoints[pointsPerLine-1] = circlePoints[pointsPerLine-1];
	trianglePoints[2 * pointsPerLine - 1] = circlePoints[2 * pointsPerLine - 1];
	//the rest
	for(int i=0; i<pointsPerLine; i++){
		trianglePoints[i] = lerp(trianglePoints[0], trianglePoints[pointsPerLine-1], (1/pointsPerLine) * i);
		printf("%d: (%d; %d)\n", i, trianglePoints[i].x, trianglePoints[i].y);
	}
	
	//drawing triangle using points
	//drawVertices(trianglePoints, pointsPerLine);
	wait_escape();
	return 0;
}

POINT lerp(POINT a, POINT b, float lerpAmount){
	POINT c;
	c.x = a.x + (lerpAmount * (b.x - a.x));
	c.y = a.y + (lerpAmount * (b.y - a.y));
	return c;
}

void drawVertices(POINT *vertices, int NBR_POINTS){
	for(int i=1; i<NBR_POINTS-1; i++){
		draw_line(vertices[i], vertices[i+1], noir);
	}
	draw_line(vertices[MAX_POINTS-1], vertices[0], noir);//last line (To fill the hole)
}
