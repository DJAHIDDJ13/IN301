#include <stdio.h>
int main(void){
	int x, y;
	printf("Entrer x: ");
	scanf("%d", &x);
	printf("Entrer y: ");
	scanf("%d", &y);
	
	int s=0;
	while(x!=1){
		if(x%2==0){
			printf("%d x %d + %d",(int)(x/2),2*y,s);
			x/=2;
			y*=2;
		} else {
			printf("%d x %d + %d", x-1, y, s+y);
			x -= 1;
			s += y;
		}
		printf("\n");
		if(x==1)
			printf("%d", s+y);
	}
	printf("\n");
	return 0;
}
