/*

https://codeforces.com/problemset/problem/1030/A
*/

#include <iostream>

using namespace std;

int main(){

	int p, o;
	bool flag = true;

	cin >> p;

	while(p--){
		cin >> o;
		if(o)
			flag = false;
	}

	if(flag)
		cout << "EASY" << endl;
	else
		cout << "HARD" << endl;
	
	return 0;
}