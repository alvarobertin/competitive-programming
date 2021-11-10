#include <climits>
#include <vector>
#include <stack>
#include <iostream>
#include <map>

using namespace std;

int n;
vector<vector<pair<int, int> > > adj(2000);
vector<int> p(2000);
vector<int> d(2000);
map<string, int> mapa;

void inicializar(int s){
  for(int i = 0; i < n; ++i){
    d[i] = INT_MAX;
    p[i] = -1;
  }

  d[s] = 0;
}

bool bellmanFord(int s, int stop){
  int i, j, k, v, peso;
  bool flag;
  
  inicializar(s);

  for(k = 0; k < stop + 1; ++k){
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

  return true;
}

int main(){
    int m, i, peso, cases, q, stops;
    string aux1, aux2;

    cin >> cases;

    for (int c = 1; c <= cases; c++){
    
        adj = vector<vector<pair<int, int> > > (2000);
        mapa = map<string, int> ();

        cin >> n;
        for ( i = 0; i < n; i++){
            cin >> aux1;
            mapa[aux1] = i;
        }
        
        cin >> m;

        for ( i = 0; i < m; i++){
            cin >> aux1 >> aux2 >> peso;
            adj[mapa[aux2]].push_back(make_pair(mapa[aux1], peso));
        }
        
        cin >> q;
        cout << "Scenario #" << c << endl;
        for (int te = 0; te < q; te++){
            
            cin >> stops;

            bellmanFord(mapa["Fredericton"], stops);


            if(d[mapa["Calgary"]] != INT_MAX )
                cout << "Total cost of flight(s) is $" << d[mapa["Calgary"]] << endl;
            else
                cout << "No satisfactory flights" << endl;

        }
        
        if(c != cases)
            cout << endl;
    }
  
    return 0;
}
