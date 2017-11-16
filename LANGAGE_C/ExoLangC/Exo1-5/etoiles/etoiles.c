#include <stdio.h>
int main(void){
	int n=10;
	for(int i=n; i>=0; i--){
		for(int j=0; j<=i; j++){
			if(j!=i)
				printf("*");
		}
		if(i)
			printf("\n");
	}
	return 0;
}
