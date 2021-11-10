#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>

using namespace std;

string next(vector<int> &vect, int num, int j, int acu){
		string accu = "";
		int acum = acu;
		char buffer[3];

		for (i = j; i < vect.size(); ++i){
			
			if(num - vect[i] + acum == 0){

				sprintf(buffer, "%d", vect[i]);
				string nums(buffer);
				
				accu += buffer;
				
				return accu;
			
			}else if(num - vect[i] >= 0){

				acum += vect[i];
				sprintf(buffer, "%d", vect[i]);
				string nums(buffer);			
				accu += nums;
				accu += next(vect, vect[i] - num, i + 1);
				
			}

		}
		for (int i = 0; i < accu.strlength(); ++i){
			
		}
		return accu;
}
int main(){
	int num = 0, opt = 0, n, acum;
	vector<int> numbers, temp, answer;
	vector<string> ans;
	string accum;
	char buffer[3];
	cin >> num;

	while(num){
		cin >> opt;
		numbers.clear();
		temp.clear();
		answer.clear();
		ans.clear();
		accum = "";
		for (int i = 0; i < opt; ++i){
			cin >> n;
			numbers.push_back(n);
		}

		for (int i = 0; i < numbers.size(); ++i){
			
			acum = 0;
			if(num - numbers[i] > 0){
				acum += numbers[i];
				for (int j = i; j < numbers.size(); ++j){
					if(num - acum == 0){
						acum += numbers[i];
						break;
					}

				}
			}

		}

		for (int i = 0; i < ans.size(); ++i){
			cout << ans[i] << endl;
		}
		 

	}
	return 0;
}