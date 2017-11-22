#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    int n, count = 0;
    char str[1001]; // minimo 
    scanf( "%d", &n);
    gets(str); // ler linha

    int i = 0; 
    while (i<n){
    	int j=0;
        int alfabeto[26] = {0}; // vazio
        gets(str); // ler linha

        for(j= 0; str[j] != '\0'; j++){ //percorrer toda a linha
        // isalpha retorna se é um caracter do alfabeto 
            if( isalpha(str[j]) && alfabeto[str[j] - 'a'] == 0 ){
                // caracter 'a' na tabela ASCII = 97 
                alfabeto[str[j] - 'a'] = 1; // alfabeto[str[j]] - 97 tbm dá 
                count++;
            }
        }
        
        if(count == 26 ){printf("%s\n","frase completa");}
        else if(count >= 13 ){printf("%s\n","frase quase completa");}
        else if(count < 13){printf("%s\n","frase mal elaborada");}
        count = 0;
        i++;
    }
    system ("pause");
    return 0;
}
