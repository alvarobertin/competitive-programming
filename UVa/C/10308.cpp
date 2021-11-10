#include <bits/stdc++.h>

using namespace std;

int n, distMax, nodoMax;
vector<vector<int>> pesos(11000, vector<int>(11000));
vector<vector<int> > adj(11000);

void dfsAux(int v, int padre, int dist){
  int w, i;
  //dist++;
  if(padre != -1){
      dist += pesos[padre][v]; 
  }

  if(dist >= distMax){
    distMax = dist;
    nodoMax = v;
  }
  
  for(i = 0; i < adj[v].size(); ++i){
    w = adj[v][i];
    if(w != padre)
      dfsAux(w, v, dist);
  }
}

int diametro(){
  distMax = 0;
  nodoMax = 1;
  //se escoge arbitrariamente iniciar en el nodo 0
  //el resultado seria el mismo asi se inicie en un nodo diferente
  dfsAux(1, -1, 0);
  dfsAux(nodoMax, -1, 0);
  
  return distMax;
}

int main(){
    int m, i, aux1, aux2, diam, peso;
    string line;

    while(getline(cin, line)){
        if(line == ""){
            if(adj[1].size() > 0){
                diam = diametro();
                cout << diam << endl;  
            }

            adj = vector<vector<int> > (11000);

        }else{
            stringstream ss(line);

            ss >> aux1;
            ss >> aux2; 
            ss >> peso;

            adj[aux1].push_back(aux2);
            adj[aux2].push_back(aux1);

            pesos[aux1][aux2] = peso;
            pesos[aux2][aux1] = peso;
        }
    }
    if(adj[1].size() > 0){
        diam = diametro();
        cout << diam << endl;  
    }
    
  return 0;
}
