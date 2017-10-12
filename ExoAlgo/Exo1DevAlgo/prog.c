#include <stdio.h>

int somSousTab(int *Tab, int g, int d){
	int som = 0;
	for(int i=g; i<=d; i++)
		som += Tab[i];
	return som;
}
int somMax(int *Tab, int l){
	int max = Tab[0];
	for(int i=0; i<=l; i++){
		for(int j=i; j<=l; j++){
			if(somSousTab(Tab,i,j)>max){
				max = somSousTab(Tab,i,j);
				printf("max%d; i=%d; j=%d\n",max,i,j);
			}
		}
	}
	return max;
}
int main(void){
	int Tab[10] = {1,-1,0,40,1,2,-10,9,1,-40};
	int max = somMax(Tab, 9);
	printf("Le maximum sous somme de Tab est: %d\n",max);
	return 0;
}
