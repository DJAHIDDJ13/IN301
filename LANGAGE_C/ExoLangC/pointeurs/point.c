#include <stdlib.h>
#include <stdio.h>
void perm(int *a, int *b){
	int c = *a;
	*a = *b;
	*b = c;
}
void reinitPointeur(int **p){
	*p = (int*) NULL;
}
int main(void){
	printf("sizeof(char) = %lu\n", sizeof(char));
	printf("sizeof(int) = %lu\n", sizeof(int));
	printf("sizeof(double) = %lu\n", sizeof(double));
	printf("sizeof(char*) = %lu\n", sizeof(char*));
	printf("sizeof(void*) = %lu\n", sizeof(void*));
	printf("sizeof(int*) = %lu\n", sizeof(int*));
	printf("sizeof(double*) = %lu\n", sizeof(double*));
	printf("sizeof(int**) = %lu\n", sizeof(int**));
	printf("sizeof(int[10]) = %lu\n", sizeof(int[10]));
	printf("sizeof(char[7][3]) = %lu\n", sizeof(char[7][3]));
	printf("sizeof(int[]) = ca result a un error de compilation\n\n");
	
	char tab[10];
	printf("sizeof(tab) = %lu\n", sizeof(tab));
	printf("sizeof(tab[0]) = %lu\n", sizeof(tab[0]));
	printf("sizeof(&tab[0]) = %lu\n", sizeof(&tab[0]));
	printf("sizeof(*&tab) = %lu\n", sizeof(*&tab));
	printf("sizeof(*&tab[0]) = %lu\n\n", sizeof(*&tab[0]));

	char(*p)[10] = &tab;
	//*((*p)+10)
	printf("sizeof(p) = %lu\n", sizeof(p));
	printf("sizeof(*p) = %lu\n", sizeof(*p));
	printf("sizeof((*p)[2]) = %lu\n", sizeof((*p)[2]));
	printf("sizeof(&(*p)[2]) = %lu\n\n", sizeof(&(*p)[2]));
	
	int a = 10, b = 20;
	printf("avant: a = %d; b = %d\n", a, b);
	perm(&a,&b);
	printf("apres: a = %d; b = %d\n\n", a, b);
	
	a = 1;
	int* po = &a;
	reinitPointeur(&po);
	printf("po = %p; cette fonction reintialise les pointeurs\n", po);

	return 0;
}
