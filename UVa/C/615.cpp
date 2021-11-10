#include <bits/stdc++.h>
using namespace std;

map<int, vector<int>> adj;
map<int, int> inde;
set<int> nodes;
bool ans;

bool BFS(){

    queue<int> cola;
    map<int, int> visi;
    int inicial, u, v;

    for (set<int>::iterator it = nodes.begin(); it != nodes.end(); it++){
        
        if( inde.find(*it) == inde.end()) {
            inicial = *it;
            break;
        }
    }
    
    visi[inicial] = 1;
    cola.push(inicial);


    while(!cola.empty()){
        
        u = cola.front();
        cola.pop();

        for (int i = 0; i < adj[u].size(); i++){
            v = adj[u][i];

            if(visi[v] != 1){
                visi[v] = 1;
                cola.push(v);
            }else{
                return false;
            }
        }
        
    }

    for (set<int>::iterator it = nodes.begin(); it != nodes.end(); it++){
        if( visi.find(*it) == visi.end()) {
            return false;
        }
    }


    return true;
}


int main() {

    int aux1, aux2, cases;

    cases = 1;
    cin >> aux1 >> aux2;
    while(aux1 > -1){
        ans = true;
        adj = map<int, vector<int> > ();
        inde = map<int, int> ();
        nodes = set<int> ();

        while( aux1 != 0){
            
            adj[aux1].push_back(aux2);
            inde[aux2]++;
            
            nodes.insert(aux1);
            nodes.insert(aux2);

            if(inde[aux2] > 1) ans = false;

            cin >> aux1 >> aux2;
        }

        if(ans) ans = BFS();  

        if(ans) printf("Case %d is a tree.\n", cases++);
        else printf("Case %d is not a tree.\n", cases++);

        cin >> aux1 >> aux2;
    }



    return 0;
}