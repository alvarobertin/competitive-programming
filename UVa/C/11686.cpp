#include <vector>
#include <map>
#include <string>
#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

int MAX = 10000000;
int n, t = 0;
vector<vector<int>> adj(MAX);
vector<int> inc(MAX, 0);
vector<int> topo;

int main(){
    int m, u, v, i, j, vis;
    queue<int> cola;

    cin >> n >> m;
    while(n != 0 || m != 0){
        
        vis = 0;
        topo.clear();
        for( i = 0; i <= n; i++ ){
            inc[i] = 0;
            adj[i].clear();
        }

        for(i = 0; i < m; i++){
            cin >> u >> v;
            adj[u - 1].push_back(v - 1);
            ++inc[v - 1];
        }

        for(i = 0; i < n; ++i){
            if(inc[i] == 0)
                cola.push(i);
        }

        while(!cola.empty()){
            v = cola.front();
            cola.pop();
            topo.push_back(v);
            for(i = 0; i < adj[v].size(); ++i){
                u = adj[v][i];
                --inc[u];
                if(inc[u] == 0)
                    cola.push(u);
            }
            ++vis;
        }

        if(vis != n)
            printf("IMPOSSIBLE\n");
        else{
            for(i = 0; i < n; ++i)
                printf("%d\n", topo[i] + 1);
        }

        cin >> n >> m;
    }


    

  return 0;
}
