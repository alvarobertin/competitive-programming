#include <bits/stdc++.h>

using namespace std;

int main(){

    long long int A, B;
    
    cin >> A >> B;
    while(A || B){
        if(B == 1)
            cout << A << "i" << endl;
        else if(B == 2)
            cout << A*-1 << endl;
        else if(B % 2 == 0){
            if( (B/2) % 2 == 0 )
                cout << A << endl;
            else
               cout << A*-1 << endl;
        }
        else{
            if(B-1 == 2)
                cout << A*-1 << "i" << endl;
            else if( (((B-1)/2) % 2) == 0 )
                cout << A << "i" << endl;
            else
               cout << A*-1 << "i" << endl;
        }
        cin >> A >> B;
    }
    return 0;
}