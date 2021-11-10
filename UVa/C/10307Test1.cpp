#include <bits/stdc++.h>

using namespace std;

vector<string> v, w;

int I, J;

int dr[] = {-1,0,0,1};
int dc[] = {0,1,-1,0};

vector<vector<int>> visited(5000);
vector<pair<int, int>> A;

void ini(){
    visited = vector<vector<int>>();
    for (int i = 0; i < 500; i++){
        visited.push_back(vector<int>(500, -1));
    }
}

void ff(int i, int j, int k, int l){
    if( i < 0 || j < 0 || i >= I || j >= J)
        return;
    if(w[i][j] == '#')
        return;

    if(visited[i][j] == -1){
        visited[i][j] = visited[k][l] + 1;
    }else{
        visited[i][j] = min(visited[k][l] + 1, visited[i][j]);
        return;
    }

    for (int x = 0; x < 4; x++){
        ff(i + dr[x], j + dc[x], i, j);    
    }

    return;
}


int main() {
    string line;
    int cases;

    cin >> cases;


    while( cases-- ){

        ini();

        cin >> J >> I;
        cin.ignore();

        w.clear();
        
        for(int i = 0; i < I; i++){
            getline(cin, line);
            w.push_back(line);            
        }
        int a = 0, b = 0;
        for (int i = 0; i < I; i++){
            for(int j = 0; j < w[i].size(); j++){
                if(w[i][j] == 'S'){
                    a = i;
                    b = j;
                }else if( w[i][j] == 'A'){
                    A.push_back({i,j});
                }
            }

        }
        
        ff(a , b, a, b);

        for (int i = 0; i < A.size(); i++){
            cout << visited[A[i].first][A[i].second] << endl;
        }
    


        if(cases)
            cout << '\n';
    }

    return 0;
}