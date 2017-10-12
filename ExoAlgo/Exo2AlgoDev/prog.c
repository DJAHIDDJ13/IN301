#include <stdio.h>
int maxUnimod(int *tab, int l){
	int g=0, d=l-1, m;
	while(d-g != 1){
		m = (g+d)/2;
		printf("m = %d; g = %d; d = %d\n",m,g,d);
		if(tab[m]>tab[m+1])
			d -= m;
		else
			g += m+1;
	}
	return tab[m];
}
int main(void){
	int tab[10] = {1,2,10,6,5,4,3,2,1,0};
	printf("Le maximum de tab est: %d\n", tab[maxUnimod(tab,10)]);
	return 0;
}
