#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, res, a, b, c;

    cin >> N;
    while(N){
        res = 0;
        vector<int> v;

        for (int i = 0; i < N; i++){
            cin >> a;
            v.push_back(a);
        }
        for(int i = 0; i < N; i++){
            a = v[i];
            b = v[(i + 1) % N];
            c = v[(i + 2) % N];

            if(a < b && b > c) res++;
            else if(a > b && b < c) res++;
        }
        cout << res << endl;

        cin >> N;
    }

    return 0;
}