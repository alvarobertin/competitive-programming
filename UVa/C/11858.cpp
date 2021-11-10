#include <iostream>
#include <vector>
#include <algorithm>
/*

	NO ESTA HECHO


*/
using namespace std;


bool compare(int a, int b){
	cout << "d" << endl;
	if(a != b)
		return a < b;
	return false;
}



int main(){


	int n, temp;

	vector<int> vec;

	cin >> n;

	for (int i = 0; i < n; ++i){
		cin >> temp;
		vec.push_back(temp);
	}


	sort(vec.begin(), vec.end(), compare);




	return 0;
}