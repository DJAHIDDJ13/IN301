#include <stdio.h>
#include <math.h>
#include <stdlib.h>
typedef struct Liste Liste;
struct Liste {
	int val;
	Liste *suiv;
};

Liste *creerListe(){
	return NULL;
}
_Bool estVide(Liste* l){
	return (l == NULL)?1:0;
}
Liste* insere(Liste* l, int element){
	Liste* m = malloc(sizeof(Liste*));
	m->val = element;
	m->suiv = l;
	return m;
}
Liste* next(Liste* l){
	if(!estVide(l))
		return l->suiv;
	return l;
}
int hd(Liste* l){
	return l->val;
}
void afficheListe(Liste* l){
	if(!l)
		printf("n\n");
	while(l){
		printf("%d ", hd(l));
		l=next(l);
	}
	printf("\n");
}
///////////////////
///L'ALGORITHME ///
///////////////////
Liste* cribleListe(int n){
	Liste *m = creerListe(), *l = creerListe();
	for(int i=n; i>=2; i--)
		l = insere(l, i);
	int i = 2;
	while(i <= sqrt(n)){
		for(int j=0; j<=i-2; j++){
			m = insere(m, hd(l));
			l = next(l);
		}
		i = hd(m);
		while(!estVide(l)){
			if(hd(l) % i)
				m = insere(m, hd(l));
			l = next(l);
		}
		while(!estVide(m)){
			l = insere(l, hd(m));
			m = next(m);
		}
		i++;
	}
	return l;
}

int* tabCrible(int n){
	int *tab = malloc(sizeof(int) * (n-1));
	for(int i=0; i<=n-2; i++)
		tab[i] = 1;
	int i = 0;
	while(i+2 <= sqrt(n)){
		while(tab[i] != 1)
			i++;
		int j = 2*(i + 1);
		while(j <= n){
			tab[j] = 0;
			j += i+2;
		}
		i++;
	}
	return tab;
}

int main(void){
	int n = 100;
	int *tab = tabCrible(n);
	Liste* l = cribleListe(n);
	afficheListe(l);
	return 0;
}
