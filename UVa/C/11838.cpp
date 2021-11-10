#include <bits/stdc++.h>

using namespace std;

int n, numSCC, t;
vector<vector<int> > adj(50000);
vector<int> visitado(50000);
vector<int> sccInd(50000);
vector<bool> enPila(50000);
stack<int> pila;
vector<vector<int> > sccNodos;

void tarjanAux(int);

void tarjan(){
  int i;

  for(i = 0; i < n ; i++){
    sccInd[i] = visitado[i] = -1;
    enPila[i] = false;
  }

  for(i = 0; i < n ; i++)
    if(visitado[i] == -1)
      tarjanAux(i);
}

void tarjanAux(int v){
  int w;
  visitado[v] = sccInd[v] = ++t;
  pila.push(v);
  enPila[v] = true;

  for(int i = 0; i < adj[v].size(); i++){
    w = adj[v][i];
    if(visitado[w] == -1){
      tarjanAux(w);
      //sccInd[v] = sccInd[v] < sccInd[w] ? sccInd[v] : sccInd[w];
      sccInd[v] = min(sccInd[v], sccInd[w]);
    }
    else if(enPila[w])
      //sccInd[v] = sccInd[v] < visitado[w] ? sccInd[v] : visitado[w];
      sccInd[v] = min(sccInd[v], visitado[w]);
  }

  if(sccInd[v] == visitado[v]){
    //cout << "SCC con indice " << sccInd[v] << ": ";
    sccNodos.push_back(vector<int>());
    numSCC++;
    while(pila.top() != v){
      //cout << pila.top() << " ";
      enPila[pila.top()] = false;
      sccNodos[numSCC - 1].push_back(pila.top());
      pila.pop();
    }

    //cout << pila.top() << endl;
    enPila[pila.top()] = false;
    sccNodos[numSCC - 1].push_back(pila.top());
    pila.pop();
  }
}

int main(){

  int m, i, aux1, aux2, j;

  cin >> n >> m;
  while (n && m){

    numSCC = t = 0;
    adj = vector<vector<int> > (50000);
    visitado = vector<int> (50000);
    sccInd = vector<int> (50000);
    enPila = vector<bool> (50000);

    pila = stack<int>();
    sccNodos.clear();

      for(i = 0; i < m; i++){
        cin >> aux1 >> aux2 >> j;
        if(j == 1)
            adj[aux1 - 1].push_back(aux2 - 1);
        else{
            adj[aux1 - 1].push_back(aux2 - 1);
            adj[aux2 - 1].push_back(aux1 - 1);
        }

    }

    tarjan();
    
    if(numSCC == 1)
        cout << 1 << endl;
    else
        cout << 0 << endl;


    cin >> n >> m;

  }

  
  return 0;
}
