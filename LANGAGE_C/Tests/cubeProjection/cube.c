#include <uvsqgraphics.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
typedef struct pt3d {
	double x,y,z;
} pt3d;

typedef struct cube{
	pt3d a[8];
} cube;

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
int main(void){
	cube c;
	int index = 0;
	for(int i=0; i<2; i++){
		for(int j=0; j<2; j++){
			for(int k=0; k<2; k++){
				c.a[index].x = (double)i;
				c.a[index].y = (double)j;
				c.a[index].z = (double)k;
				index ++;
				printf("%d,%d,%d\n",i,j,k);
			}
		}
	}
	
	return 0;
}
