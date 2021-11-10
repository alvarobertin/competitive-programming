#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <cstdio>
#include <cmath>

using namespace std;

bool comp(string pal){
	if(pal == "<" || pal == ">" || pal == "<=" || pal == ">=" || pal == "=") return true;
	return false;
}

double aprox(double x){
	x *= 10.0;
	x += 0.5;
	int y = (int) floor(x);
	return (double) y / 10.0;

}

int main(){

	int g, p;
	string ts, temp;
	double td, dsum;
	bool ans;

	vector<string> sum;

	map<string, double> parties;

	cin >> p >> g;

	for (int i = 0; i < p; ++i){
		cin >> ts >> td;
		parties[ts] = td;
	}

	for (int i = 1; i <= g; ++i){
		sum.clear();
		dsum = 0;

		cin >> temp;
		while(!comp(temp)){
			if(temp != "+")
				sum.push_back(temp);
			cin >> temp;
		}
		cin >> td;

		for (int k = 0; k < sum.size(); ++k)
			dsum += parties[sum[k]];

		dsum = aprox(dsum);
		td = aprox(td);

		if(temp == "<")
			ans = dsum < td;
		else if(temp == ">")
			ans = dsum > td;
		else if(temp == "<=")
			ans = dsum <= td;
		else if(temp == ">=")
			ans = dsum >= td;
		else
			ans = dsum == td;
		
	
		if(ans)
			printf("Guess #%d was correct.\n", i);
		else
			printf("Guess #%d was incorrect.\n", i);

	}

	return 0;
}