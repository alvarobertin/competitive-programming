#include <bits/stdc++.h>

using namespace std;

int n;

struct Edge {
    int u, v, weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};

vector<Edge> edges;

int kruskal(){
        

    int cost = 0;
    vector<int> tree_id(n);
    vector<Edge> result;

    for (int i = 0; i < n; i++)
        tree_id[i] = i;
    sort(edges.begin(), edges.end());

    for (Edge e : edges) {
        if (tree_id[e.u] != tree_id[e.v]) {
            cost += e.weight;
            result.push_back(e);

            int old_id = tree_id[e.u], new_id = tree_id[e.v];
            for (int i = 0; i < n; i++) {
                if (tree_id[i] == old_id)
                    tree_id[i] = new_id;
            }
        }
    }
    return cost;
}

vector<string> keys;

int distancia(string a, string b){
    int acum = 0;
    for (int k = 0; k < 4; k++){
        acum += min( abs( (a[k] - '0') - (b[k] - '0') ) , 10 - abs( (a[k] - '0') - (b[k] - '0') )  );
    }
    
    return acum;
}

int main(){
    int m, i, k, q, aux1, aux2, peso, cases;
    double iniciox, inicioy, schoolx, schooly;
    
    string line;

    cin >> cases;
    while(cases--){

        keys.clear();
        edges.clear();

        cin >> n;

        for ( i = 0; i < n; i++){
            cin >> line;
            keys.push_back(line);
        }
        
        Edge temp;
        for (int i = 0; i < keys.size(); i++){
            for (int j = 0; j < keys.size(); j++){
                if(i != j){

                    temp.u = i;
                    temp.v = j;
                    temp.weight = distancia(keys[i], keys[j]);
                    
                    edges.push_back(temp);
                }   
            }
        }
        n = keys.size();

        int res = 0;
        int mins = 999999999;
        int mini = 0;
        for (int i = 0; i < n; i++){
            if(distancia("0000", keys[i]) < mins){
                mins = distancia("0000", keys[i]);
                mini = i;
            }
            
        }

        res = kruskal();

        cout << res + mins << endl;

        
    }
  

  
    return 0;
}
