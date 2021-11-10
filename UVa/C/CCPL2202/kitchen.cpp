#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define vpii vector<pair<int, int> >
#define endl "\n"

int main(){
	int n;
	while(cin >> n){
		vpii parejas;
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			if(y > x){
				int t;
				t = x;
				x = y;
				y = t;
			}
			pii par = make_pair(x, y);	
			parejas.push_back(par);
		}
		
		sort(parejas.begin(), parejas.end());
		vector<stack<pair<int, int> > > lista;
		stack<pair<int, int> > temp;
		temp.push(parejas[parejas.size() - 1]);
		lista.push_back(temp);
		int j;
		for(int i = parejas.size() - 2; i >= 0; i--){
			for(j = 0; j < lista.size(); j++){
				if(parejas[i].first <= lista[j].top().first && parejas[i].second <= lista[j].top().second){
					lista[j].push(parejas[i]);
					break;
				}
			}
			if(j == lista.size()){
				stack<pair<int, int> > temp1;
				temp1.push(parejas[i]);
				lista.push_back(temp1);
			}
		}
		cout << lista.size() << endl;
	}


	return 0;
}