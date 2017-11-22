#include <stdio.h>
#define MAX 1000 

int numero[MAX];
int temp,total;
int i,j,k;

int main(void) {
	// your code goes here

int n, m, num, dig;
  
    while(scanf("%d %d", &n, &m) != EOF){
    total = 0;
    for(i = n; i <= m; ++i){
    	dig = 0; num = i; // numero do digito = i 
        
        while (num > 0 || num != 0){
        	numero[dig] = num %10;
            num = num /10;
            dig++;
        }
        
        temp = 0; 
        for(j = 0; j < dig; j++)
            for(k = j + 1 ; k < dig;k++) 
            	if(numero[k] == numero[j])
               		temp = 1;
               		//break;
               	//else if (temp == 0)
               	//	total++;
               	//return;
               		
        if(temp == 0) 
            total++;       		
    }
    printf("%d\n",total);
    }
}
