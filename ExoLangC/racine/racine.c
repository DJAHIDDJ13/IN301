#include <stdio.h>
#include <math.h>
double ab(double n){
	if(n>0)
		return n;
	return -n;
}
int main(void){
	int n;
	printf("Entrer un nombre: ");
	scanf("%d", &n);
	double g = 0.0;
	double d = (double) n;
	const double EPSILON = 0.001;
	double m = (g+d)/2;
	int i = 0;
	while(ab(m*m - n) > EPSILON && i<1000){
		m = (g+d)/2;
		if(m*m > n){
			d = m;
		} else {
			g = m;
		}
		i++;
	}
	printf("La racine de %d est: %g", n, m);
	return 0;
}
