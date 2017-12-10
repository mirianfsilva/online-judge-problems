/* ----------------------------------------------
Username: mirianfs | SPOJ.com ! Probema: CONTAGEM - Não é Mais um Joguinho Canadense

O problema consiste em encontrar o caminho minimo em um grafo que é direcionado. 
Partindo de um vertice inicial a um final. O grafo foi representado como uma matriz estática passada por
parametro na função de caminho. Para encontrar a distância minima foi utilizado o algoritmo de Dijkstra, 
que visita todos os vertices e retorna a menor distância de i até j. 
---------------------------------------------- */

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main(){
  int tam, i;
  int teste = 1;
  long long int result = 0; //Pois envolve potência e como pode ter até 60 caracteres não cabe em formatos inferiores
  string str;

  while((cin >> str) && (!cin.eof())){
    tam = str.length();

    result = 0;
    for(int i = 0; i < tam; i++){
      if (str[i] == 'b') {
        result = result + ((long long int) pow(2, tam - i - 1));
      }
    }

    cout << "Palavra " << teste++ << endl;
    cout << result << endl << endl;
  }

  return 0;
}
