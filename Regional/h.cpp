#include <bits/stdc++.h>

using namespace std;

int maxi;
map<int, int> unli;
vector<vector<int>> adj(5000);
map<int, int> unos;

bool bfs(int s){
    int i, j, k, conteo, u, v, copyconteo, cont;
    maxi = 1;
    bool flag ;

    vector<vector<int>> mapa;

    queue< pair<int, pair< vector<vector<int>>, int> > > cola;

    /*
        Estado: int nodo, mapa vis, int num
        pair<int, pair< vector<vector<int>>, int> > estado;
    
    */

    cola.push({ 0, {adj, 1} });
    cont = 0;
    while(!cola.empty()){
        cont++;
        u = cola.front().first;
        mapa = (cola.front().second).first;
        conteo = (cola.front().second).second;
        cola.pop();

        for(i = 0; i < adj[u].size(); i++){
 
            v = adj[u][i];

            if(unli[u] == 1 && unli[v] == 1) return false;

            if(unos[v] == 0 && unos[u] == 0) break;

            if(v != -1){
                vector<vector<int>> copymapa = mapa;
                copyconteo = conteo;
                if(unli[u] == 1){
                    // cout << "bs";
                    // si tiene *
                    if(v == 0)
                        copyconteo += 1;
                    maxi = max(copyconteo, maxi);
                    cola.push({ v, {copymapa, copyconteo} });
                    
                }else{
                    

                    if( mapa[u][i] != -1 ){
                        // cout << "a";
                        if(v == 0){
                            copyconteo += 1;
                            unos[u]--;
                        }
                        maxi = max(copyconteo, maxi);
                        copymapa[u][i] = -1;
                        
                        cola.push({ v, {copymapa, copyconteo} });
                    }
                }
            }
        }

    }

    return true;
}

int main(){
    int n, aux1;
    char a;

    while(cin >> n){

        for (int i = 0; i < n; i++){
            cin >> a;
            if( a == '*'){
                cin >> aux1;
                adj[i].push_back(aux1 - 1);
                unli[i] = 1;
            }else{

                for (int j = 0; j < a - '0'; j++){
                    cin >> aux1;
                    adj[i].push_back(aux1 - 1);
                    if(aux1 - 1 == 0) unos[i]++;
                }
            }
        }
        

        if(bfs(0)){
            cout << maxi << endl;
        }else{
            if(maxi > 1)
                cout << maxi << endl;
            else
                cout << "*" << endl;
        }
    }

  
    return 0;
}
