#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

bool compare(int a, int b){
	int absA = abs(a), absB = abs(b);
	if(absA != absB){
		return absA < absB;
	}
	return false;
}


int main(){

	int p, F, temp, flag, count;

	vector<int> floors;


	cin >> p;

	while(p--){
		floors.clear();
		count = 0;
		cin >> F;

		for (int i = 0; i < F; ++i){
			
			cin >> temp;
			floors.push_back(temp); 	
		
		}

		sort(floors.begin(),floors.end(), compare);
		


		flag = floors[0];
		count = 1;
		if(!F){
			count = 0;
		}
		for (int i = 1; i < F; ++i){
			if(floors[i] > 0 && flag < 0){
				flag = 1;
				count += 1;
			}
			else if(floors[i] < 0 && flag > 0){
				flag = -1;
				count += 1;
			}
		}

		cout << count << endl;

	}

	return 0;
}
