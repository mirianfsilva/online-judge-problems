#include<stdio.h>
#include<stdlib.h>
// Fibonacci, Quantas Chamadas? 1029 URI

int k=0, count=0;
int fib(long int n) {
    count++;
    if (n == 0 || n == 1){
    	k = k + n;
    	return n;
    }
    else{
    	return fib(n-1) + fib(n-2);
    }
}

int main(){
	int n,x,i;
	scanf("%d",&n);	
   	for(i = 0; i < n; i++){
        scanf("%d",&x);
        if( x>=1 && x<=39 ){
        	fib(x);
           	printf("fib(%d) = %d calls = %d\n",x,count-1,k);
            k=0;count=0;
        }
   	}
return 0;
}
