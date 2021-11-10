#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main(){

    int K, diva, divb, a, b;

    cin >> K;
    while(K){

        cin >> diva >> divb;


        for ( int i = 0; i < K; i++){
            
            cin >> a >> b;

            if(a == diva || b == divb)
                cout << "divisa" << endl;
            else if(a > diva && b > divb)
                cout << "NE" << endl;
            else if(a < diva && b > divb)
                cout << "NO" << endl;
            else if(a < diva && b < divb)
                cout << "SO" << endl;
            else
                cout << "SE" << endl;
        }
        
        cin >> K;
    }


    return 0;
}