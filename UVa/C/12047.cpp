#include <climits>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int n;
vector<vector<pair<int, int> > > adj(11000), adjReves(11000), adjNormal(11000);
vector<int> p(11000);
vector<int> d(11000);

void inicializar(int s){
  for(int i = 0; i < n; ++i){
    d[i] = INT_MAX;
    p[i] = -1;
  }

  d[s] = 0;
}

void dijkstra(int s){
  int i, j, k, u, v, peso, costo;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > cola;
  
  inicializar(s);
  cola.push(make_pair(0, s));

  while(!cola.empty()){
    costo = cola.top().first;
    u = cola.top().second;
    cola.pop();

    if(costo == d[u]){
      for(j = 0; j < adj[u].size(); ++j){
	v = adj[u][j].first;
	peso = adj[u][j].second;
	if(d[u] != INT_MAX && d[u] + peso < d[v]){
	  d[v] = d[u] + peso;
	  p[v] = u;
	  cola.push(make_pair(d[v], v));
	}
      }
    }
  }
}

int main(){
    int m, i, aux1, aux2, peso, cases, s, t, P, r;
    vector<int> dReves(11000), dNormal(11000);

    cin >> cases;

    while(cases--){
        adjReves = vector<vector<pair<int, int> > >(11000);
        adjNormal = vector<vector<pair<int, int> > >(11000);
        cin >> n >> m >> s >> t >> P;
        s = s - 1;
        t = t - 1; 
        r = 0;

        for(i = 0; i < m; i++){
            cin >> aux1 >> aux2 >> peso;
            adjNormal[aux1-1].push_back(make_pair(aux2-1, peso));
            adjReves[aux2-1].push_back(make_pair(aux1-1, peso));
        }

        adj = adjReves;
        dijkstra(t);
        dReves = d;
        
        adj = adjNormal;
        dijkstra(s);
        dNormal = d;

        
        for (int i = 0; i < n; i++){
            for (int j = 0; j < adjNormal[i].size(); j++){
                aux1 = i;
                aux2 = adjNormal[i][j].first;
                peso = adjNormal[i][j].second;
                if(dNormal[aux1] != INT_MAX && dReves[aux2] != INT_MAX) {   
                    if( (dNormal[aux1] + dReves[aux2] + peso) <= P && peso > r){
                        r = peso;
                    }                
                }
            }
        }
        if(r == 0){
            cout << -1 << endl;
        }else{
            cout << r << endl;
        }
    }
    return 0;
}
