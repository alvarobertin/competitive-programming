#include <bits/stdc++.h>

using namespace std;

vector<vector<string>> v;
vector<vector<int>> visited;
int I, J;

void ff(int i, int j, string a, string b){
    if( i < 0 || j < 0 || i >= I || j >= J)
        return;
    if(v[i][j] != a) return;
    v[i][j] = b;
    visited[i][j] = 1;

    ff(i - 1, j - 1, a, b);
    ff(i - 1, j, a, b);
    ff(i - 1, j + 1, a, b);

    ff(i, j - 1, a, b);
    ff(i, j + 1, a, b);

    ff(i + 1, j - 1, a, b);
    ff(i + 1, j, a, b);
    ff(i + 1, j + 1, a, b);

}

vector<int> espacios (void) {
    int max = 0;
    vector<int> res;
    for (int i = 0; i < J; i++){
        max = 0;
        for (int j = 0; j < I; j++){
            if(v[j][i].size() > max){
                max = v[j][i].size();
            }
        }
        res.push_back(max);
    } 
    return res;
}


int main() {
    string line;
    int num;
    vector<int> format;

    while( getline(cin, line) ){
        if( line == "%" ){
            I = v.size();
            J = v[0].size();
            num = 1;

            for (int i = 0; i < I; i++){
                for (int j = 0; j < J; j++){

                    if(visited[i][j] == 0){
                        ff(i, j, v[i][j], to_string(num));
                        num++;
                    }
                }
                
            }
            format = espacios();
            for (int i = 0; i < I; i++){
                cout.width(format[0]); cout << right << v[i][0];
                for (int j = 1; j < J; j++){
                    cout.width(format[j] + 1); cout << right << v[i][j]; 
                }
                cout << endl;
            }  
            

            v = vector<vector<string>>(0);
            visited = vector<vector<int>>(0);
            cout << "%" << endl;
        }
        else{
            stringstream ss(line);
            string aux;
            vector<string> aux2;
            vector<int> auxn;
            while(ss >> aux){
                aux2.push_back(aux);
                auxn.push_back(0);
            }
            v.push_back(aux2);
            visited.push_back(auxn);
        }
    }
    I = v.size();
    J = v[0].size();
    num = 1;

    for (int i = 0; i < I; i++){
        for (int j = 0; j < J; j++){

            if(visited[i][j] == 0){
                ff(i, j, v[i][j], to_string(num));
                num++;
            }
        }
        
    }
    format = espacios();
    for (int i = 0; i < I; i++){
        cout.width(format[0]); cout << right << v[i][0];
        for (int j = 1; j < J; j++){
            cout.width(format[j] + 1); cout << right << v[i][j]; 
        }
        cout << endl;
    }  

    cout << "%" << endl;

    return 0;
}