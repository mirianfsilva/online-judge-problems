#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 200000
/* Kruskal_MST
Kruskal busca uma AGM para um grafo conexo com pesos.
Encontra um subset das arestas que forma uma árvore que inclui todos os vértices,
onde o peso total, dado pela soma dos pesos das arestas da árvore, é minimizado.
*/
int parent [MAX];

typedef struct Edge{ // estrutura que representa a aresta e o peso em um graf
  /* data*/
  int from; // inicio - de
  int to; // destino - para
  int weight; // peso
  //int index;
} Edge;

Edge E[MAX];

/*
typedef struct subset{ // Conjunto union-find
    struct subset *parent;
    int rank;
}subset;

subset *findparent(subset *a) { // OK
    if (a->parent==NULL) return a;
    else return (a->parent = findparent(a->parent));
}

void union(subset *p, subset *q) { // OK
    if (p->rank > q->rank) {
        q->parent = p;
    } else if (p->rank < q->rank) {
        p->parent = q;
    } else {
        p->parent = q;
        p->rank += 1;
    }
}

// FIND-SET(u) retorna um elemento representativo do conjunto que contém u.
// se dois vértices u e v pertencem à mesma árvore basta testar FIND-SET(u) e FIND-SET(v).
// Combinação das árvores : UNION
int findset(subset *subsets, int i){
    if (subsets[i].parent != i) // FAIL
        subsets[i].parent = findset(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void Union(subset *subsets, int x, int y){
    int p = findset(subsets, x);
    int q = findset(subsets, y);

    if (subsets[p].rank < subsets[q].rank) // if (p->parent > q->rank)
        subsets[p].parent = q;
    else if (subsets[p].rank > subsets[q].rank)
        subsets[q].parent = p;
    else {
        subsets[q].parent = p;
        subsets[p].rank++;
    }
}

Edge *CreateGraph(int v, int e){
    Edge *edges = malloc (e*sizeof(Edge));

    int from, to;
    int i;

    for (i=0; i < e; i++){
        scanf("%d %d %d", &from, &to, &edges[i].weight);

        if ( from > to) {
            edges[i].from = to;
            edges[i].to = from;
        }else {
            edges[i].from = from;
            edges[i].to = to;
        }
        edges[i].index = i;
    }
  return edges;
}

int Kruskal(Edge* G, int V, int E){
    int e = 0;
    int i = 0;
    int x,y;
    int count = 0;
    Edge result[V];

    qsort(G, E, sizeof(Edge),compara);

    subset *subsets = malloc( V * sizeof(subset));
    int v;

    for (v = 0; v < V; ++v){
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    //count = sizeof(subset)*E + sizeof(int)*(E-1);

    while (e < V - 1){
        Edge next_edge = G[i++];
        x = findset(subsets, next_edge.from);
        y = findset(subsets, next_edge.to);

        if (x != y){
            result[e++] = next_edge;
            //count += result[i].weight;
            Union(subsets, x, y);
        }
    }

    for (i = 0; i < e; ++i){
        count += result[i].weight;
        //printf("%d \n",result[i].weight);
        //printf("COUNT %d\t",count);
    }
    //printf("%d\n",count);
    return count;
    free (subsets);
}*/

int findparent(int x){ // encontra um elemento u no conjunto
  if(x == parent [x])
    return x;
  return parent [x] = findparent (parent[x]);
}

int comp(const Edge *x, const Edge *y){ // compara duas arestas de acordo com seus pesos
  //return (x->weight > y->weight);
  return (x->weight < y->weight) ?-1: (x->weight > y->weight);
}



int main(int argc, char *argv[]){

  int vert,edges; // m , n
  scanf ("%d %d",&vert, &edges);

  int i,full =0,count=0, kruskal =0;

  while ( vert != 0 && edges != 0){
    //kruskal = 0, full = 0, count = 0;
    for ( i = 0; i < vert; i++ )
      parent [i] = i;
        for (i = 0; i < edges; i++){
            scanf ("%d %d %d",&E[i].from,&E[i].to,&E[i].weight);
            count += E[i].weight;
        }
    
    qsort(E,edges,sizeof(Edge),comp); //ordenar

    for ( i = 0; i < edges; i ++){
      int x = findparent (E[i].from);
      int y = findparent (E[i].to);

      if ( x!= y){
        full +=E[i].weight;
        parent[x]=y;
      }
    }
    //int kruskal = 0;
    kruskal = (count - full);
    //printf("Total Cost of MST is:%d",(count - full));
    printf("%d\n",kruskal);
    kruskal = 0, full = 0, count = 0;
    scanf ("%d %d",&vert, &edges);
  }
  return 0;
}
