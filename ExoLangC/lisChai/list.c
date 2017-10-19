#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Liste Liste;
struct Liste{
	int val;
	struct Liste *suiv;
};

Liste *creerListeVide(){
	return NULL;
}

_Bool estVide(Liste *l){
	return (l)?0:1;
}

void affListe(Liste *l){
	Liste *cur = l;
	while(cur){
		printf("%d ", cur->val);
		cur = cur->suiv;
	}
	printf("\n");
}

void pop(Liste *l){
		Liste *cur = l;
		while(cur->suiv->suiv){
			cur = cur->suiv;
		}
		free(cur->suiv);
		cur->suiv = NULL;
}

Liste *pushFirst(Liste *l, int val){
	Liste *m = malloc(sizeof(Liste));
	m->val = val;
	m->suiv = l;
	return m;
}
Liste *pushLast(Liste *l, int val){
	Liste *m = l;
	if(!m){
		return pushFirst(l,val);
	}
	while(m->suiv){
		m = m->suiv;
	}
	m->suiv = malloc(sizeof(Liste));
	m->suiv->val = val;
	m->suiv->suiv = NULL;
	return l;
}

int alea(int n){
	return rand()%n;
}

_Bool estTri(Liste *l){
	Liste *m = l;
	while(m->suiv){
		if(m->val > m->suiv->val)
			return 0;
		m = m->suiv;
	}
	return 1;
}
int main(void){
	srand ( time(NULL) );
	Liste *l = creerListeVide();
	for(int i=0; i<2; i++)
		l = pushLast(l,alea(5));
	affListe(l);

	if(estTri(l))
		printf("\nl est triee\n");
	else
		printf("\nl n'est pas triee\n");
	return 0;
}
