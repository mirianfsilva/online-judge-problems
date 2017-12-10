/* ----------------------------------------------
Username: mirianfs | SPOJ | Problema: Encontre o Telefone

O programa consiste basicamente em transformar um conjunto de expressões em números.
Cada letra é correspondente à um número de acordo com o enunciado do problema. A solução
faz a verificação apenas com if's e retorna a entrada composta por letras em seus respectivos
números.
---------------------------------------------- */
#include <bits/stdc++.h>
#include <iostream>
#include <cstring>

using namespace std;

int main(){
    char teste;
    while (scanf("%c", &teste) !=EOF){
        if (65 <= teste && teste <= 67)
            cout << "2";
        else if (68 <= teste && teste <= 70)
            cout << "3";
        else if (71 <= teste && teste <= 73)
            cout << "4";
        else if (74 <= teste && teste <= 76)
            cout << "5";
        else if (77 <= teste && teste <= 79)
            cout << "6";
        else if (80 <= teste && teste <= 83)
            cout << "7";
        else if (84 <= teste && teste <= 86)
            cout << "8";
        else if (87 <= teste && teste <= 90)
            cout << "9";
        else
            cout << teste;
    }
	return 0;
}
