#include <bits/stdc++.h>

using namespace std;

map<string, int> indegre;
map<string, int> days;

int n;
vector<vector<pair<int, int> > > adj(50000);
map<string, int> etiqueta;
vector<int> d(50000);

void inicializar(int s){
  for(int i = 0; i < n; ++i){
    d[i] = INT_MAX;
  }

  d[s] = 0;
}

bool bellmanFord(int s){
  int i, j, k, v, peso;
  bool flag;
  
  inicializar(s);

  for(k = 0; k < n - 1; ++k){
    flag = false;
    
      for(i = 0; i < n; i++){
        for(j = 0; j < adj[i].size(); ++j){
          v = adj[i][j].first;
          peso = adj[i][j].second;
          if(d[i] != INT_MAX && d[i] + peso < d[v]){
            d[v] = d[i] + peso;
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


int main() {
    string line, aux, preds, temp;
    int cases, w, p;

    cin >> cases;
    cin.ignore();
    cin.ignore();
    while( cases-- ){


        adj = vector<vector<pair<int, int> > > (500);
        etiqueta.clear();
        d = vector<int> (500);
        p = 1;
        indegre.clear();
        getline(cin, line);

        while(line != ""){
            stringstream ss(line);

            ss >> aux;
            if(etiqueta.find(aux) == etiqueta.end() ) etiqueta[aux] = p++;
            indegre[aux] = 0;

            ss >> w;
            days[aux] = w *-1;
            preds = "";
            ss >> preds;

            indegre[aux] = preds.size();
            for (int i = 0; i < preds.size(); i++){
                temp = string(1, preds[i]);
                if(etiqueta.find(temp) == etiqueta.end() ) etiqueta[temp] = p++;
                adj[ etiqueta[ temp ] ].push_back( { etiqueta[aux], days[aux]  } ) ;
            }

            getline(cin, line);
        }

        for (map<string, int>::iterator i = indegre.begin(); i != indegre.end() ; i++){
            if(i->second == 0 ){
                adj[0].push_back( {etiqueta[i->first], days[i->first]});
            }
        }
        
        // for (int i = 0; i < p; i++){
        //     for(int j = 0; j < adj[i].size(); j++){
        //         cout << i << " " << adj[i][j].first << endl;
        //     }
        // }
        
        n = p; 
        bellmanFord(0);        
        int max = 0;
        for(int i = 0; i < n; ++i){
            if(d[i]*-1 > max) max = d[i]*-1;
            //cout << d[i] << endl;
        }

        cout << max << endl;
        if(cases)
            cout << endl;
    }

    return 0;
}