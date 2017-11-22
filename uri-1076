#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// DESENHANDO LABIRINTOS

// N < X2, onde X é a largura em nodos do labirinto, que pode variar de 3 até 7 - GRAFO MÁXIMO 7x7

int G[49][49]; // tamanho maximo de um grafo-matriz
bool vert_visit[49]; // indicar se o vértice foi descoberto - máximo de vértices 49

// depth-first search recursivo que visita todos os vertices ligados
int dfs(int vert, int v) {
    int count = 0; // contador de visitas - movimentos feitos
    vert_visit[vert] = true; // marca v como visitado

    int i;
    for (i = 0; i < v; i++) {
        /* para cada vértice adjacente a v
        se v não for visitado realiza a busca
        recursivamente */
        if (G[vert][i] && !vert_visit[i]) {
            count += dfs(i, v) + 1;
        }
    }
    return count;
}

int main(int argc, char *argv[]){

int instancias;
int v,a; // vertices e arestas
int start;
int x, y; // vertices que serão conectados por uma aresta

    /*FILE *fin = fopen(argv[1], "r"); // "input.txt" - leitura
    FILE *fout = fopen(argv[2], "w"); // "output.txt" - escrita

    if(fin == NULL || fout == NULL) {
        printf("ERROR, FILE NOT FOUND.");
        return 0;
    }*/

    int k,i,j,l;
    scanf("%d",&instancias);
    for (k =0; k < instancias; k++){
        scanf("%d", &start); // vertice inical
        scanf("%d %d", &v, &a); // qntd vertices e arestas

        //Inicializa grafo todo com 0, nenhum vertice visitado
        // vert_visit = false
        for (i = 0; i < v; i++) {
            for (j = 0; j < v; j++) {
                G[i][j] = 0;
            }
            vert_visit[i] = false;
        }

        // grafo simples com arestas duplas de ida e volta
        for (l=0; l < a; l++) {
            scanf("%d %d", &x, &y);
            G[x][y] = 1;
            G[y][x] = 1;
        }
        printf("%d\n", dfs(start, v) * 2);
    }
    return 0;
}
