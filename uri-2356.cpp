/* ----------------------------------------------
Mírian Francielle - UFMG
Username: mirianfs 
---------------------------------------------- */
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <cstring>

using namespace std;

int main(){
	char str[102], dna[102];
	set <string> s; 

	while(cin >> str >> dna){
		//if(str.find(dna) == true) 
		bool temp = strstr (str, dna); 
		if(temp == true)
			cout << "Resistente" << endl;
		else
			cout << "Nao resistente" << endl;
	}
	return (0);
}
