#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main(){

    int N;

    long long int a, b;

    cin >> N;

    while(N--){

        cin >> a >> b;

        if(a > b)
            cout << ">" << endl;
        else if(a < b)
            cout << "<" << endl;
        else
            cout << "=" << endl;


    }


    return 0;
}