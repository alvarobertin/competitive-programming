#include <bits/stdc++.h>

using namespace std;

int n, distMax, nodoMax;
vector<vector<int> > adj(50000);
int grado[50000];
int nivel[50000];
set<int> nodosCentro, worst;

void dfsAux(int v, int padre, int dist){
  int w, i;
  dist++;

  if(dist > distMax){
    worst.clear();  
    distMax = dist;
    nodoMax = v;
  }
        
  if(dist >= distMax)
    worst.insert(v);

  for(i = 0; i < adj[v].size(); ++i){
    w = adj[v][i];
    if(w != padre)
      dfsAux(w, v, dist);
  }
}

int diametro(){
  distMax = 0;
  nodoMax = -1;

  //se escoge arbitrariamente iniciar en el nodo 0
  //el resultado seria el mismo asi se inicie en un nodo diferente
  dfsAux(0, -1, -1);
  for (int i = 0; i < 2; i++)
    dfsAux(nodoMax, -1, -1);
    
  return distMax;
}

int radio(){
  int diam = diametro();
  return (diam + 1) / 2;
}

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
 
}

int main(){
    int hijos, i, aux1, aux2, rad;
    
    while(cin >> n){

        worst = set<int>();
        nodosCentro = set<int>();
        adj = vector<vector<int> > (5000);

        for (int i = 0; i < n; i++){
            cin >> hijos;
            for (int j = 0; j < hijos; j++){
                cin >> aux1;
                adj[i].push_back(aux1 - 1);
            }
        }

        centro();

        printf("Best Roots  :");

        for(set<int>::iterator it = nodosCentro.begin(); it != nodosCentro.end(); ++it)
            printf(" %d", (*it) + 1);
        printf("\n");

        printf("Worst Roots :");

        diametro();
        
        for(set<int>::iterator it = worst.begin(); it != worst.end(); ++it)
            printf(" %d", (*it) + 1);

        printf("\n");
    }


    return 0;
}
