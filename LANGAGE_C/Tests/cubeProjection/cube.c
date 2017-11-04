#include <uvsqgraphics.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#define PI 3.1415
typedef struct pt3d {
	double x,y,z;
} pt3d;

typedef struct cube{
	pt3d vertex[8];
} cube;

pt3d rotate(pt3d start, char axe, float theta);

int main(void){
	cube c;
	int index = 0;
	for(int i=0; i<2; i++){
		for(int j=0; j<2; j++){
			for(int k=0; k<2; k++){
				c.vertex[index].x = (double)i;
				c.vertex[index].y = (double)j;
				c.vertex[index].z = (double)k;
				index ++;
			}
		}
	}

	POINT n[8];
	for(int i=0; i<8; i++){
		n[i].x = c.vertex[i].x * 100+100;
		n[i].y = c.vertex[i].y * 100+100;
	}
	init_graphics(300, 300);
	fill_screen(blanc);

	while(1){		
		for(int i=0; i<8; i++){
			c.vertex[i] = rotate(c.vertex[i], 'x', 0.01);
		}
		for(int i=0; i<8; i++){
			c.vertex[i] = rotate(c.vertex[i], 'y', 0.01);
		}
		for(int i=0; i<8; i++){
			n[i].x = c.vertex[i].x * 100+100;
			n[i].y = c.vertex[i].y * 100+100;
		}
		int lines[12][2] = {{0,1},{0,2},{0,4},{1,3},{1,5},{2,3},{2,6},{3,7},{4,5},{4,6},{5,7},{6,7}};
		for(int i=0; i<12; i++){
			draw_line(n[lines[i][0]], n[lines[i][1]], noir);
		}
		attendre(10);
		fill_screen(blanc);
	}
	return 0;
}


pt3d rotate(pt3d start, char axe, float theta){
	pt3d end;
	if(axe == 'x'){
		end.x = start.x;
		end.y = start.y*cos(theta) - start.z*sin(theta);
		end.z = start.y*sin(theta) + start.z*cos(theta);
	}
	else if(axe == 'y'){
		end.x = start.z*sin(theta) + start.x*cos(theta);
		end.y = start.y;
		end.z = start.z*cos(theta) - start.z*sin(theta);
	}
	else if(axe == 'z'){
		end.x = start.x*cos(theta) + start.z*sin(theta);
		end.y = start.x*sin(theta) - start.z*cos(theta);
		end.z = start.z;
	}
	return end; 
}
