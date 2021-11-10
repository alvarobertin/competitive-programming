#include <bits/stdc++.h>

using namespace std;

int n, t;
vector<vector<int> > adj(50000);
int visitado[50000];
int low[50000];
int padre[50000];
vector<int> pigeon(50000, 0);
set<int> apNodos;

void apAux(int);

void ap(){
  int i;

  for(i = 0; i < n; i++)
    low[i] = visitado[i] = padre[i] =-1;

  for(i = 0; i < n; i++)
    if(visitado[i] == -1)
      apAux(i);
}

bool compare(pair<int, int> a, pair<int, int> b){
  if(a.second != b.second)
    return a.second > b.second;
  return a.first < b.first;
}

void apAux(int v){
  int w, numHijos = 0;
  visitado[v] = low[v] = ++t;

  for(int i = 0; i < adj[v].size(); i++){
    w = adj[v][i];
    if(visitado[w] == -1){
      numHijos++;
      padre[w] = v;
      apAux(w);
      if(low[v] < low[w]){
        low[v] = low[v];
      }else{
        low[v] = low[w];
      }
      if(low[w] >= visitado[v])
        pigeon[v]++;
      //low[v] = low[v] < low[w] ?  : low[w];

      //verificar si es un punto de articulacion
      if(padre[v] != -1 && low[w] >= visitado[v]){
	      apNodos.insert(v);
        
      }
    }
    else if(w != padre[v]){
      if(low[v] < visitado[w]){
        low[v] = low[v];
      }else{
        low[v] = visitado[w];
      }

      //low[v] = low[v] < visitado[w] ? low[v] : visitado[w];

    }
  }
  if(padre[v] != -1)
    pigeon[v]++;
  // Se cambio el > de numhijos por >=
  if(padre[v] == -1 && numHijos >= 1)
    apNodos.insert(v);
}

int main(){
  int m, i, aux1, aux2;

  cin >> n >> m;
  while(n && m){

    t = 0;
    adj = vector<vector<int> >(50000);
    pigeon = vector<int> (50000, 0);
    apNodos.clear();

    cin >> aux1 >> aux2;
    while(aux1 != -1){
      adj[aux1].push_back(aux2);
      adj[aux2].push_back(aux1);
      cin >> aux1 >> aux2;

    }

    ap();

    vector< pair<int, int> > res;
    pair<int, int> temp;

    for (int k = 0; k < n; k++){
      temp.first = k;
      temp.second = pigeon[k];
      res.push_back(temp);
    }
    
    // for(set<int>::iterator it = apNodos.begin(); it != apNodos.end(); ++it){
    //   temp.first = *it;
    //   temp.second = pigeon[*it];
    //   res.push_back(temp);
    // }
    sort(res.begin(), res.end(), compare);

    for (int k = 0; k < m; k++){
      cout << (res[k].first) << " " << (res[k]).second << endl;
    }

    // for (int k = 0; k < n; k++){
    //   cout << k << ": " << pigeon[k] << endl;
    // }
    
    
  
    cin >> n >> m;
  
    cout << endl;
  }
  return 0;
}
