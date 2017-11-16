#include <stdio.h>
int syr(int s, char c){
	int cmp = 0;
	while(s != 1){
		if(s%2)
			s = s*3 +1;
		else
			s = (int)(s / 2);
		if(c == 'o'){
			printf("%d [%d]\n", s, syr(s, 'n'));
		}
		cmp ++;
	}
	return cmp;
}
int main(void){
	int s;
	printf("Entrer un nombre: ");
	scanf("%d", &s);
	syr(s, 'o');
	printf("\n");
	printf("Le nombre d'iterations est: %d", syr(s, 'n'));
	return 0;
}
