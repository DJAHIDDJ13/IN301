#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct ListeC {
	char c;
	struct ListeC* suiv;
} ListeC;

ListeC* ajoutChaine(char *s, ListeC* l){
	if(strlen(s) == 0)
		return l;
	ListeC* append = malloc(sizeof(ListeC));
	append->c = s[strlen(s)-1];
	s[strlen(s)-1] = '\0';
	append->suiv = l;
	return ajoutChaine(s, append);
}
void afficherListe(ListeC* l){
	while(l){
		printf("%c",l->c);
		l = l->suiv;
	}
	printf("\n");
}
void remplitMot(int argc, char* argv[], char **t, ListeC** l){
		*t = malloc(sizeof(char) * strlen(argv[1]));
		strcpy(*t, argv[1]);

		*l = ajoutChaine(argv[2], *l);
}
int main(int argc, char *argv[]){
	if(argc == 3){
		char *chaine1;
		ListeC* chaine2;
		remplitMot(argc, argv, &chaine1, &chaine2);
		printf("chaine1: %s", chaine1);
		printf("\nchaine2: ");
		afficherListe(chaine2);
	}
	return 0;
}
