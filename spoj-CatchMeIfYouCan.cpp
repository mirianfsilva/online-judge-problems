/* ----------------------------------------------
SEMANA 3 | Username: mirianfs | SPOJ.com | Problem CMIYC
O problema consiste em um jogo, em que dois jogadores devem andar em um poligono,
e cada um dos jogadores possui uma velocidade. (first possui velocidade x, second possui
velocidade 2x). Dada o tamanho do polígono, tenho que calcular a posição em que os dois jogadores
vão se encontrar, já que eles possuem velocidades diferentes. A velocidade e o caminho percorrido
pelos jogadores possui um padrão, tal que se o tamanho do poligono é divisível por 3, que é a soma
das velocidades dos dois jogadores então a saída é a distância dos dois do ponto de saída. 
---------------------------------------------- */
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#include <set>
using namespace std;

int main(){
	
	long long int t;
	long long int poligono; // test case
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> poligono;
		if(poligono%3 == 0){
			cout << poligono/3 << endl;
		}else {cout << 0 << endl;} 
	}	
	return 0;
}
