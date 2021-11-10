#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cstdio>
#include <map>

using namespace std;


int main(){

	int T, N, temp, tank, start, count, cases = 1;
	bool flag;
	vector<int> avalible, needed;

	cin >> T;

	while(cases <= T){

		avalible.clear();
		needed.clear();
		tank = 0;
		start = 0;
		count = 0;
		flag = false;
		cin >> N;

		for (int i = 0; i < N; ++i){
			cin >> temp;
			avalible.push_back(temp);
		}

		for (int i = 0; i < N; ++i){
			cin >> temp;
			needed.push_back(temp);
		}


		for (int i = 0; i < N; ++i){	
			if(avalible[i] + tank >= needed[i]){
				tank = tank + avalible[i] - needed[i];
				count += 1;
				if(!flag){
				 	flag = true;
					start = i;
					count = 0;
				}
			}
			else{
				flag = false;
				tank = 0;
			}
		}

		for (int i = 0; i <= start; ++i){
			if(avalible[i] + tank >= needed[i]){
				tank = tank + avalible[i] - needed[i];
				count += 1;
				if(!flag){
				 	flag = true;
					start = i;
					count = 0;
				}
			}
			else{
				flag = false;
				tank = 0;
			}			
		}
		if(count == N){
			printf("Case %d: Possible from station %d\n", cases, start + 1);
		}
		else{
			printf("Case %d: Not possible\n", cases);
		}

		cases++;
	}

	return 0;
}
