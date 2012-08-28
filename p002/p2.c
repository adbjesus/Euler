#include <stdio.h>
#include <stdlib.h>

#define MAX 4000000

int main(void){
	long int res=0;
	long int prev1=1,prev2=0;
	long int current=0;
	
	while((current=prev1+prev2) < MAX){
		if(current%2==0) res+=current;
		prev2 = prev1;
		prev1 = current;
	}
	printf("Res: %ld\n", res);
	return 0;
}


