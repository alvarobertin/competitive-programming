#include <bits/stdc++.h>

using namespace std;

vector<string> v, w;

int I, J;

int dr[] = {1,1,0,-1,-1,-1,0,1};
int dc[] = {0,1,1,1,0,-1,-1,-1};

int ff(int i, int j){
    char a = 'W';
    char b = 'L';
    if( i < 0 || j < 0 || i >= I || j >= J)
        return 0;
    if(v[i][j] != a) return 0;
    int ans = 1;

    v[i][j] = b;

    for (int k = 0; k < 8; k++){
        ans += ff(i + dr[k], j + dc[k]);
    }

    return ans;
}


int main() {
    string line;
    int cases, i, j;

    cin >> cases;
    cin.ignore();
    cin.ignore();

    while( cases-- ){
        w.clear();
        
        getline(cin, line);

        while (line[0] == 'W' || line[0] == 'L'){
            w.push_back(line);
            getline(cin, line);            
        }

        I = w.size();
        J = w[0].size();

        while (line != ""){

            stringstream ss(line);
            string aux;
            ss >> i;
            ss >> j;
            
            v = w;
            
            cout << ff(i - 1, j - 1) << endl;
            
            getline(cin, line);
        }
        if(cases)
            cout << '\n';
    }

    return 0;
}