/* ----------------------------------------------
Username: mirianfs | SPOJ.com | Problema: Pedido de Desculpas
---------------------------------------------- */

#include <iostream>
#include <vector>
using namespace std;

int max (int a,int b){
  return (a > b) ? a : b;
}

int calcula(int Nfrases, int pesos[], int valores[], int tamCartao){
  int desc[Nfrases + 1][tamCartao + 1];

  for (int i = 0; i <= tamCartao; i++){
    desc[0][i] = 0;
  }
  
  for (int i = 0; i <= Nfrases; i++){
    desc[i][0] = 0;
  }

  for (int i = 1; i <= Nfrases; i++){
    for (int j = 0; j <= tamCartao; j++){
      desc[i][j] = desc[i - 1][j];
      if ((j - pesos[i]) >= 0){
        desc[i][j] = max(desc[i][j], desc[i-1][j-pesos[i]] + valores[i]);
      }
    }
  }
  return desc[Nfrases][tamCartao];
}

int main(){
  int tamCartao, Nfrases, pesos[51], valores[51];
  int teste = 1;

  while (cin >> tamCartao >> Nfrases && (tamCartao && Nfrases)) {
    for (int i = 1; i <= Nfrases; i++){
      cin >> pesos[i] >> valores[i];
    }
    cout << "Teste " << teste << endl << calcula(Nfrases, pesos, valores, tamCartao) << endl << endl;
    teste++;
  }
  return 0;
}
