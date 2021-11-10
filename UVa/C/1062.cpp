#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <stack>

using namespace std;

int main(){

	string pal;
	bool flag;
	vector< stack<char> > pila;
	int cases = 1;

	cin >> pal;
	
	while(pal != "end"){

		pila.clear();
		stack<char> temp;
		temp.push(pal[0]);
		pila.push_back(temp);
		temp.pop();

		for (int i = 1; i < pal.length(); ++i){
			flag = false;
			for (int j = 0; j < pila.size(); ++j){
				
				if(pal[i] <= pila[j].top()){
					pila[j].push(pal[i]);
					flag = true;
					break;
				}

			}
			if(!flag){
				temp.push(pal[i]);
				pila.push_back(temp);
				temp.pop();			
			
			}

		}

		printf("Case %d: %d\n", cases, pila.size());

		cin >> pal;
		cases++;
	}

	return 0;
}