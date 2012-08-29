#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int is_palindrome(int);

int digits=1;

int main(void){
	int res=0,tmp,i,k;
	double min,max;
	printf("Digits: ");
	scanf("%d",&digits);
	if(digits<=0){
		printf("Must be at least 1 digit");
		return 0;
	}
	min=pow(10.0,digits-1);
	max=pow(10.0,digits);
	for(i=min;i<max;i++){
		for(k=min;k<max;k++){
			tmp=i*k;
			if(is_palindrome(tmp) && tmp>res) res=tmp;
		}
	}
    printf("RES: %d",res);
	return 0;
}

int is_palindrome(int n){
	char buf[digits*2];
    int d,i;

	sprintf(buf,"%d",n);
    d = strlen(buf);
	for(i=0;i<d/2;i++){
        if(buf[i]!=buf[d-i-1]) return 0;
    }
	return 1;
}


