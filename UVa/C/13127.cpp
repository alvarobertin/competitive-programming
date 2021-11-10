#include <climits>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

int n;
vector<vector<pair<int, int> > > adj(5000);
vector<int> p(5000), esBanco, policias;
vector<int> d(5000, INT_MAX);

void inicializar(int s){
  for(int i = 0; i <= n; ++i){
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

bool myfunction(int a, int b){
  if(d[a] != d[b])
    return d[a] < d[b];
  return a < b;
}

int main(){
  int m, i, aux1, aux2, peso, nBancos, nPolicias, maxima;
  vector<int> imprimir;
  vector< int > bancos; 

    while(cin >> n >> m >> nBancos >> nPolicias){
        maxima = 0;
        policias = vector<int>();
        bancos = vector< int >();
        imprimir = vector<int>();
        esBanco = vector<int>(n+1, 0);
        d = vector<int> (n+1, INT_MAX);
        adj = vector<vector<pair<int, int> > > (n+1);

        for(i = 0; i < m; i++){
            cin >> aux1 >> aux2 >> peso;
            adj[aux1].push_back(make_pair(aux2, peso));
            adj[aux2].push_back(make_pair(aux1, peso));
        }

        for ( i = 0; i < nBancos; i++){
            cin >> aux1;
            esBanco[aux1] = 1;
        }

        for ( i = 0; i < nPolicias; i++){
            cin >> aux1;
            policias.push_back(aux1);
            adj[n].push_back(make_pair(aux1, 0));
        }
        
        if(nPolicias != 0){

            dijkstra(n);

            for ( i = 0; i < n; i++){
              if(esBanco[i] == 1){
                bancos.push_back(i);
              }
            }
            
            sort(bancos.begin(), bancos.end(), myfunction);
            
            maxima =  d[bancos[nBancos-1]];

            for ( i = 0; i < nBancos; i++){
                if(maxima ==  d[bancos[i]]){
                    imprimir.push_back( bancos[i]);
                }
            }
            
            cout << imprimir.size();
            if(maxima == INT_MAX)
                cout << " *" << endl;
            else
                cout << " " << maxima << endl;

            cout << imprimir[0];

            for ( i = 1; i < imprimir.size(); i++){
                cout << " " << imprimir[i];
            }
            cout << endl;


        }else{
            for ( i = 0; i < n; i++){
                if(esBanco[i] == 1){
                  bancos.push_back(i);
                }
            }
            sort(bancos.begin(), bancos.end(), myfunction);
            maxima = d[bancos[nBancos-1]];

            cout << nBancos << " *" << endl;

            cout << bancos[0];

            for ( i = 1; i < nBancos; i++){
                cout << " " << bancos[i];
            }
            cout << endl;
        }


    }
  
  return 0;
}
