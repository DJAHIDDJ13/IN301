#include <stdio.h>
double ab(double n){
	if (n<0)return -n;
	return n;
}
int main(void){
	const double EPSILON = 0.01;
	double Sn = 0.0;
	double Sn1 = 1.0;
	int i = 2;
	
	while(ab(Sn1-Sn) >= EPSILON){
		Sn = Sn1;
		Sn1 += (double) 1/(i*i);
		i++;
		printf("Sn = %g;   Sn1 = %g\n",Sn,Sn1);
	}
	return 0;
}
