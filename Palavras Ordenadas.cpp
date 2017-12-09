#include <iostream>
#include <string>
// mirianfs
using namespace std;
int main(){
	int n;
	string s;

	cin >> n;

	while(n--){
		cin >> s;
		bool ord = true;
		for (int i = 0; i < s.size() - 1; ++i){
			if(tolower(s[i]) >= tolower(s[i+1])){
				ord = false;
				break;
			}
		}
		cout << s << ": ";
		if(ord)
			cout << "O" << endl;
		else
			cout << "N" << endl;
	}
}
