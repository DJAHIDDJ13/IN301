 #include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Liste Liste;
struct Liste{
	int val;
	struct Liste *suiv;
};

Liste *creerListeVide();
_Bool estVide(Liste *l);
void affListe(Liste *l);
Liste *popLast(Liste *l);
Liste* popHead(Liste *l);
Liste *pushFirst(Liste *l, int val);
Liste *pushLast(Liste *l, int val);
int alea(int n);
_Bool estTri(Liste *l);
int nbrEle(Liste *l);
int recEle(Liste *l, int e);
Liste* supEle(Liste *l, int e);
Liste* catLis(Liste *l1, Liste *l2);
Liste* ajoutElementTriee(Liste *l, int element);
Liste* fusionListe(Liste* l1, Liste* l2);
Liste* swap(Liste *l, int a, int b);
Liste *triABulle(Liste *l);
int valI(Liste *l, int f);

int main(void){
	srand (time(NULL));
	Liste *l = creerListeVide();
	for(int i=0; i<5; i++) l = pushLast(l,alea(5));
	affListe(l);
	printf("%s",(estTri(l))?"\nl est triee\n":"\nl n'est pas triee\n");
	
	printf("\nLe nombre d'elements: %d\n\n", nbrEle(l));
	
	int al = alea(5);
	printf("Recherche de %d: %d\n\n", al, recEle(l, al));
	
	printf("Supression de cet element.\n");
	l = supEle(l,al);
	affListe(l);
	printf("\n");
	
	Liste *l2 = creerListeVide();
	for(int i=0; i<5; i++)
		l2 = pushLast(l2,alea(5));
	printf("L2: ");
	affListe(l2);
	printf("concatenation de l1 et l2:\n");
	l = catLis(l,l2);
	affListe(l);
	printf("\n");
	
	Liste *l1 = pushLast(pushLast(pushLast(creerListeVide(),1),2),4);
	printf("L1: ");
	affListe(l1);
	ajoutElementTriee(l1,5);
	printf("Apres l'ajout: ");
	affListe(l1);
	printf("\n");
	
	Liste *l3 = pushLast(pushLast(pushLast(creerListeVide(),1),2),4);
	printf("L3: ");
	affListe(l3);
	printf("Fusion de: ");
	affListe(l1);
	printf("et: ");
	affListe(l3);
	l1 = fusionListe(l1,l3);
	affListe(l1);
	printf("\n");
	
	printf("L: ");
	affListe(l);
	swap(l,1,2);
	printf("swap element 1 avec element 2: \n");
	printf("apres: ");
	affListe(l);
	
	printf("\ntri de cet liste: \n");
	l = triABulle(l);
	affListe(l);
	
	return 0;
}

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

Liste *popLast(Liste *l){
		Liste *cur = l;
		while(cur->suiv->suiv){
			cur = cur->suiv;
		}
		free(cur->suiv);
		cur->suiv = NULL;
		return l;
}

Liste* popHead(Liste *l){
	Liste *temp = l;
	l = l->suiv;
	free(temp);
	return l;
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
	m->suiv = malloc(sizeof(Liste*));
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
	while(l){
		if(e == l->val)
			return i;
		l=l->suiv;
		i++;
	}
	return -1;
}

Liste* supEle(Liste *l, int e){
	int rec = recEle(l,e);
	if(rec==-1) return l;
	else if(rec==0){
		l = popHead(l);
		return l;
	}
	Liste* temp = l;
	for(int i=0; i<rec-1; i++)
		temp = temp->suiv;
	temp->suiv = temp->suiv->suiv;
	return l;
}

Liste* ajoutElementTriee(Liste *l, int element){
	if(!estTri(l))
		return l;
	Liste* temp = l;
	while(temp->suiv->val < element && temp)
		temp = temp->suiv;
	if(temp == NULL)
		return pushLast(l, element);
	if(temp == l)
		return pushFirst(l, element);
		
	Liste* node = malloc(sizeof(Liste*));
	node->val = element;
	node->suiv = temp->suiv;
	temp->suiv = node;
	return l;
}
Liste* catLis(Liste *l1, Liste *l2){
	Liste *temp = l1;
	while(temp->suiv)
		temp = temp->suiv;
	temp->suiv = l2;
	return l1;
}

Liste* fusionListe(Liste* l1, Liste* l2){
	Liste *temp = creerListeVide();
	while(l1 && l2){
		if(l1->val < l2->val){
			temp = pushLast(temp, l1->val);
			l1 = l1->suiv;
		}
		else{
			temp = pushLast(temp, l2->val);
			l2 = l2->suiv;
		}
	}
	if(l1){
		temp = catLis(temp, l2);
	} else {
		temp = catLis(temp, l1);
	}
	return temp;
}

Liste* swap(Liste *l, int a, int b){
	int nbr = nbrEle(l);
	if(a>nbr || b>nbr)
		return l;
	if(a>b){
		int c = b;
		b=a;
		a=c;
	}
	int i = 0;
	Liste *temp = l;
	while(i<a ){
		temp = temp->suiv;
		i++;
	}
	Liste *pointA = temp;
	while(i<b){
		temp = temp->suiv;
		i++;
	}
	Liste *pointB = temp;
	int c = pointB->val;
	pointB->val = pointA->val;
	pointA->val = c;
	return l;
}

int valI(Liste *l, int f){
	int i=0;
	if(nbrEle(l) < f)
		exit(0);
	while(i<f){
		l=l->suiv;
	}
	return l->val;
}
Liste *triABulle(Liste *l){
	int nbr = nbrEle(l);
	_Bool f = 0;
	do{
		_Bool f = 0;
		for(int i=0; i<nbr; i++){
			if(valI(l,i-1) > valI(l, i)){
				l = swap(l, i-1, i);
				f = 1;
			}
		}
	}while(!f);
	return l;
}
