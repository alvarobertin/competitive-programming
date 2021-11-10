#include <bits/stdc++.h>

using namespace std;

int n, distMax, nodoMax;
vector<vector<int> > adj(50000);
int grado[50000];
int nivel[50000];
set<int> nodosCentro;
vector<int> alturas(50000);

void centro(){
  int i, v, nivelMax = 0, radio;
  queue<int> cola;

  for(i = 0; i < n; ++i){
    nivel[i] = 0;
    grado[i] = adj[i].size();
  }

  for(i = 0; i < n; ++i)
    if(grado[i] == 1)
      cola.push(i);

  while(!cola.empty()){
    v = cola.front();
    cola.pop();

    for(i = 0; i < adj[v].size(); ++i){
      grado[adj[v][i]]--;
      if(grado[adj[v][i]] == 1){
        cola.push(adj[v][i]);
        nivel[adj[v][i]] = nivel[v] + 1;
        nivelMax = max(nivelMax, nivel[adj[v][i]]);
      }
    }
  }

  for(i = 0; i < n; ++i)
    if(nivel[i] == nivelMax)
      nodosCentro.insert(i);

  radio = (nodosCentro.size() >= 2) ? nivelMax + 1 : nivelMax;
  //cout << "El radio del arbol es " << radio << endl;
}

void dfsAux(int v, int padre, int dist){
  int w, i;
  alturas[v] = dist;
  dist++;

  if(dist > distMax){
    distMax = dist;
    nodoMax = v;
  }
  
  for(i = 0; i < adj[v].size(); ++i){
    w = adj[v][i];
    if(w != padre)
      dfsAux(w, v, dist);
  }
}


int main(){
    int m, i, aux1, aux2, rad;

    while(cin >> n){

        for(i = 0; i < n; i++){
            cin >> m;
            for (int j = 0; j < m; j++){
                cin >> aux2;
                adj[i].push_back(aux2 - 1);
            }
        }
            set<int> res;
            centro();
            distMax = 0;
            nodoMax = 0;        
            set<int>::iterator it = nodosCentro.begin();
            dfsAux(*it, -1, 0);
            for (int i = 0; i < n; i++){
                 if(alturas[i] == distMax - 1){
                     res.insert(i + 1);
                 }
            }
            cout << "Best Roots  : " << *it + 1;
            ++it;
            for( ; it != nodosCentro.end(); ++it){
                cout << " " << *it + 1;
                distMax = 0;
                nodoMax = 0; 
                dfsAux(*it, -1, 0);
                for (int i = 0; i < n; i++){
                    if(alturas[i] == distMax - 1){
                        res.insert(i + 1);
                    }
                }
            }
            cout << endl;
            it = res.begin();
            cout << "Worst Roots : " << *it;
            ++it;
            for (; it != res.end(); ++it){
                cout << " " << *it;
            }
            alturas = vector<int> (6000);

            cout << endl;
            adj = vector<vector<int> > (6000);
            nodosCentro = set<int> ();
            
    }



    return 0;
}
