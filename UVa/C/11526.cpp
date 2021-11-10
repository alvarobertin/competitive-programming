#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main(){

	int cases;
	long int n;
	double sq;
	bool igual;
	cin >> cases;
	while(cases--){

		cin >> n;
		igual = false;
		long long res = 0;
		long long int sq = sqrt(abs(n));

		vector<long long> vec;

		for( int i = 1; i <= sq + 1; i++){
			vec.push_back(n/i);
			if(n/i != sq)
				res += n/i;
			if(n/i == sq && i != sq + 1)
				igual = true;
		}

		for (int i = 0; i < vec.size() - 1; ++i){
			res += ((vec[i] - vec[i + 1]) * (i + 1));
		}
		if(igual)
			res -= vec.back();

		if(n <= 0)
			res = 0;

		cout << res << endl;
	}

	return 0;
}