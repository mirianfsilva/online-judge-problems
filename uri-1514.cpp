#include <iostream>
#include <cstdbool>
#define MAX 100
using namespace std;

int n, m, tmp;
int matriz[MAX][MAX];

bool um(int matriz[MAX][MAX]){
  bool b = true;
  int l;
  for (int i = 0; i < n; ++i){
      l = 0;
      for (int j = 0; j < m; ++j)
        l += matriz[i][j];
      if(l == m)
        b = false;
   }
   return b;
}

bool dois(int matriz[MAX][MAX]){
   bool b = true, b1;
   tmp = 0;
   for (int i = 0; i < m; ++i){
      b1 = false;
      for (int j = 0; j < n; ++j)
         if(matriz[j][i] != 0)
            b1 = true;
      if(b1) tmp++;
   }
   if(tmp == m) return true;
   else return false;
}

bool tres(int matriz[MAX][MAX]){
   bool b = true;
   for (int i = 0; i < m; ++i){
      tmp = 0;
      for (int j = 0; j < n; ++j)
         tmp += matriz[j][i];
      if(tmp == n)
         b = false;
   }
   return b;
}

bool quatro(int matriz[MAX][MAX]){
   int tmp2 = 0;
   tmp = 0;
   for (int i = 0; i < n; ++i){
      tmp = 0;
      for (int j = 0; j < m; ++j)
         tmp += matriz[i][j];

      if(tmp > 0)
         tmp2++;
   }
   if(tmp2 == n) return true;
   else return false;
}

int main(){
   int c;
   while((cin >> n  >> m) && (n || m)){
      c = 0;
      for (int i = 0; i < n; ++i)
         for (int j = 0; j < m; ++j)
            cin >> matriz[i][j];

      if(um(matriz))    c++;
      if(dois(matriz))  c++;
      if(tres(matriz))  c++;
      if(quatro(matriz))c++;
    
      cout << c << endl;
   }

   return 0;
}
