#include <bits/stdc++.h>

using namespace std;

int n, numSCC, t;
vector<vector<int> > adj(50000);
int visitado[50000];
int low[50000];
int padre[50000];
set<pair<int, int> > bridges;

void bridgesAux(int);
bool compare(pair<int, int> a, pair<int, int> b){
  if(a.first != b.first)
    return a.first < b.first;
  return a.second < b.second;
}

void bridgesTarjan(){
  int i;

  for(i = 0; i < n; i++)
    low[i] = visitado[i] = padre[i] =-1;

  for(i = 0; i < n; i++)
    if(visitado[i] == -1)
      bridgesAux(i);
}

void bridgesAux(int v){
  int w;
  visitado[v] = low[v] = ++t;

  for(int i = 0; i < adj[v].size(); i++){
    w = adj[v][i];
    if(visitado[w] == -1){
      padre[w] = v;
      bridgesAux(w);
      low[v] = low[v] < low[w] ? low[v] : low[w];

      //verificar si es un puente
      if(low[w] > visitado[v])
	    bridges.insert(make_pair(v, w));
    }
    else if(w != padre[v])
      low[v] = low[v] < visitado[w] ? low[v] : visitado[w];
  }
}

int main(){
    int m, i, aux1, aux2;

    cin >> n >> m;

    while(n && m){

        numSCC = t = 0;
        adj = vector<vector<int> > (50000);
        bridges.clear();
        
        for(i = 0; i < m; i++){
            cin >> aux1 >> aux2;
            adj[aux1].push_back(aux2);
            adj[aux2].push_back(aux1);
        }

        bridgesTarjan();



        if(bridges.size() == 0)
            cout << 0 << endl;
        else{

            vector< pair<int, int> > res;
            pair<int, int> temp;

            for(set<pair<int, int> >::iterator it = bridges.begin(); it !=  bridges.end(); ++it){
              if(it->first <= it->second){
                temp.first = it->first;
                temp.second = it->second;
              }else{
                temp.first = it->second;
                temp.second = it->first;
              }
              
              res.push_back(temp);
            }

            sort(res.begin(), res.end(), compare);
            cout << bridges.size();

            for (int k = 0; k < res.size(); k++){
              cout << " " << (res[k].first) << " " << (res[k]).second;
            }
            
            cout << endl;
        }

        cin >> n >> m;
    }
  return 0;
}
