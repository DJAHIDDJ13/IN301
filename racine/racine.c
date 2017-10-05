#include <stdio.h>
#include <math.h>
double ab(double n){
	if(n>0)
		return n;
	return -n;
}
int main(void){
	int n;
	printf("Entrer un nombre n: ");
	scanf("%d", &n);
	const double EPSILON = 0.01;
	double d = 0;
	double f = (double) n;
	double m = (d+f)/2;
	while(m*m<n-EPSILON || m*m>n-EPSILON){
		if (m*m>n)
			f = m;
		else
			d = m;
		m = (d+f)/2;
	}
	printf("%g", m);
	return 0;
}
