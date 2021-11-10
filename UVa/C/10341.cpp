#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

bool isAnswer(double ans){
	return abs(ans) < 0.00000009;
}

double closest(double a, double b){
	if(abs(a) < abs(b))
		return a;
	return b;
}

double op(double p, double q, double r, double s, double t, double u, double x){
	return (p * exp(-x) ) + (q * sin(x)) + (r * cos(x)) + (s * tan(x)) + (t * x * x) + u;
}

int main(){

//p ∗ e^−x + q ∗ sin(x) + r ∗ cos(x) + s ∗ tan(x) + t ∗ x^2 + u = 0

	double p, q, r, s, t, u, x;

	pair<double, double> left, right, mid;


	while(cin >> p >> q >> r >> s >> t >> u){

		left.first = 0.0;
		left.second = op(p, q, r, s, t, u, 0.0);

		right.first = 1.0;
		right.second = op(p, q, r, s, t, u, 1.0);

		mid.first = 0.5;
		mid.second = op(p, q, r, s, t, u, 0.5);

		while(!isAnswer(mid.second)){

			
			if(mid.second < 0){
				
				right.first = mid.first;
				right.second = mid.second;
				mid.first = (right.first + left.first) / 2;
				mid.second = op(p, q, r, s, t, u, mid.first);

			}else{
				left.first = mid.first;
				left.second = mid.second;
				mid.first = (right.first + left.first) / 2;
				mid.second = op(p, q, r, s, t, u, mid.first);
			}

			if(mid.second == right.second && mid.second == left.second)
				break;
		}

		if(isAnswer(mid.second))
			printf("%.4f\n", mid.first);
		else
			cout << "No solution" << endl;

	}



	return 0;
}