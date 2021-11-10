#include <bits/stdc++.h>

using namespace std;

int main(){
    int cases;
    pair<long long int, long long int> left, mid, right;
    string P;
    cin >> cases;
    while(cases--){
        cin >> P;

        left = {0,1};
        mid = {1,1};
        right = {1,0};
        for (int i = 0; i < P.size(); i++){
            if(P[i] == 'R'){
                left = mid;
                mid = {left.first + right.first, left.second + right.second};
            }else{
                right = mid;
                mid = {left.first + right.first, left.second + right.second};
            }
        }
        cout << mid.first << "/" << mid.second << endl;
    }
    return 0;
}
