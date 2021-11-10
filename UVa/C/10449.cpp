#include <bits/stdc++.h>

using namespace std;

int n, maxi;
vector<vector<pair<int, int> > > adj(50000);
vector<int> p(50000);
vector<int> d(50000);

void inicializar(int s){
  for(int i = 0; i < n; ++i){
    d[i] = INT_MAX;
    p[i] = -1;
  }

  d[s] = 0;
}

bool bellmanFord(int s){
  int i, j, k, v, peso;
  bool flag;
  
  inicializar(s);

  for(k = 0; k < n - maxi; ++k){
    flag = false;
    
    for(i = 0; i < n; i++){
      for(j = 0; j < adj[i].size(); ++j){
	v = adj[i][j].first;
	peso = adj[i][j].second;
	if(d[i] != INT_MAX && d[i] + peso < d[v]){
	  d[v] = d[i] + peso;
	  p[v] = i;
	  flag = true;
	}
      }
    }

    if(!flag)
      break;
  }

  for(i = 0; i < n; i++){
    for(j = 0; j < adj[i].size(); ++j){
      v = adj[i][j].first;
      peso = adj[i][j].second;
      if(d[i] != INT_MAX && d[i] + peso < d[v])
	return false;
    }
  }

  return true;
}
int main(){
    int m, i, aux1, aux2, peso, q, cases = 1;
    string line;

    while (cin >> n){
        maxi = 1;
        adj = vector<vector<pair<int, int> > >(5000);
        p = vector<int>(5000);
        d = vector<int> (5000);

        vector<int> bussynes;
        bussynes.push_back(0);
        for ( i = 0; i < n; i++){
            cin >> aux1;
            bussynes.push_back(aux1);
        }
        cin >> m;

        for(i = 0; i < m; i++){
            cin >> aux1 >> aux2;
            adj[aux1].push_back(make_pair(aux2, pow(bussynes[aux2] - bussynes[aux1], 3) ));
        }
        n++;
        bool flag = bellmanFord(1);
        maxi = -1;

        vector<int> d_og = d;

        bellmanFord(1);

        cin >> q;

        cout << "Set #" << cases++ << endl;
        for(i = 0; i < q; ++i){
            cin >> aux1;
            if(d[aux1] < 3 || d[aux1] == 2147483647 || d[aux1] != d_og[aux1])
                cout << "?" << endl;
            else
                cout << d[aux1] << endl;
        }
    }



    

return 0;
}
