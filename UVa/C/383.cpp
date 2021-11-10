#include <vector>
#include <map>
#include <string>
#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

int n, numWarehouse;
vector<vector<int>> adj(10000);
bool encontrado;
int visitados[1000];
int p[1000];
map<string, int> names;

void bfsAux(int v, int final){
  int u, w, i;
  queue<int> cola;
  visitados[v] = 1;
  cola.push(v);

  while(!cola.empty()){
    
    u = cola.front();
    cola.pop();
    if(u == final){
        encontrado = true;
        return;
    }

    for(i = 0; i < adj[u].size(); ++i){
        w = adj[u][i];
        if(!visitados[w]){
            visitados[w] = 1;
            p[w] = u;
            cola.push(w);
        }
    }
  }
}

void bfs(int inicio, int final){
  int i;

    for(i = 0; i < n; ++i){
        visitados[i] = 0;
        p[i] = -1;
    }

    bfsAux(inicio, final);
}

int main(){
    int u, v, i, j, casos;
    string name1, name2;
    int N, M, P;
    cin >> casos;

    cout << "SHIPPING ROUTES OUTPUT\n";
    for (int y = 1; y <= casos; y++){
        adj = vector<vector<int>> (10000);
        names.clear();
        cin >> n >> M >> P;

        for (i = 0; i < n; i++){
            cin >> name1;
            names[name1] = i; 
        }
        
        for (int i = 0; i < M; i++){
            cin >> name1 >> name2;
            adj[names[name1]].push_back(names[name2]);
            adj[names[name2]].push_back(names[name1]);
        }
        cout << "\nDATA SET  " << y << endl << endl;
        for (int i = 0; i < P; i++){
            
            encontrado = false;
            numWarehouse = 0;

            cin >> N >> name1 >> name2;

            bfs(names[name1], names[name2]);

            if(encontrado == true){

                int node = names[name2];
                while(node != names[name1] && p[node] != node){
                    numWarehouse++;
                    node = p[node];
                }
                cout << "$" << numWarehouse*N*100 << endl;
            }else{
                cout << "NO SHIPMENT POSSIBLE" << endl;
            }

        }
        
    }
    cout << "\nEND OF OUTPUT" << endl;


  return 0;
}
