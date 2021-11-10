#include <bits/stdc++.h>

using namespace std;

int n, res;
vector<vector<pair<int, int> > > adj(5000);


vector<int> p(50000);
vector<pair<pair<int, int>, int>> d(50000);

void inicializar(int s){
  for(int i = 0; i < n; ++i){
    d[i] = {{2107483647, 2107483647}, 2107483647};
    p[i] = -1;
  }

  d[s] = {{0, 0}, 0};
}

bool bellmanFord(int s){
  int i, j, k, v, peso;
  pair<pair<int, int>, int> temp; 
  bool flag;
  
  inicializar(s);
    for(j = 0; j < adj[s].size(); ++j){
        peso = adj[s][j].second;
        v = adj[s][j].first;        
        d[v] = {{peso, peso}, 0};
    }

  for(k = 0; k < n - 1; ++k){
    
      for(i = 0; i < n; i++){
        for(j = 0; j < adj[i].size(); ++j){
          v = adj[i][j].first;
          peso = adj[i][j].second;
          temp = d[i];
            temp.first.first = temp.first.second;
            temp.first.second = peso;
            temp.second  += abs(peso - temp.first.first);

          if(d[i].second != 2107483647 && temp.second < d[v].second){
            d[v] = temp;
            flag = true;
          }
        }
      }
  }


  return true;
}

// void dijkstra(int s){
//   int i, j, k, peso, v, u, costo;
//   priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > cola;
//   pair <int, int> temp; 
//     inicializar(s);
//     for(j = 0; j < adj[s].size(); ++j){

//         peso = adj[s][j].second;
//         u = adj[s][j].first;

//         cola.push({0, u});
        
//         d[u] = {peso, peso};
//     }

//   while(!cola.empty()){

//     costo = cola.top().first;
//     u = cola.top().second;
//     cola.pop();

//     if(costo == d[u].second - d[u].first){
    
//         for(j = 0; j < adj[u].size(); ++j){
//             v = adj[u][j].first;
//             peso = adj[u][j].second;
//             temp = d[u];

//             temp.first = min(temp.first, peso);
//             temp.second  = max(temp.second, peso);

//             if(d[u].first != INT_MAX && d[u].second != -2107483647 && (temp.second - temp.first) < (d[v].second - d[v].first) ){
//                 d[v] = temp;
//                 cola.push({d[v].second - d[v].first, v});
//             }
//         }
//     }


//   }
// }


int main() {
    string line;
    int m, aux1, aux2, w, st, fs, q;

    while( cin >> n >> m ){
        adj = vector<vector<pair<int, int> > > (5000);

        for ( int i = 0; i < m; i++){
            cin >> aux1 >> aux2 >> w;

            adj[aux1 - 1].push_back( {aux2 - 1, w} );
            adj[aux2 - 1].push_back( {aux1 - 1, w} );
        }
        
        cin >> st >> fs;

        cin >> q;

        
        for (int i = 0; i < q; i++){
            d = vector<pair<pair<int, int>, int>> (50000);
            cin >> aux1 >> aux2;
            res = 0;
            //visited.clear();
            bellmanFord(aux1 - 1);

            cout << d[aux2 - 1].second + st + fs << endl;

        }
        
        // for (int i = 0; i < result.size(); i++){
        //     cout << result[i].u << " " <<  result[i].v << " " << result[i].weight << endl;
        // }


    }

    return 0;
}