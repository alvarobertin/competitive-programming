#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

double d(pair<double, double> a, pair<double, double> b){
	return sqrt( (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second) );
}

int main(){
	int n;
	double x, y, min;
	pair<double, double> temp;
	vector< pair<double, double> > puntos; 	
	cin >> n;
	while(n){
		
		min = 10000;
		puntos.clear();

		for (int i = 0; i < n; ++i){
			cin >> x >> y;
			temp.first = x;
			temp.second = y;

			puntos.push_back(temp);
		}

		double res = 0;
		for (int i = 0; i < n; i++){

			for (int j = i + 1; j < n; j++){
				
				res = d(puntos[i], puntos[j]);				
				if(  res < min ){
					min = res;
				}
			}

		}

		if(min < 10000)
			printf("%.4f\n", min);
		else
			cout << "INFINITY" << '\n';

		cin >> n;
	}



	return 0;
}