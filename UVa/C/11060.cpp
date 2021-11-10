#include <vector>
#include <map>
#include <string>
#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

int MAX = 10000;
int n, t = 0;
vector<vector<int>> adj(MAX);
map<string, int> names;
vector<int> inc(MAX, 0);
vector<int> topo;
vector<string> bevs;

int main(){
    int m, u, v, i, j, vis = 0, cases = 1;
    string name, a, b;
    priority_queue <int, vector<int>, greater<int> > cola;

    while(cin >> n){
        vis = 0;
        topo.clear();
        names.clear();
        bevs.clear();
        for( i = 0; i <= n; i++ ){
            inc[i] = 0;
            adj[i].clear();
        }

        for ( i = 0; i < n; i++){
            cin >> name;
            names[name] = i;
            bevs.push_back(name);
        }

        cin >> m;

        for ( i = 0; i < m; i++){
            cin >> a >> b;
            adj[ names[a] ].push_back( names[b] );
            ++inc[ names[b] ];
        }

        for(i = 0; i < n; ++i){
            if(inc[i] == 0){
                cola.push(i);
            }
        }
        
        while(!cola.empty()){
            v = cola.top();
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
            printf("Hay un ciclo\n");
        else{
            printf("Case #%d: Dilbert should drink beverages in this order: ", cases++);
            for(i = 0; i < n; ++i)
                printf("%s%s", bevs[topo[i]].c_str(), (i == n - 1) ? ".\n" : " ");

            printf("\n");
        }
    }


    


  return 0;
}
