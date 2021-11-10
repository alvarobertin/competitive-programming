#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> mem;
vector<int> price, weight;

int memo(int m, int n){

    if(mem[m][n] != -1) return mem[m][n];
    else{
        if(!n){
            if(m >= weight[n]) mem[m][n] = price[n];
            else{
                mem[m][n] = 0;
            }
            return mem[m][n];
        }else{
            if(m >= weight[n]) mem[m][n] = max(memo(m, n - 1) , memo(m - weight[n], n - 1) + price[n] );
            else{
                mem[m][n] = memo(m, n - 1);
            }
            return mem[m][n];
        }
    }
}


int main(){

    
    int T, N, P, W, G, MW, res;

    cin >> T;

    while(T--){
        price = vector<int>();
        weight = vector<int>();
        cin >> N;

        for (int i = 0; i < N; i++){
            cin >> P >> W;
            price.push_back(P);
            weight.push_back(W);
        }
        
        cin >> G;
        res = 0;
        for (int z = 0; z < G; z++){
            cin >> MW;

            mem = vector<vector<int>> (MW + 1, vector<int>(N + 1, -1));   

            res += memo(MW, N - 1);
 

        }
        
        cout << res << endl;

    }



    return 0;
}