#include <bits/stdc++.h>

using namespace std;

int n, ans;
vector<vector<int> > adj(11000);
vector<int> visi(11000);

void dfsAux(int v, int padre){
  int w, i;

  for(i = 0; i < adj[v].size(); ++i){
    w = adj[v][i];
    if(w != padre && visi[w] != 1){
        ans++;
        visi[w] = 1;
        dfsAux(w, v);
    }
  }
}

int main(){
    
    int cases, n, m, l, aux1, aux2;


    cin >> cases;

    while(cases--){
        adj = vector<vector<int> > (11000);
        visi = vector<int> (11000, 0);
        ans = 0;
        vector<int> hand;

        cin >> n >> m >> l;

        for (int i = 0; i < m; i++){
            cin >> aux1 >> aux2;
            adj[aux1].push_back(aux2);
        }
        for (int i = 0; i < l; i++){
            cin >> aux1;
            if(visi[aux1] != 1){     
                visi[aux1] = 1;  
                ans++;     
                dfsAux(aux1, -1);
            }
        }
        
        cout << ans << endl;


    }

    
    
    return 0;
}
