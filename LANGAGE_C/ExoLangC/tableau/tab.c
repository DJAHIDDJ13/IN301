#include <stdio.h>
#include <stdlib.h>
#define N 10
int* initTab(int *T){
	for(int i=0; i<N; i++)
		T[i] = 1;
	return T;
}
int prodTab(int *T){
	int prod = 1;
	for(int i=0; i<N; i++)
		prod *= T[i];
	return prod;
}
int minTab(int *T){
	int min = T[0];
	for(int i=1; i<N; i++)
		if(min > T[i])
			min = T[i];
	return min;
}
int *shift(int *T){
	for(int i=0; i<N-1; i++)
		T[i+1] = T[i];
	T[0] = 0;
	return T;
}
void affTab(int *T){
	for(int i=0; i<N; i++)
		printf("%d ", T[i]);
	printf("\n");
}
int *inserTab(int *T, int t){
	int i=0;
	int j = -1;
	for(int i=0; i<N; i++)
		if(t > T[i]){
			j = i;
			break;
		}
	for(int i=j; i<N; i++)
}
int main(void){
	int *T = malloc(N*sizeof(int));
	initTab(T);
	affTab(T);
	
	printf("Le produit du Tableau T est: %d\n", prodTab(T));
	
	printf("Le minimum du Tableau T est: %d\n", minTab(T));
	
	shift(T);
	affTab(T);

	
	return 0;
}
