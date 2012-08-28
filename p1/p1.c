#include <stdio.h>
#include <stdlib.h>

#define MAX 1000
#define MULT_SIZE 2

int mults[MULT_SIZE]={3,5};

int main(void){
	long int res=0;
	long int i,k;

	for(i=1;i<MAX;i++)
		for(k=0;k<MULT_SIZE;k++)
			if(i%mults[k]==0){res+=i;break;}
	printf("Sum: %ld\n",res);
	return 0;
}


