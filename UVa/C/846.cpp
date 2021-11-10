#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

double ope(double dif){
	return floor(sqrt(4*(dif-1) + 1));
}

int main(){

	int cases;
	double a, b, res;

	cin >> cases;

	while(cases--){

		cin >> a >> b;

		if( abs(a - b) == 0)
			cout << 0 << endl;
		else
			cout << ope(abs(b - a)) << endl;
	}

	return 0;
}