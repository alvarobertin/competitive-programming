#include <bits/stdc++.h>

using namespace std;



int main(){

    int cases, E, P;
    cin >> cases;

    while(cases--){
            
        cin >> P >> E;
        if(P - E >= 10) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}