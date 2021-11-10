#include <bits/stdc++.h>

using namespace std;

int sum(vector<int> nums){
	int sum = 0;
	for (int i = 0; i < nums.size(); ++i){
		sum += nums[i];
	}
	return sum;
}

pair<int, int> mult(vector<int> nums){
	pair<int, int> ms;
	ms.first = 1;
	ms.second = 0;

	for (int i = 0; i < nums.size(); ++i){
		ms.first *= nums[i];
		ms.second += nums[i];
	}
	return ms;
}


int main(){

	int cases, n, t, steps, sum;

	cin >> cases;

	while(cases--){

		vector<int> nums;
		steps = 0;

		cin >> n;
		for (int i = 0; i < n; ++i){
			cin >> t;
			nums.push_back(t);
		}
		pair<int, int> ms;

		ms = mult(nums);
		
		while(!ms.first || !ms.second){
			ms = mult(nums);
			if(ms.first == 0){

				for (int i = 0; i < nums.size(); ++i){
					if(!nums[i]){
						nums[i]++;
						steps++; 
					}
				}

			}
			ms = mult(nums);
			if(ms.second == 0){
					
				for (int i = 0; i < nums.size(); ++i){
					if(nums[i] != -1){
						nums[i]++;
						steps++;
						break;
					}
					else if(i == nums.size() - 1){
						nums[i]++;
						steps++;
						break;	
					}
				}		
			}
			ms = mult(nums);
		}

		cout << steps << '\n';

	}

	return 0;
}