#include <bits/stdc++.h>

using namespace std;

int n, groups;

struct Edge {
    int u, v;
    double weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};

vector<Edge> edges;
vector<pair<int, int>> cords;

int check(vector<int> tr){
    set<int> te;
    for (int i = 0; i < n; i++){
        te.insert(tr[i]);
    }
    return te.size();
}

double kruskal(){
        
    double cost = 0;
    vector<int> tree_id(n);
    vector<Edge> result;

    for (int i = 0; i < n; i++)
        tree_id[i] = i;
    sort(edges.begin(), edges.end());

    for (Edge e : edges) {
        if(check(tree_id) == groups)
            break;

        if (tree_id[e.u] != tree_id[e.v] ) {
            
            if(cost < e.weight) cost = e.weight;

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

double r(double a){
    double v = (int)(a * 100 + .5);
    return (double)v/100;
}

double distancia(int i, int j){
    long double a = pow((cords[i].first - cords[j].first), 2);
    long double b = pow((cords[i].second - cords[j].second), 2);
    long double c;
    c = a + b;
    return sqrt(c);
}

int main(){
    int m, i, k, q, aux1, aux2, peso, cases;
    double res;
    
    
    string line;

    cin >> cases;
    while(cases--){

        edges.clear();
        cords.clear();

        cin >> groups;

        Edge temp;
        cin >> aux1;
        while(aux1 != -1){
            cin >> aux2;
            cords.push_back({aux1, aux2});
            cin >> aux1;
        }
        
        
        for (int i = 0; i < cords.size(); i++){
            for (int j = 0; j < cords.size(); j++){
                if(i != j){

                    temp.u = i;
                    temp.v = j;
                    temp.weight = distancia(i, j);
                    
                    edges.push_back(temp);
                }   
            }
        }
        n = cords.size();

        res = kruskal();

    
        cout << ceil(res) << endl;

        
    }
  

  
    return 0;
}
