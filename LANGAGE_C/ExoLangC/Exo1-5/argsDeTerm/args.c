#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int main( int argc, char** argv){
	double somme = 0.0;
	for(int i=1; i<argc; i++){
		if(! isdigit(argv[i][0]))
			printf("%s peut etre negative\n", argv[i]);
		somme += atof(argv[i]);
	}
	printf("La somme des valeurs est: %g\n",somme);
		
	return 0;
}
