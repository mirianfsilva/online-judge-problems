/* ----------------------------------------------
Username: mirianfs | SPOJ.COM | Problema: Mesa da Sra Montagny!

A resolução do problema, consiste em determinar se o grafo - nesse problema - representado como
uma matriz - se ele é bipartido. Ou seja, se para cada vertice, ele possui um correspondente do 
outro "lado da mesa", sendo assim vizihos. Para a solução foi implentada uma busca em largura (bfs)
para verificar os vizinhos de cada vertice, com o auxilio de uma fila. 
---------------------------------------------- */
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX 101
using namespace std;

int bfs(int g[MAX][MAX], int raiz, int n){
    vector <int> cor(n+1);
    for(int j=1; j<=n; j++) {
        cor[j] = 0;   
    }

    queue<int> fila;
    fila.push(raiz);
    cor[raiz] = 13;
    while(!(fila.empty())){
        int temp = fila.front();
        for(int j=1; j <= n; j++){
            if(g[temp][j] == 1){
                if(cor[j] == cor[temp])
                    return 0;
                if(cor[j] == 0){
                    cor[j] = cor[temp] * (-1);
                    fila.push(j);
                }
            }
        }
        fila.pop();
    }
    return 1;
}

int main(){
    ios_base::sync_with_stdio(false);
    int caso =1;
    int n=0, a=0,v=0, w=0;
    int g[MAX][MAX];
    
    while(cin>>n){   
        cin>>a; 
        cout<< "Instancia "<< caso << endl; caso++;
        for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) g[i][j] = 0;
        for(int i=0; i<a; i++){                           
            cin>>v>>w;
            g[v][w] = 1;
            g[w][v] = 1;
        }
        int temp = bfs(g, 1, n);
        if(temp==0) cout<<"nao"<<"\n\n";
        else cout<<"sim"<<"\n\n";
        }
    return 0;
}
