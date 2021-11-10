#include <bits/stdc++.h>

using namespace std;

int n;
bool mori;
vector<vector<pair<int, int> > > adj(50000);
vector<int> pesos(5000);
vector<int> p(50000);
vector<int> d(50000);
vector<int> ciclo;
map<int, int> visited;

void inicializar(int s){
  for(int i = 0; i < n; ++i){
    d[i] = INT_MAX;
    p[i] = -1;
  }

  d[s] = 0;
}

bool ruta(int startNode, int endNode){
    
    int node = endNode;
    
    for (int i = 0; i < n; i++){
        //cout << "node " << node << " " << d[node] << endl;
        if(d[node] > 99 || d[node] == 2147483647) return false;
        if(node == -1) break;
        node = p[node];
    }
    return true;
}


bool bellmanFord(int s){
  int i, j, k, v, peso, t, cur;
  bool flag = true;
  bool entradoCiclo = false;
  
  inicializar(s);
    for(k = 0; k < n - 1; ++k){
    
      for(i = 0; i < n; i++){
        
        for(j = 0; j < adj[i].size(); ++j){
          if(visited[i] == 1) break;
          v = adj[i][j].first;
          peso = pesos[adj[i][j].first];
          if(d[i] != INT_MAX && d[i] + peso < d[v] && d[i] + peso < 100){
            //cout << d[v] << " " << d[i] << " " << peso << endl;
            d[v] = d[i] + peso;
            p[v] = i;
            flag = true;
          }
        }
      }

      if(!flag)
        break;
  }


   for(i = 0; i < n; i++){
    for(j = 0; j < adj[i].size(); ++j){
      v = adj[i][j].first;
      peso = pesos[adj[i][j].first];
      if(d[i] != INT_MAX && d[i] + peso < d[v] ){
          ciclo.push_back(v);
          flag = false;
      } 
    }
  }

  return flag;
}

int main(){
    int m, i, aux1, aux2, peso;

    cin >> n;
    while(n != -1){
        mori = false;
        adj = vector<vector<pair<int, int> > > (500);
        pesos = vector<int> (500);
        p = vector<int> (500);
        d = vector<int> (500);
        ciclo = vector<int>();

        for ( i = 0; i < n; i++){
            cin >> peso;
            cin >> m;
            pesos[i] = peso*-1;
            
            for (int j = 0; j < m; j++){
                cin >> aux2;
                adj[i].push_back(make_pair(aux2 - 1, 0));
                visited[i] = 0;
                visited[aux2 - 1] = 0;
            }

        }

        bool flag = bellmanFord(0);
        
        if(flag){
            //cout << "g" << d[n - 1] << mori;

            if(( d[n - 1] < 100) && d[n - 1] != 2147483647  ) cout << "winnable" <<  endl;
            else cout << "hopeless" << endl;
        }else{
            bool encontro = false;
            queue<int> cola;
            int startNode = n - 1;
            visited.clear();
            for (int z = 0; z < ciclo.size(); z++){
                if(visited[ciclo[z]] != 1){
                    
                    encontro = false;
                
                    int endNode;
                
                    startNode = ciclo[z];
                    endNode = n - 1;

                    cola.push(startNode);
                    
                    
                    visited[startNode] = 1;
                    
                                    
                    while( !cola.empty() ){

                        int node = cola.front();

                        cola.pop();

                        if(node == endNode){
                            encontro = true;
                            break;
                        } 
                
                        for(int i = 0; i < adj[node].size(); ++i){

                            int aux = adj[node][i].first;

                            if( visited[aux] != 1 ){
                                cola.push(aux);
                                visited[aux] = 1;
                            }
                        
                        }
                    
                    }
                    if(encontro )
                        break;
                }
            }   
            vector<int> d_og = d;
            bool oldmori = mori;

           // mori = ruta(0, n-1);
            
            //flag = bellmanFord(0);
            //&& ruta(0, n-1) && ruta(startNode, n-1)
            if(encontro && ruta(0, startNode)){
                cout << "winnable" <<  endl;
            }else{
                if(( d_og[n - 1] < 100) && d_og[n - 1] != 2147483647 ) cout << "winnable" <<  endl;
                else cout << "hopeless" << endl;
            }
            
        }





        cin >> n;
    }



    return 0;
}
