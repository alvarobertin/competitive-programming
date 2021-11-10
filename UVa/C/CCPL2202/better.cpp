#include <bits/stdc++.h>

#define vi vector<int>

using namespace std;

vector<vi> res;

void back1(vi lista, int i, vi acum, int lim){
	if(acum.size() == 3){
		if(lista[acum[2]] - lista[acum[0]] <= lim)
			res.push_back(acum);

		return;
	}

	if(i == lista.size()) return;

	back1(lista, i + 1, acum, lim);
	acum.push_back(i);
	back1(lista, i + 1, acum, lim);
}

int main(){
	int n, g, d;
	vi lista, acum;

	cin >> n >> d;

	while(n || d){
		res.clear();
		lista.clear();
		acum.clear();

		for (int i = 0; i < n; ++i){
			cin >> g;
			lista.push_back(g);
		}

		sort(lista.begin(), lista.end());
		
		back1(lista, 0, acum, d);

		sort(res.begin(), res.end());
		for (int i = 0; i < res.size(); ++i){
			for (int j = 0; j < 3; ++j){
				cout << res[i][j] << " ";
			}
			cout << '\n';
		}

		cin >> n >> d;
	}

	return 0;
}