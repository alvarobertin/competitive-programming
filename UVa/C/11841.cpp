#include <bits/stdc++.h>
using namespace std;

struct node{
  int x;
  int y;
  int z;
};

vector<node> nodos;

int dx[] = {-1,0,1,1,0,-1};
int dy[] = {0,-1,-1,0,1,1};
int dz[] = {1,1,0,-1,-1,0};

bool sePuede(int node, int aux){
  for(int j = 0; j < 6; j++){
    if( nodos[node].x == nodos[aux].x + dx[j] && nodos[node].y == nodos[aux].y + dy[j] && nodos[node].z == nodos[aux].z + dz[j]){
      return true; 
    }
  }
  return false;
}

int main(){
  

  int n, m, x , y, z;
  queue<int> cola;
  

  cin >> n >> m;

  while(n || m){
    nodos.clear();
    node temp;
    vector<int> visited(50000, 0);
    for (int i = 0; i < m; i++){
      cin >> x >> y >> z;
      temp.x = x;
      temp.y = y;
      temp.z = z;
      nodos.push_back(temp);
      visited[i] = 0;
    }
    
    vector<vector<int>> res;
    for (int z = 0; z < m; z++){
      
      vector<int> temp;

      if( visited[z] != 1){

        temp.push_back(z);      
        int startNode = z;

        cola.push(startNode);
        
        visited[startNode] = 1;
              
        while( !cola.empty() ){

            int aux = cola.front();

            cola.pop();
    
            for(int i = 0; i < m; ++i){
              if( visited[i] == 0 && sePuede(aux, i) ){
                  cola.push(i);
                  visited[i] = 1;
                  temp.push_back(i);
              }
            }
        
        }
      }
      res.push_back(temp);      
    }

    bool flagx, flagy, flagz, flagres;
    flagx = flagy = flagz = flagres = false;

    for (int i = 0; i < res.size(); i++){
      for (int j = 0; j < res[i].size(); j++){
        if(nodos[ res[i][j] ].x == 0)
          flagx = true;
        if(nodos[res[i][j]].y == 0)
          flagy = true;
        if(nodos[res[i][j]].z == 0)
          flagz = true;
        //cout << res[i][j] << " ";
      }

      if(flagz && flagx && flagy){
        flagres = true;
        break;
      }else{
        flagx = flagy = flagz = false;
      }
    }
    if(flagres)
      cout << "Benny" << endl;
    else
      cout << "Willy" << endl;
    
    cin >> n >> m;
  } 




  return 0;
}