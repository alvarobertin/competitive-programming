#include <bits/stdc++.h>

using namespace std;

int n, numSCC, t;
map< string, vector<string> > adj;
map<string, int> visitado;
map<string, int> sccInd;
map<string, bool> enPila;
stack<string> pila;
vector<vector<string> > sccNodos;
map< string, vector<string> >::iterator it;

void tarjanAux(string);

void tarjan(){
  int i;

  for(it = adj.begin(); it != adj.end(); it++)
    if(visitado[it->first] == -1)
      tarjanAux(it->first);
}

void tarjanAux(string v){
  string w;
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
    sccNodos.push_back(vector<string>());
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

  cin >> n;
  while (n){

    numSCC = t = 0;
    adj.clear();
    visitado.clear();
    sccInd.clear();
    enPila.clear();
    pila = stack<string>();
    sccNodos.clear();

    cin.ignore();
    for ( int j = 0; j < n; j++){    
        
        vector<string> v;
        string aux, res;
        for (int j = 0; j < 5; j++){
            cin >> aux;
            v.push_back(aux);
            // if(adj.find(aux) == adj.end())
            //     adj[aux] = vector<string> (); 
        }
        cin >> res;

        for(i = 0; i < 5; i++){
            adj[ res ].push_back( v[i]);
            sccInd[v[i]] = visitado[v[i]] = -1;
            enPila[v[i]] = false;
            // sccInd[v[k]] = visitado[v[k]] = -1;
            // enPila[v[k]] = false;
        }
    }
    tarjan();
    for (i = 0; i < sccNodos.size(); i++){
        sort(sccNodos[i].begin(), sccNodos[i].end());
    }


    sort(sccNodos.begin(), sccNodos.end());

    for (i = 0; i < sccNodos.size(); i++){
        cout << sccNodos[i][0];
        for (int j = 1; j < sccNodos[i].size(); j++){
            cout << " " << sccNodos[i][j] ;
        }
        cout << endl;
    }
    
    
    cin >> n;
    if(n)
        cout << endl;
  }

  
  return 0;
}
