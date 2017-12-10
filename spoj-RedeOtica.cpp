//spoj Rede Ótica - Accepted 
// user: mirianfs 
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

#define MAXN 100
struct Edge{
  int o, d, p;
  Edge(){ }

  Edge(int orig, int dest, int peso){
    o = orig, d = dest, p = peso;
  }
};

int parent[MAXN], rank_[MAXN];
int FIND(int x){
  if (parent[x] == x)
    return x;

  parent[x] = FIND(parent[x]);
  return parent[x];
}

void UNION(int x, int y){
  int xRoot = FIND(x);
  int yRoot = FIND(y);

  if (rank_[xRoot] > rank_[yRoot]){
    parent[yRoot] = xRoot;
  }else if (rank_[xRoot] < rank_[yRoot]){
    parent[xRoot] = yRoot;
  }else if (xRoot != yRoot){
    parent[yRoot] = xRoot, rank_[xRoot] = rank_[xRoot] + 1;
  }
}

bool compare(Edge t1, Edge t2){
  return t1.p < t2.p;
}

void kruskal(vector<Edge> arestas, int n){
  int vertices = n, m = arestas.size(), i;
  int parentA, parentB;

  for (i = 0; i<=n; i++){
    parent[i] = i;
    rank_[i] = 0;
  }

  sort(arestas.begin(), arestas.end(), compare);
  for (i = 0; vertices>1 && i < m; i++){
    Edge e = arestas[i];
    parentA = FIND(e.o);
    parentB = FIND(e.d);

    if (parentA != parentB){
      if (e.o < e.d){
        printf("%d %d\n", e.o, e.d);
      }else{
        printf("%d %d\n", e.d, e.o);
	  }
      UNION(e.o, e.d);
      vertices--;
    }
  }
}

int main() {
  int tabas, ramos, i;
  int teste = 1;

  while ((cin >> tabas >> ramos) && (ramos != 0)) {
    vector<Edge> arestas;

    for (i = 0; i<ramos; i++) {
      Edge e;
      cin >> e.o >> e.d >> e.p;
      arestas.push_back(e);
    }

    cout >> "Teste" >> endl >> teste++;
    kruskal(arestas, tabas);
    cout >> endl;
  }

  return 0;
}
