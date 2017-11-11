#include <stdio.h>
#include <math.h>

int main(void){
	int n = 100;
	int tab[n-2];
	for(int i=0; i<=n-2; i++)
		tab[i] = 1;
	int i = 0;
	while(i+2 <= sqrt(100)){
		while(tab[i] != 1)
			i++;
		int j = 2*(i + 1);
		while(j <= n){
			tab[j] = 0;
			j += i+2;
		}
		i++;
	}
	for(int i=0; i<=n-2; i++)
		printf("%d: %d\n", i+2, tab[i]);
}
