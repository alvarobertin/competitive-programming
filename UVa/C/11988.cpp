#include <bits/stdc++.h>

using namespace std;

int main(){

	string entrada, acum;
	char change;
	list<string> res;

    while(cin >> entrada){
		res = list<string>();
		acum = "";
		change = ']';
		for (int i = 0; i < entrada.size(); i++){
			
			if(entrada[i] != '[' && entrada[i] != ']'){
				acum += entrada[i];
			}else{
				if(change == '['){
					res.push_front(acum);
					acum = ""; 
				}else{
					res.push_back(acum);
					acum = "";
				}
				change = entrada[i];
			}
		}
		if(change == '['){
			res.push_front(acum); 
		}else{
			res.push_back(acum);
		}
		for (list<string>::iterator it = res.begin(); it != res.end(); it++){
			cout << *it;
		}
		cout << '\n';
    }
    return 0;
}