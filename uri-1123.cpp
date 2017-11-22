/* ----------------------------------------------
Username: mirianfs | SPOJ.com | Probema: Desvio de Rota
O problema consiste em encontrar o caminho minimo em um grafo que é direcionado. 
Partindo de um vertice inicial a um final - posições do grafo que foi representado como uma matriz. 
Para encontrar a distância minima foi utilizado o algoritmo de Dijkstra, que visita todos os vertices
e retorna a menor distância de i até j. 

---------------------------------------------- */

#include <iostream>
#include <algorithm>
#include <vector>
#define max 255
#define INF 99999

using namespace std;

void Dijkstra(int GRAPH[max][max], int d[max], int n,int c,int K) {
    bool Free[n+3];
    
    int i=0,v=0;
    for ( i=c; i < n; i++) {
        Free[i] = true;
        d[i] = INF;
    }
    
    d[K] = 0;
    while (1) {
        int tot_ped_min = INF;
        int u = 0;
        for (i = c; i < n; i++)
            if (Free[i] && d[i] < tot_ped_min) {
                u = i; tot_ped_min = d[i];
            }
        if (u == 0) return;
        
        Free[u] = false;
        for ( v = c; v < n; v++)
            if (Free[v] && d[u]+ GRAPH[u][v] < d[v])
                d[v] = d[u] + GRAPH[u][v];
    }
}
 
int main() {
    int m=0,p=0,u=0,v=0;
    int c_est[max], d[max]; 
    int GRAPH[max][max];
    
    int n=0,c=0,K=0;
    while (cin >> n >> m >> c >> K) {
        if (!n && !m && !c && !K) 
            break;
        
        c_est[c-1]= 0;
        for (int i = 0; i < n; i++){
            for (int j = i; j < n; j++){
                GRAPH[i][j] = GRAPH[j][i] = INF;
            }
        }
        while (m--) {
            cin >> u >> v >> p;
            GRAPH[u][v] = GRAPH[v][u] = p;
        }
        
        for (int i = c-2; i >=0 ; i--){
            c_est[i] = c_est[i+1] + GRAPH[i][i+1];
        }
        
        Dijkstra(GRAPH,d,n,c,K);
        int result = INF;
        
        for (int i = c; i < n; i++)
            for ( int j = 0; j < c; j++)
                if (d[i] + c_est[j] + GRAPH[i][j] < result){
                    result = d[i] + c_est[j] + GRAPH[i][j];
                }
        cout << result << endl;
    }
    return 0; 
}
