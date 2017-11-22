#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void invert (char *str){
int i;
for ( i = 0; i < strlen(str)/2; i++) {
    char temp = str[i];
    str[i] = str[strlen(str)-i-1];
    str[strlen(str) - i -1] = temp;
  }
}

int main(){

    int n, count = 0;
    char str[1001]; // minimo 
    scanf( "%d", &n);
    gets(str); // ler linha
 
    int i = 0; 
    while (i < n){
        int j=0;
        int alfabeto[26] = {0}; // vazio
        gets(str); // ler linha
 
        for(j= 0; str[j] != '\0'; j++){
        // isalpha retorna se é um caracter do alfabeto 
            if(isalpha(str[j])){str[j] = str[j] + 3;}
        }
        
        invert(str);
        // printf("%s\n",str);

        for ( j = strlen(str)/2; str[j] != '\0'; j++) { 
            str[j] = str[j] -1; 
        }

        printf ("%s\n",str); 
        i++;
    }
    return 0;
}
