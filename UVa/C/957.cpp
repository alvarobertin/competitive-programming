#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>
using namespace std;

int main(){
	
	int Y, P, n, min, max, acum, res;

	vector<int> Popes;

	while(cin >> Y >> P){
		Popes.clear();
		max = 0;
		min = 0;

		for (int i = 0; i < P; ++i){
			cin >> n;
			Popes.push_back(n);
		}

		res = 0;
		int j;
		for (int i = 0; i < P; ++i){
			n = 1;
			acum = 1;
			
			for (j = i + 1; j < P; ++j){

				if(Popes[j] - Popes[i] + 1> Y){
					break;
				}else{
					acum = Popes[j] - Popes[i] + 1;
				}
				
				n++;
			}

			if(acum <= Y ){
				if(n > res){
					res = n;
					min = Popes[i];
					max = Popes[j - 1];
				}
			}
		}

		cout << res << " " << min << " " << max << endl;

		scanf("\n");

	}
	return 0;
}