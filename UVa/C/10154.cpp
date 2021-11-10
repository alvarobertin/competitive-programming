#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> vec;

int N;

int tab(){
    vector<int> a(vec.size());
    int ans = 0;
    for (int n = 0; n < a.size(); n++){
        a[n] = 1;
        for (int i = 0; i < n; i++){
            if(vec[n] >= vec[i] && a[i] >= a[n]) a[n] = a[i] + 1;
        }
        ans = max(a[n], ans);
    }
    return ans; 
}

int res(int n, int S){

    if(n == N) return 0;

    if(n != N){

        if(vec[n].second > S) return res(n + 1, S);
        if(vec[n].second <= S) return max(res(n + 1, S), 1 + res(n + 1,  min(S- vec[n].second, vec[n].first - vec[n].second) ) );


    }
    return 0;

}

def morralTabOpt(M, N, w, b):
    tab = [0 for _ in range(M + 1)]

    for n in range(0, N):
        for m in range(M, -1, -1):
            if m - w[n] >= 0: tab[m] = max(tab[m], tab[m - w[n]] + b[n])

    return tab[M]


int main(){

    int w, s;

    while(cin >> w >> s){
        vec.push_back({s, w});
    }

    sort(vec.begin(), vec.end());


    return 0;
}