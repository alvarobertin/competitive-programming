#include <bits/stdc++.h>

using namespace std;

vector<string> w;

int I, J;

int dr[] = {-1,0,0,1};
int dc[] = {0,1,-1,0};
vector<vector<int>> visited(5000);

vector<pair<int, int>> A;
map<pair<int,int>, int> etiquetas;

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

void ini(){
    visited = vector<vector<int>>();
    for (int i = 0; i < 500; i++){
        visited.push_back(vector<int>(500, -1));
    }
}

bool SePuede(int i, int j){
    if( i < 0 || j < 0 || i >= I || j >= J) return false;
    if(w[i][j] == '#') return false;
    if(visited[i][j] != -1) return false;

    return true;
}

int main() {
    string line;
    int cases;

    cin >> cases;


    while( cases-- ){


        cin >> J >> I;
        cin.ignore();

        A = vector<pair<int, int>>();
        etiquetas.clear();

        w.clear();
        
        for(int i = 0; i < I; i++){
            getline(cin, line);
            w.push_back(line);            
        }
        int a = 0, b = 0, pos = 0;
        for (int i = 0; i < I; i++){
            for(int j = 0; j < w[i].size(); j++){
                if(w[i][j] == 'S' || w[i][j] == 'A'){
                    A.push_back({i,j});
                    etiquetas[{i,j}] = pos++;
                }
            }

        }
        Edge temp;
        for (int i = 0; i < A.size(); i++){
            
            queue<pair<int, int> > cola;
            pair<int, int> startNode = {A[i].first, A[i].second} ;
            ini(); 
        
            while(!cola.empty())
                cola.pop();

            cola.push(startNode);
            

            visited[startNode.first][startNode.second] = 0;
                    
            while( !cola.empty() ){

                pair<int, int> node = cola.front();

                cola.pop();

                for (int x = 0; x < 4; x++){
                    int tempi = node.first + dr[x];
                    int tempj = node.second + dc[x];
                    if(SePuede(tempi, tempj) ){
                        cola.push({tempi, tempj});
                        
                        visited[tempi][tempj] = visited[node.first][node.second] + 1;

                        if( (w[tempi][tempj] == 'A' || w[tempi][tempj] == 'S') ){
                            
                            int v = etiquetas[{startNode.first, startNode.second}];
                            int w = etiquetas[{tempi, tempj}];

                            temp.u = v;
                            temp.v = w;
                            temp.weight = visited[tempi][tempj];
                            
                            edges.push_back(temp);

                            temp.u = w;
                            temp.v = v;
                            temp.weight = visited[tempi][tempj];
                            
                            edges.push_back(temp);
                            
                        }
                        
                    }
                }
        
            }

        }

        // for (Edge e : edges) {
        //     cout << e.weight << endl;
        // }

        n = edges.size(); 
        int res = kruskal();        

        cout << res << endl;

        edges.clear();

    }

    return 0;
}