#include <stdio.h>
int nbrDiv(int n){
	int somme=0;
	for(int i=1; i<=n; i++){
		if(n%i==0)
			somme += i;
	}
	return somme;
}
int main(void){
	int n, m;
	printf("Entrer deux nombres: \n");
	scanf("%d %d",&n, &m);
	if(nbrDiv(n)==nbrDiv(m))
		printf("%d et %d sont des nombres amies\n",n,m);
	else
		printf("%d et %d ne sont pas des nombres amies\n",n,m);
	return 0;
}
