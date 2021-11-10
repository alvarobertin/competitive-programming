#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main() {


	int cases, l;
	char test[129], scas[2];
	string pal, zeros; 

	cin.getline(scas, 30);


	cases = atoi(scas);

	while(cases--){
		
		pal = "";

		cin.getline(test, 130);
		
		string pal(test);
		
		l = pal.length();
		
		zeros = "";

		for (int i = 0; i < l; ++i){
				zeros += '0';
		}

		for (int i = 0; i < l; ++i){
			if(pal[i] == ']'){
				
				for (int j = i; j >= 0; --j){
					if(pal[j] == '(' ){
						break;
					}
					else if(pal[j] == '[' ){
						pal[j] = '0';
						pal[i] = '0';
						break;
					}	
				}

			}
			else if(pal[i] == ')'){
				
				for (int j = i; j >= 0; --j){
					if(pal[j] == '['){
						break;
					}
					else if(pal[j] == '('){
						pal[j] = '0';
						pal[i] = '0';

						break;
					}	
				}

			}else if(pal[i] != '(' && pal[i] != '[' && pal[i] != ']' && pal[i] != ')'){
				pal[i] = '0';
			}
		}
	
		if(pal == zeros){
			cout << "Yes" << endl;
		}
		else{
			cout << "No" << endl;
		}
	}


	return 0;
}