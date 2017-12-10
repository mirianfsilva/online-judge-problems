/* ----------------------------------------------
Mírian Francielle da Silva - 2013048950
Username: mirianfs | SPOJ.com | Problema: Bits Trocados

---------------------------------------------- */

#include <iostream>
#include <vector>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	
	int x50, x10, x5, x1;
	int v, teste = 1;
	while(cin >>v && v){
		x50 = v/50;
		v = v%50;
		
		x10 = v/10;
		v = v%10;
		
		x5 = v/5;
		v = v%5;
		
		x1 = v;
		
		cout << "Teste "<< teste << endl;
		cout << x50 << ' '<< x10 << ' ' << x5 << ' '<< x1 << endl << endl; 
		teste++;
	}
	return 0;
}
