#include <bits/stdc++.h>

using namespace std;

int n, acum, de, cercano;
bool fans;
vector<int> agua(4);
vector<int> ans(4);
vector<int> limite(3);
map<pair<int, pair<int, int>>, int> visited;

int ponerAgua(int u, int v){
    int temp = 0;
    if(limite[v] == agua[v]) return 0;
    if(agua[u] <= limite[v] - agua[v]){
        agua[v] += agua[u];
        temp = agua[u];
        agua[u] = 0;
        return temp;
    }else{
        agua[u] -= limite[v] - agua[v];
        temp = limite[v] - agua[v];
        agua[v] = limite[v];
        return temp;        
    } 
    
}

bool checkAns(){
    if(agua[0] <= de && agua[0] > cercano){
        cercano = agua[0];
        ans = agua;
    }
    if(agua[1] <= de && agua[1] > cercano){
        cercano = agua[1];
        ans = agua;
    }
    if(agua[2] <= de && agua[2] > cercano){
        cercano = agua[2];
        ans = agua;
    }
    if((agua[2] == cercano || agua[1] == cercano || agua[0] == cercano) && ans[3] > agua[3]){
        ans[3] = min(ans[3], agua[3]);
    }

    if(fans && (agua[2] == de || agua[1] == de || agua[0] == de)){
        ans[3] = min(ans[3], agua[3]);
    }

    if(cercano == de && !fans){
        fans = true;
        ans = agua;
    }


    return fans;
}

void dijkstra(vector<int> s){
  int i, j, k, peso, costo;
  vector<int> u, v;
  priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<pair<int, vector<int>>> > cola;
  

    cola.push(make_pair(0, s));
    int conteo = 0;
  while(!cola.empty() && conteo < 90000){

    costo = cola.top().first;
    u = cola.top().second;
    agua = u;
    cola.pop();
    

    for(i = 0; i < 3; i++){

        for ( j = 0; j < 3; j++){

            if(i != j ){
                agua = u;
                
                peso = ponerAgua(i, j);

                if(visited[{agua[0], {agua[1], agua[2]} }] == 0){
                    visited[{agua[0], {agua[1], agua[2]} }] = 1;
                    
                    agua[3] += peso;
                    //cout << agua[0] << " " << agua[1] << " " << agua[2] << ": " << agua[3] << endl; 
                    checkAns();
                    cola.push(make_pair(agua[3], agua));
                }
            }
        }
    }

    conteo++;
  }
}

int main(){
    int m, a, b, c, aux1, aux2, peso, cases;


    cin >> cases;

    while(cases--){
        cin >> a >> b >> c >> de;
        agua[0] = 0;
        agua[1] = 0;
        agua[2] = c;
        agua[3] = 0;


        limite[0] = a;
        limite[1] = b;
        limite[2] = c;

        cercano = 0;
        fans = false;
        ans.clear();
        visited.clear();

        dijkstra(agua);
        
        if(cercano)
            cout << ans[3] << " " << cercano << endl;
        else
            cout << 0 << " " << 0 << endl;
        
    }

  
    return 0;
}
