#include <stdio.h>
#include <math.h>
#include <time.h>
_Bool premier(long int n){
	if(n%2 == 0)
		return 0;
	for(long int i=3; i<=sqrt(n); i+=2)
		if (n%i==0)
			return 0;
	return 1;
}
int main(void){
	long int n;
	printf("Entrer un nombre: ");
	scanf("%li", &n);
	if(premier(n))
		printf("%li est premier.\n",n);
	else
		printf("%li n'est pas premier.\n",n);
	return 0;
}
