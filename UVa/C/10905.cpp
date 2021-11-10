#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;


bool compare(string a, string b){


	int la = a.length(), lb = b.length();


	int peque = min(la, lb);

	for (int i = 0; i < peque; ++i){
		if(a[i] != b[i]){
			return a[i] > b[i];
		}
	}

	for (int i = peque; i < max(la, lb); ++i){
		if(la > lb){
			if(a[i] != b[peque - 1])
				return a[i] > b[peque - 1];
		}
		else if(la < lb){
			if(b[i] != a[peque - 1])
				return b[i] > a[peque - 1];
		}
	}

	return true;
	
}

int main(){


	int T;
	vector<string> nums;
	string temp;

	cin >> T;

	while(T){

		nums.clear();


		for (int i = 0; i < T; ++i){
			cin >> temp;
			nums.push_back(temp);
		}

		sort(nums.begin(), nums.end(), compare);

		for (int i = 0; i < T; ++i){
			cout << nums[i];
		}
		cout << endl;
		cin >> T;
	}

	return 0;
}