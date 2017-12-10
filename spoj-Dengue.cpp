/* ----------------------------------------------
Username: mirianfs | SPOJ.com | Problema DENGUE

O problema consiste em encontrar o menor caminho à um posto de vacinação. Para determinar em qual
vila deve ser instalada o posto, de tal forma que habitantes que tinham o maior custo, passem a ter 
o menor custo, foi utilizado o algoritmo de dijkstra. O mesmo vai calcular o caminho de um determinado vertice
até todos os vertices, essa distância é armazenada em uma fila de prioridades (que usa um heap), para retornar
o menor caminho de um vertice até todos os outros, o vertice que possuir a menor distância de todos os outros
é o mais adequado para a instalação do posto de vacinação.  
---------------------------------------------- */
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
#include <cstring>
#define MAX 100
#define INF 100000000

using namespace std;
/*  Floyd–Warshall algorithm same Dijstra, with negatives cyvles*/

int n, grafo[MAX][MAX], grau[MAX];
vector <int> dist(MAX);

void dijkstra(int source){
	for (int i = 0; i < n; i++){
		dist[i] = INF;
	}

	dist[source] = 0;
	priority_queue<pair<int, int> > heap;
	heap.push(make_pair(0, source));
	 
	while (!heap.empty()){
		int u = heap.top().second;
		heap.pop();
		for (int i = 0; i < grau[u]; i++){
			int v = grafo[u][i];
			int totalDist = dist[u] + 1;
			if (totalDist <= dist[v]){
				dist[v] = totalDist;
		    	heap.push(make_pair(totalDist, v));
			}
		}
	}
}

int main(){
	int v, u, t = 0;
	
	while ((cin >> n) && n!=0){
		int vila = INF;
		int path = INF;
		if (n == 0) break;

		for (int i = 0; i < n; i++)
			grau[i] = 0;
			for (int i = 1; i < n; i++){
				cin >> v >> u;
				grafo[v-1][grau[v-1]] = u-1;
				grau[v-1]++;
				grafo[u-1][grau[u-1]] = v-1;
				grau[u-1]++;
			}

		for (int i = 0; i < n; i++){
			dijkstra(i);
			int max = 0;
			for (int j = 0; j < n; j++){
				if (dist[j] > max)
					max = dist[j];
			}
			
			if (path > max){
				path = max;
				vila = i + 1;
			}
		}
		cout << "Teste " << ++t << endl << vila << endl << endl;
	}
	return (0);
}
