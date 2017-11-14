#include <stdio.h>
#include <stdlib.h>

typedef struct liste{
	int val;
	struct liste* suiv;
} liste;
typedef struct{
	liste* l[3];
} han;
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
	int tab[100];
	int i=0;
	while(p){
		tab[i] = p->val;
		i++;
		p = p->suiv;
	}
	for(int j=i-1; j>=0; j--)
		printf("%d ", tab[j]);
	printf("\n");
	
}
void affichePiles(liste* p[3]){
	for(int i=0; i<3; i++)
		affichePile(p[i]);
	printf("\n");
}
liste** passerEle(liste* p[3], int s, int g){
	if(s<0||s>2  ||  g<0 || g>2){
		fprintf(stderr,"Unauthorized access g or p\n");
		exit(EXIT_FAILURE);
	}
	p[g] = insere(p[g], hd(p[s]));
	p[s] = next(p[s]);
	return p;
}
int other(int s, int g){
	if(s == 0){
		if(g == 1)
			return 2;
		else if(g == 2)
			return 1;
	} else if(s == 1){
		if(g == 0)
			return 2;
		else if(g == 2)	
			return 0;
	} else if(s == 2){
		if(g == 0)
			return 1;
		else if(g == 1)
			return 0;
	}
	return -1;
}
han hanoi(han p, int s, int g, int n){
	if(n == 0)
		return p;
	//printf("s = %d, g = %d, other()= %d\n",s,g,other(s,g));
	p = hanoi(p, s, other(s,g), n-1);
	affichePiles(p.l);
	passerEle(p.l, s, g);
	p = hanoi(p, other(s,g), g, n-1);
	return p;
}
int main(int argc, char *argv[]){
	if(argc != 2 || atoi(argv[1]) == 0){
		fprintf(stderr, "ARGUMENT ERROR\n");
		exit(EXIT_FAILURE);
	}
	han p;
	p.l[0] = creerListe();
	p.l[1] = creerListe();
	p.l[2] = creerListe();
	int n = atoi(argv[1]);

	p.l[0] = initPile(p.l[0], n);
	p = hanoi(p, 0, 2, n);
	affichePiles(p.l);
	clrscr();
	getchar();
	exit(EXIT_SUCCESS);
}
