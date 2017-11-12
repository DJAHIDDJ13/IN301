#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void printArray(int *a, int len){
	printf("[");
	for(int i=0; i<len; i++){
		if(i==len-1)
			printf(" %d",a[i]);
		else
			printf("%d ,",a[i]);
	}
	printf("]\n");
}
		
int* Merge(int *L,int leftCount,int *R,int rightCount) {
	int i=0,j=0,k=0;
	int* A = malloc(sizeof(int) * (rightCount+leftCount));
	if(!A)
		exit(3);
	while(i<leftCount && j< rightCount) {
		if(L[i]  < R[j])
			A[k++] = L[i++];
		else 
			A[k++] = R[j++];
	}
	while(i < leftCount) 
		A[k++] = L[i++];
	while(j < rightCount) 
		A[k++] = R[j++];
	return A;
}
int* MergeSort(int *A,int n) {
	int mid,i, *L, *R;
	if(n < 2) 
		return A;

	mid = n/2;

	L = (int*) malloc(mid*sizeof(int)); 
	R = (int*) malloc((n- mid)*sizeof(int)); 
	if(!L || !R)
		exit(2);
	for(i = 0;i<mid;i++)
		L[i] = A[i];
	for(i = mid;i<n;i++) 
		R[i-mid] = A[i];

	L = MergeSort(L,mid);
	R = MergeSort(R,n-mid); 
	A = Merge(L,mid,R,n-mid);
	
    free(L);
    free(R);
    return A;
}

float Med2Tab(int *t1,int *t2, int taille1, int taille2){
	int s = taille1 + taille2;
	int *t = malloc(s * sizeof(int));
	t = Merge(t1,taille1,t2,taille2);
	float res;
	if(s%2)
		res = t[((int)s/2)+1];
	else
		res = (t[((int)s/2)-1] + t[((int)s/2)])/2.0;
	free(t);
	return res;
}

int alea(int n){
	return rand() % n;
}
int min(int a, int b) {
   return (a<b)?a:b;
}
int max(int a, int b) {
   return (a>b)?a:b;
}

float Med2TabLog(int *t1,int *t2, int taille1, int taille2){
	int s = taille1/2;
	float m1, m2;
	if(taille1%2){
		m1 = t1[s];
		m2 = t2[s];
	}
	else{
		m1 = (t1[s-1]+t1[s])/2.0;
		m2 = (t2[s-1]+t1[s])/2.0;
	}
	/*printArray(t1,taille1);
	printArray(t2,taille2);
	printf("m1 = %g; m2 = %g\n",m1,m2);*/
	if(taille1 == 2)
		return (max(t1[0],t2[0]) + min(t1[1],t2[1]))/2.0;
	if(taille1%2){	
		if(m1 == m2)
			return m1;
		else if(m1 > m2)
			return Med2TabLog(t1, t2+s, s+1, s+1);
		else
			return Med2TabLog(t1+s, t2, s+1, s+1);
	}else{
		if(m1 == m2)
			return m1;
		else if(m1 > m2)
			return Med2TabLog(t1, t2+s-1, s+1, s+1);
		else
			return Med2TabLog(t1+s-1, t2, s+1, s+1);
	}
}

int main(int argc, char* argv[]){
	srand(clock());
	int *t1, *t2;
	int n = atoi(argv[1]);

	if(argc != 2 || n<2)
		exit(1);

	t1 =(int*) malloc(sizeof(int) * n+1);
	t2 =(int*) malloc(sizeof(int) * n+1);
	if(!t1 || !t2)
		exit(1);
	int taille1=0, taille2=0;
	//initialization aleatoire de t1 et t2
	for(int i=0; i<n; i++){
		t1[i] = alea(1000);
		taille1++;
		t2[i] = alea(1000);
		taille2++;
	}
	//tri de t1 et t2
	printf("sorting t1 and t2 (taille = %d)\n", n);
	clock_t begin = clock();
	t1 = MergeSort(t1,taille1);
	t2 = MergeSort(t2,taille1);
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Time Taken to sort t1 and t2: %g s\n\n", time_spent);
	
	//median O(n)
	begin = clock();
	//printArray(t1, taille1);
	//printArray(t2, taille2);
	//printArray(Merge(t1,taille1,t2,taille2), taille2+taille1);
	printf("~~ Median of t1 and t2 using merge (fusion) is: %g\n", Med2Tab(t1,t2,taille1,taille2));
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Time Taken to calculate : %g s\n\n", time_spent);
	
	//median O(log(n))
	begin = clock();
	printf("~~ Median of t1 and t2 using dichotomy is: %g\n", Med2TabLog(t1,t2,taille1,taille2));
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Time Taken to calculate : %g s\n\n", time_spent);
	
	free(t1);
	free(t2);
	exit(1);
}
