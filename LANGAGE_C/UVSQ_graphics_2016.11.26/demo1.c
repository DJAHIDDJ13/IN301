#include <uvsqgraphics.h>

int main () {
    init_graphics (800,600);
	affiche_auto_off();
	POINT p = {400,300};
	double res = 0;
	while(1){
		char c[100];
		sprintf(c,"%d", get_key());
		if(atoi(c) == 273)
			res *=32;
		else if(atoi(c) == 274)
			res --;
		else if(atoi(c) == 275)
			res = log(-1);
		else if(atoi(c) == 276)
			res *= -1;

		if(atoi(c) != -1 && c[0] != 27){
			char s[100];
			sprintf(s, "%g",res);
			fill_screen(blanc);
			aff_pol_centre(s, 25, p, noir);
			affiche_all();
		}
		else if(atoi(c) == 27)
			exit(0);
	} 

    exit(0);
}
