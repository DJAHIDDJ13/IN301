#include <stdio.h>
#include "circonference.h"
#include "surface.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char* argv[]){
	int r = atoi(argv[1]);
	if(argc !=2 || r < 0 || (!isdigit(argv[1][0]))){
		fprintf(stderr, "ARGUMENT ERROR \n\"%s\" is not a valid argument for principal!\n", argv[1]);
		exit(1);
	}
	printf("La circonference est: %g\n", circ(r));
	printf("La surface est: %g\n\n", surface(r));
	exit(0);
}
