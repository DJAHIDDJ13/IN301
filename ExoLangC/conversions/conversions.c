#include <stdio.h>
int main(void){
	int sec;
	printf("Entrer le nombre des secondes: ");
	scanf("%d", &sec);
	
	int h = sec/3600;
	sec %= 3600;
	int m = sec/60;
	sec %= 60;
	printf("%d seconde%c correspind a: ", sec+h*3600+m*60, (sec>1)?'s':' ');
	if(h>0)
		printf("%d heure%c ",h, (h>1)?'s':' ');
	if(m>0)
		printf("%d minute%c ",m, (m>1)?'s':' ');
	if(sec>0)
		printf("%d seconde%c\n",sec, (sec>1)?'s':' ');
	return 0;
}
