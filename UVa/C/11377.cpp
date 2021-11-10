/*
Implementacion Algoritmo de Dijkstra para SSSP
Autor: Carlos Ramirez
Fecha: Abril 25 de 2020

*/

#include <climits>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int n;
vector<vector<pair<int, int> > > adj(50000);
vector<int> p(50000);
vector<int> d(50000);
vector<int> tieneAir(50000, 1);

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
    int m, i, k, q, c, aux1, aux2, peso, cases;


    cin >> cases;
    c = 1;
    while(cases--){

        adj = vector<vector<pair<int, int> > > (5000);
        
        tieneAir = vector<int> (5000, 1);
        
        cin >> n >> m >> k;

        for ( i = 0; i < k; i++){
            cin >> aux1;
            tieneAir[aux1 - 1] = 0;
        }
        
        for ( i = 0; i < m; i++){
            cin >> aux1 >> aux2;
            aux1--;
            aux2--;
            if(aux1 != aux2){
                adj[aux1].push_back( {aux2, tieneAir[aux2]  } );
                adj[aux2].push_back( {aux1, tieneAir[aux1] } );
            }

        }
            

        cin >> q;
        cout << "Case "<< c++ << ":" << endl;

        for ( i = 0; i < q; i++){
            p = vector<int> (5000);
            d = vector<int> (5000);
            
            cin >> aux1 >> aux2;
            
            dijkstra(aux1 - 1);
            
            if(d[aux2 - 1] == 2147483647 || d[aux1 - 1] == 2147483647)
                cout << -1 << endl;
            else{
                if(aux1 != aux2)
                    cout << d[aux2 - 1] + tieneAir[aux1 - 1] << endl;
                else
                    cout << 0 << endl;
            }
        }
        
        // for(i = 0; i < n; ++i)
        //     cout << "Distancia a nodo " << i << ": " << d[i] << endl;

        
        cout << endl;
    }
  

  
    return 0;
}
