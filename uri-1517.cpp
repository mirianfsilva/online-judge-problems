/* ----------------------------------------------
Username: mirianfs | URI | Problema: Maças

O problema consiste em determinar a quantidade de maças que Rafael pode recocler, dada K maçãs disponíveis.
O espaço em que as maças são distribuidas é uma matriz MxN. Rafael pode andar por toda a matriz, e possui um
tempo que determina em qual posição ele está quando a maçã cair. Foi implementada uma função auxiliar que calcula
a distância de rafael dada as posições das maçãs. Um vetor guarda a quantidade de maçãs de acordo rafael recolhe.
Para determinar essa quantidade, dado o tempo mais a posição de rafael, se ela corresponde à uma posição em que uma
maçã irá cair, o vetor é atualizado, e ao final retorna a quantidade máxima que ele pode recolher da árvore. 
---------------------------------------------- */

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#define MAX 1001
using namespace std;
int N, M, K;

int x[MAX];
int y[MAX];
int t[MAX];
int resposta[MAX];

int dist(int p1, int p2){
	int dx = x[p1] - x[p2];
	int dy = y[p1] - y[p2];
	if(dx < 0) dx*=-1;
	if(dy < 0) dy*=-1;
	return dx < dy? dy : dx;
}

int main(){

	while(cin >> N >> M >> K && (N != 0 && M != 0 && K != 0)){
		for(int i = 1; i <= K; i++){
			cin >> x[i] >> y[i] >> t[i];
			resposta[i] = MAX;
		}

		cin >> x[0] >> y[0]; // posição do rafael 
		resposta[0] = -1;
		int max = -1;

		for(int i = K; i >= 0; i-- ){
			resposta[i] = 1;
			for(int j = i + 1; j <= K;j++ ){
				if( t[i] + dist(i,j) <= t[j] && resposta[i] < resposta[j] + 1 ) 
					resposta[i] = resposta[j] + 1;
			}
		}
		for(int i = 0; i <= K; i++)
			if(resposta[i] > max) 
				max = resposta[i];
		cout << resposta[0] -1 << endl;
	}
}
