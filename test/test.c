#include <stdio.h>
#include <stdlib.h>

int main(void){
	FILE *f;
	f = fopen("test.c","r");
	if(!f){
		printf("ERROR!\n");//TEST
		exit(1);
	}
	printf("TEST.C:\n");
	char c = 1;
	const int LIMIT = 20000;
	int i = 0;
	while(i<LIMIT){
		c = fgetc(f);//TEST
		if(c!=EOF)
			printf("%c",c);
		else
			break;
		i++;
	}
	fclose(f);
	return 0;
}
//HAHAHHAHHAHHAH7
