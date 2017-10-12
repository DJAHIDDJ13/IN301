#include <stdlib.h>
#include <stdio.h>

typedef struct {
	int taille;
	int tab[100];
} Tableau;

int alea(int n){
	return rand()%n;
}
void initAlea(Tableau *T){
	T->taille = 10;
	for(int i=0; i<T->taille; i++){
		T->tab[i] = alea(20);
	}
}
void affTab(Tableau T){
	for(int i=0; i<T.taille; i++)
		printf("%d ", T.tab[i]);
	printf("\n");
}
long int prodTab(Tableau T){
	int prod = 1;
	for(int i=0; i<T.taille; i++)
		prod *= T.tab[i];
	return prod;
}
int minTab(Tableau T){
	int min = T.tab[0];
	for(int i=1; i<T.taille; i++)
		if(min > T.tab[i])
			min = T.tab[i];
	return min;
}
void shift(Tableau *T){
	for(int i=T->taille-1; i>=0; i--)
		T->tab[i+1] = T->tab[i];
	T->taille ++;
	T->tab[0] = 0;
}
void triTab(Tableau *T){
	for (int i=0; i<T->taille-1; i++)
		for(int j=i+1; j<T->taille; j++)
			if(T->tab[i] > T->tab[j]){
				int a = T->tab[i];
				T->tab[i] = T->tab[j];
				T->tab[j] = a;
			}
}
void inserTab(Tableau *T, int t){
	int j = -1;
	for(int i=0; i<T->taille; i++)
		if(t > T->tab[i]){
			j = i;
			break;
		}
	j = 4;
	T->taille ++;
	for(int i=T->taille; i>j; i--)
		T->tab[i+1] = T->tab[i];
	T->tab[j+1] = t;
}
void invTab(Tableau *T){
	for(int i=0; i<(int)(T->taille/2); i++){
		int a = T->tab[i];
		T->tab[i] = T->tab[((int)T->taille) - i - 1];
		T->tab[((int)T->taille) - i - 1]= a;
		//printf("\nDEBUG: La taille est %d; i = %d; j = %d\n",T->taille, i, ((int)T->taille) - i - 1);
	}
}
void supEle(Tableau *T, int a){
	for(int i=a; i<T->taille; i++)
		T->tab[i] = T->tab[i+1];
	T->taille --;
}
void supAlea(Tableau *T){
	int a = alea(T->taille);
	supEle(T,a);
}
/*void supDou(Tableau *T){
	int k = 0;
	for(int i=T->taille-1; i>=0; i--){
		for(int j=i-1; j>=0; j--){
			if(T->tab[i] == T->tab[j]){
				supEle(T, j);
				k++;
			}
		}
	}
	T->taille -= k;
}*/
int main(void){
	printf("sizeof(Tableau) = %lu\n\n", sizeof(Tableau));

	int n;
	printf("Entrer un nombre n: ");
	scanf("%d", &n);
	printf("%d est un nombre aleatoire entre 0 et %d\n\n",alea(n), n);
	
	Tableau T;
	initAlea(&T);
	affTab(T);
	
	printf("Le produit du Tableau T est: %li\n", prodTab(T));
	
	printf("Le minimum du Tableau T est: %d\n", minTab(T));
	
	shift(&T);
	affTab(T);
	printf("\n");
	
	triTab(&T);
	affTab(T);
	
	int t;
	printf("Entrer un nombre pour l'inserer dans le tableau T: ");
	scanf("%d", &t);
	inserTab(&T,t);
	affTab(T);
	printf("\n");
	
	invTab(&T);
	affTab(T);
	printf("\n");
	invTab(&T);
	
	supAlea(&T);
	affTab(T);
	supAlea(&T);
	affTab(T);
	printf("\n");
	
	/*supDou(&T);
	affTab(T);
	printf("\n");*/
	return 0;
}
