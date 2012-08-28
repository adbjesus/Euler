#include <stdio.h>
#include <stdlib.h>

long long int next_prime(long long int);
int is_prime(long long int);

int main(void){
	long long int n;
	long long int prime=2;

	printf("Factorization program\n");
	printf("Number: ");
	scanf("%I64d",&n);

	while(n!=1){
		if(n%prime==0){
			n=n/prime;
			printf("%I64d\n",prime);
		}
		else prime=next_prime(prime);
	}
	return 0;
}

long long int next_prime(long long int prime){
	if(prime==2) return 3;
	for(prime+=2;!is_prime(prime);prime+=2);
	return prime;
}

int is_prime(long long int prime){
	long long int i,tmp;
	for(i=3;1;i+=2){
		tmp=prime/i;
		if(tmp<i) return 1;
		else if(prime == tmp*i) return 0;
	}
	return 1;
}

