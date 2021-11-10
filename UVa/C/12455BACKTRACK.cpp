#include <bits/stdc++.h>

using namespace std;


bool back(vector<int>& bars, int index, int n, int acum){
	if(acum == n) return true;
	if(acum > n) return false;
	if(index == bars.size() ) return false;

	return back(bars, index + 1, n, acum) || back(bars, index + 1, n, acum + bars[index]);
	
}



int main(){

	int t, n, p, b;

	cin >> t;



	while(t--){

		vector<int> bars;

		cin >> n >> p;

		for (int i = 0; i < p; ++i){
			cin >> b;
			bars.push_back(b);
		}

		int index = 0, acum = 0;

		if(back(bars, index, n, acum)){
			cout << "YES" << endl;
		}else{
			cout << "NO" << endl;
		}


	}




	return 0;
}