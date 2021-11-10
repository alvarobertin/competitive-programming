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
set<string>::iterator it2;
set<string> ans;

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

void dfs(string v){
    string u;  
    int i;
    visitado[v] = 1;
    ans.insert(v);

    for(i = 0; i < adj[v].size(); ++i){
        u = adj[v][i];
        if(visitado[u] == 0){
            ans.insert(u);
            dfs(u);
        }
    }

}



int main(){

    int m, i, aux1, aux2, j;
    string start;
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
        ans.clear();

        numSCC, t;

        for ( int j = 0; j < n; j++){    
            
            vector<string> v;
            string aux, res, line;
            getline(cin, line);

            stringstream ss(line);

            ss >> start;
            while(ss >> aux){
                adj[ start ].push_back(aux);
                sccInd[start] = visitado[start] = -1;
                enPila[start] = false;
            }
            
           
        }

        tarjan();
        
        visitado.clear();

        for (int i = 0; i < numSCC; i++){
            if(sccNodos[i].size() > 1){
                dfs(sccNodos[i][0]);
            }
        }
        
        cout << ans.size() << endl;
        it2 = ans.begin();
        cout << *(it2);
        it2++;
        for (; it2 != ans.end(); it2++){
            cout << " " << *it2;
        }
        cout << endl;

        cin >> n;
        
    }


  return 0;
}
