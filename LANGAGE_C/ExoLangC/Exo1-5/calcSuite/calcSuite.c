#include <stdio.h>
#include <math.h>
double suite(int n){
	if(n == 1)
		return 1;
	return sqrt(n + suite(n-1));
}
int main(void){
	int n;
	printf("Entrer un nombre: ");
	scanf("%d", &n);
	double res = suite(n);
	printf("%g", res);
	return 0;	
}
