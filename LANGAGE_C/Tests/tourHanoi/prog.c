#include <stdio.h>
#include <stdlib.h>

typedef struct liste{
	int val;
	struct liste* suiv;
} liste;

int hd(liste* l){
	if(l==NULL)
		exit(EXIT_FAILURE);
	return l->val;
}
liste* next(liste* l){
	if(l==NULL)
		return l;
	return l->suiv;
}
liste* insere(liste* l, int e){
	liste* m = (liste*) malloc(sizeof(liste*));
	m->suiv = l;
	m->val = e;
	return m;
}
_Bool estVide(liste* l){
	return l==NULL;
}
liste* creerListe(){
	return NULL;
}
liste* initPile(liste* p, int n){
	int i=n;
	while(i>0){
		p = insere(p, i);
		i--;
	}
	return p;
}
void affichePile(liste* p){
	if(p == NULL){
		printf("n\n");
		return;
	}
	while(p){
		printf("%d ", p->val);
		p = p->suiv;
	}
	printf("\n");
	
}
void affichePiles(liste* p[3]){
	for(int i=0; i<3; i++)
		affichePile(p[i]);
}
passerEle(liste* p[3], int p, int g){
	if(p<0||p>2  ||  g<0 || p>2){
		fprintf("Unauthorized ")
	}
}
int main(int argc, char *argv[]){
	
	if(argc != 2 || atoi(argv[1]) == 0){
		fprintf(stderr, "ARGUMENT ERROR\n");
		exit(EXIT_FAILURE);
	}
	int n = atoi(argv[1]);
	liste* p[3] = {creerListe(),creerListe(),creerListe()};
	p[0] = initPile(p[0], n);
	affichePiles(p);
	exit(EXIT_SUCCESS);
}
