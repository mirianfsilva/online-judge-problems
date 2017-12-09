#include <bits/stdc++.h>
#include <iostream>


using namespace std;

int main(){
    double valorAposta, valorPremio;
    int escolhido, sorteado, grupoE, grupoS;

    while ((cin >> valorAposta >> escolhido >> sorteado) && (valorAposta || escolhido || sorteado)){
        valorPremio = 0;
        if (escolhido%10000 == sorteado%10000){ //Milhar
            valorPremio = valorAposta*3000;
        }else if (escolhido%1000 == sorteado%1000){ //Centena
            valorPremio = valorAposta*500;
        }else if (escolhido%100 == sorteado%100){ //Dezena
            valorPremio = valorAposta*50;
        }else{ //Dezenas do mesmo grupo
            grupoE = escolhido%100;
            if (grupoE == 0){
                grupoE = 100;
            }
            grupoE = (grupoE-1)/4;

            grupoS = sorteado%100;
            if (grupoS == 0){
                grupoS = 100;
            }
            grupoS = (grupoS-1)/4;

            if (grupoE == grupoS){
                valorPremio = valorAposta*16;
            }
        }
        printf("%.2f\n", valorPremio); //2 casas decimais
    }
    return 0;
}
