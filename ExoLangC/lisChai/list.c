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

void popLast(Liste *l){
		Liste *cur = l;
		while(cur->suiv->suiv){
			cur = cur->suiv;
		}
		free(cur->suiv);
		cur->suiv = NULL;
}

void popHead(Liste *l){
	l = l->suiv;
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

int nbrEle(Liste *l){
	int cmpt = 1;
	while(l->suiv){
		cmpt++;
		l=l->suiv;
	}
	return cmpt;
}

int recEle(Liste *l, int e){
	int i = 0;
	while(l->suiv){
		if(e == l->val)
			return i;
		l=l->suiv;
		i++;
	}
	return -1;
}

int supEle(Liste *l, int e){
	int rec = recEle(l,e);
	if(rec==-1) return 0;
	else if(rec==0)popHead(l);
	for(int i=0; i<rec-1; i++)
		l = l->suiv;
	l->suiv = l->suiv->suiv;
	return 0;
}
int main(void){
	srand (time(NULL));
	Liste *l = creerListeVide();
	//for(int i=0; i<5; i++) l = pushLast(l,alea(5));
	l=pushLast(pushLast(l,0),1);
	affListe(l);
	printf("%s",(estTri(l))?"\nl est triee\n":"\nl n'est pas triee\n");
	
	printf("\nLe nombre d'elements: %d\n\n", nbrEle(l));
	
	int al = 1;
	printf("Recherche de %d: %d\n\n", al, recEle(l, al));
	
	printf("Supression de cet element.\n");
	supEle(l,al);
	affListe(l);
	printf("\n");
	return 0;
}
