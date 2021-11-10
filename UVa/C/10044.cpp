#include <vector>
#include <map>
#include <string>
#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

int n, erdos, contador;
vector<vector<int>> adj(1000);
bool encontrado;
int visitados[1000];
int p[1000];
map<string, int> names;

void bfsAux(int v, int final){
  int u, w, i;
  queue<int> cola;
  visitados[v] = 0;
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
        if(visitados[w] == -1){
            visitados[w] = visitados[u] + 1;
            p[w] = u;
            cola.push(w);
        }
    }
  }
}

void bfs(int inicio, int final){
  int i;

    for(i = 0; i < contador; ++i){
        visitados[i] = -1;
        p[i] = -1;
    }

    bfsAux(inicio, final);
}

int main(){
    int u, v, i, j, scenarios, k, numComas;
    string entrada, name;
    vector<string> combinaciones;
    int N, M, P;
    cin >> scenarios;

    for (int y = 1; y <= scenarios; y++){
        adj = vector<vector<int>> (1000);
        names = map<string, int>();

        cin >> P >> N;
        cin.ignore();
        contador = 1;
        for (int i = 0; i < P; i++){
            getline(cin, entrada);
            k = 0;
            numComas = 0;
            combinaciones = vector<string>();
            name = "";
            while(entrada[k] != ':'){
                
                if(entrada[k] == ',' && numComas == 0){
                    numComas = 1;
                    name.push_back(entrada[k]);
                }
                else if(entrada[k] == ',' && numComas == 1){
                    numComas = 0;

                    if(names[name] == 0){
                        names[name] = contador;
                        contador += 1;    
                    }

                    combinaciones.push_back(name);
                    name = "";
                    k++;// Para el espacio despues de la coma final de los nombres
                }
                else{
                    name.push_back(entrada[k]);
                }
                k++;
            }
            if(names[name] == 0){
                names[name] = contador;
                contador += 1;    
            }
            combinaciones.push_back(name);
        
            int size = combinaciones.size();
            for (int l = 0; l < size; l++){
                for (int x = l; x < size; x++){
                    if(x != l){
                        adj[names[combinaciones[l]]].push_back(names[combinaciones[x]]);
                        adj[names[combinaciones[x]]].push_back(names[combinaciones[l]]);
                    }
                }
            }

        }
        cout << "Scenario " << y << endl; 
        for (int i = 0; i < N; i++){
            getline(cin, entrada);
            encontrado = false;
            erdos = 0;
            
            if(names[entrada] != 0){
                bfs(names["Erdos, P."], names[entrada]);
            }

            if(encontrado == true){
                cout << entrada << " " << visitados[names[entrada]] << endl;
            }else{
                cout << entrada << " infinity" << endl;
            }
        }
            
    }
    
  return 0;
}
