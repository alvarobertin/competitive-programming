#include <bits/stdc++.h>

using namespace std;

int main(){


    map<string, string> mapa;
    
    string entrada, entrada2;
    cin >> entrada;
    cin >> entrada2;

    mapa[entrada] = entrada2;
    
    mapa.clear();

    cout << mapa[entrada] << endl;


    return 0;
}