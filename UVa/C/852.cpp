#include <bits/stdc++.h>

using namespace std;

vector<string> v, w;
bool flag;
int I, J, numFichas, numVacios;

int dr[] = {0,1,0,-1};
int dc[] = {-1,0,1,0};

void ff2(int i, int j, char c){
    // Solo para .
    if( i < 0 || j < 0 || i >= I || j >= J)
        return;
    if(v[i][j] == 'v') return;

    if(w[i][j] != '.' && w[i][j] != c){
        flag = true;
        return;
    }

    if(w[i][j] == c) return;

    numVacios++;

    v[i][j] = 'v';

    for (int k = 0; k < 4; k++) ff2(i + dr[k], j + dc[k], c);

}

void ff(int i, int j, char c){
    // para O y X

    if( i < 0 || j < 0 || i >= I || j >= J)
        return;

    if(v[i][j] == 'v') return;

    if(c != w[i][j] &&  w[i][j] != '.') return;

    if( w[i][j] == '.'){
        flag = false;
        numVacios = 0;
        ff2(i, j, c);
        if(!flag) numFichas += numVacios;
        return;
    } 

    numFichas++;

    v[i][j] = 'v';

    for (int k = 0; k < 4; k++) ff(i + dr[k], j + dc[k], c);

}


int main() {
    string line;
    int cases, i, j, ansW, ansB;
    I = 9;
    J = 9;

    cin >> cases;

    while( cases-- ){
        ansW = ansB = 0;
        v = w = vector<string> ();
        
        for ( i = 0; i < 9; i++){
            cin >> line;
            w.push_back(line);
            v.push_back(line);
        }
        
        for ( i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                
                if(v[i][j] != 'v' && w[i][j] != '.'){
                    numFichas = 0;
                    numVacios = 0;
                    flag = false;
                    ff(i, j, w[i][j]);
                    if(w[i][j] == 'O'){
                        ansW += numFichas;
                    }else{
                        ansB += numFichas;
                    }           
                }
            }       
        }
        cout <<"Black " << ansB << " White " << ansW << endl;
    }
    return 0;
}