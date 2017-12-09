/*---------------------
Problema Primo - SPOJ
----------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool primo(int n){
	int i = 2;

	while (i*i <= n){
	  if (n%i==0) return false;			
	    i++;				
	}
	return true;
}

int main(){
	int num, x;
	scanf("%d",&num);
	
	if(num <0) num = num*(-1);
	x = primo(num);

	if(x == false) printf("nao\n");
	else printf("sim\n");
	
return 0;
}
