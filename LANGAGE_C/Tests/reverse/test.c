#include <stdio.h>
#include <stdlib.h>
typedef struct Liste Liste;
struct Liste {
	int val;
	Liste *suiv;
};
void affListe(Liste* l){
	Liste* m = l;
	int f = 1;
	int s = (int) l;
	s%=1000;
	while(l && (l!=m || f == 1) && f<5){
		printf("%d->(%d)",s, l->val);
		l = l->suiv;
		if(l == m)
			printf("[c]");
		f ++;
		s = (int) l;
		s%=1000;
	}
	printf("\n");
}
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
Liste* inverse(Liste* l){
	if(estVide(l) || estVide(next(l)))
		return l;
	Liste* lres = inverse(next(l));
	printf("\nlres = ");
	affListe(lres);
	printf("\nl = ");
	affListe(l);
	l->suiv->suiv = l;
	printf("\nlres = ");
	affListe(lres);
	printf("\nl = ");
	affListe(l);
	l->suiv = NULL;
	printf("\nlres = ");
	affListe(lres);
	printf("\nl = ");
	affListe(l);
	return lres;
}

int main(void){
	Liste* l;
	l = insere(insere(insere(creerListe(),3),2),1);
	affListe(l);
	l = inverse(l);
	affListe(l);
	return 0;
}
