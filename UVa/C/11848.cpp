#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<pair<int, int> > > adj(50000);
vector<int> p(50000);
vector<double> d(50000);
vector<vector<double>> pa(5000), pb (5000);

void inicializar(int s){
  for(int i = 0; i < n; ++i){
    d[i] = INT_MAX;
    p[i] = -1;
  }

  d[s] = 0;
}

void dijkstra(int s, double a){
  int i, j, k, u, v;
  double peso, costo;
  priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>> > cola;
  
  inicializar(s);
  cola.push(make_pair(0, s));

  while(!cola.empty()){
    costo = cola.top().first;
    u = cola.top().second;
    cola.pop();

    if(costo == d[u]){
        for(j = 0; j < adj[u].size(); ++j){
            v = adj[u][j].first;

            if(  pa[u][v] == -1 ){
                peso = pb[u][v];
            }else if(pb[u][v] == -1) {
                peso = pa[u][v]; 
            }else{
                peso = pa[u][v]*a + pb[u][v]*(1 - a) ;
            }

            if(d[u] != INT_MAX && d[u] + peso < d[v]){
                d[v] = d[u] + peso;
                p[v] = u;
                cola.push(make_pair(d[v], v));
            }
        }
    }
  }
}


int main() {
    string line;
    int ma, mb, k, aux1, aux2;
    double a, w;

    cin >> n >> ma >> mb >> k; 

    while( n != -1 ){
        pa = vector<vector<double>> (5000);
        pb = vector<vector<double>> (5000);

        adj = vector<vector<pair<int, int> > >(5000);
        p = vector<int> (5000);
        d = vector<double> (5000);

        for (int i = 0; i < n; i++){
            pa.push_back(vector<double> (5000));
            pb.push_back(vector<double> (5000));
            for (int j = 0; j < n; j++){
                pa[i].push_back(-1);
                pb[i].push_back(-1); 

            }
        }
        

        for ( int i = 0; i < ma; i++){
            cin >> aux1 >> aux2 >> w;

            adj[aux1].push_back( {aux2, 0} );
            adj[aux2].push_back( {aux1, 0} );

            pa[aux1][aux2] = w;
            pa[aux2][aux1] = w;
        }
        
        for ( int i = 0; i < mb; i++){
            cin >> aux1 >> aux2 >> w;

            adj[aux1].push_back( {aux2, 0} );
            adj[aux2].push_back( {aux1, 0} );

            pb[aux1][aux2] = w;
            pb[aux2][aux1] = w;

        }        

        for (int i = 0; i < k; i++){
            cin >> a;

            dijkstra(0, a);

            cout << int(d[n - 1]) << endl;
        }
        
 

        cin >> n >> ma >> mb >> k; 
    }

    return 0;
}