#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<int> nums, visitado, reset, reset2;
    for (int i = 0; i < 50000; i++){
        reset2.push_back(i + 1);
    }
    int cases, k, aux, s, acum;
    cin >> cases;
    while(cases--){
        cin >> k;
        nums = reset2;
        for (int i = 0; i < k; i++){
            cin >> s;
            acum = 1;
            if(!i) cout << nums[s];
            else cout << " " << nums[s];
            nums.erase(nums.begin() + s);
        }
        cout << '\n';
    }
    return 0;
}
