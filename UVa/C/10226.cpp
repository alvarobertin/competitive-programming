#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>
using namespace std;

int main(){
	string arbol;

	int cases;

	double perce, total;

	map<string, double> bosque;

	scanf("%d\n", &cases);

	while(cases--){

		bosque.clear();
		total = 0;

		while(getline(cin, arbol)){
			if(arbol == "")
				break;

			bosque[arbol] += 1;
			total++;

		}

		for (map<string, double>::iterator it = bosque.begin(); it != bosque.end() ; ++it){

			printf("%s %.4lf\n", (it->first).c_str(), ((it->second)/total)*100);
		}
		if(cases)
			cout << endl;
	}


	return 0;
}