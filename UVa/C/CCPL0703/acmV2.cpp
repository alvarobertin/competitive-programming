#include <bits/stdc++.h>

using namespace std;


vector<int> nums;

int conv(string str){
    int res = 0, pot = 0;
    for(int i = str.size() - 1; i >= 0; i--){
        int temp = str[i] - '0';
        res += temp * pow(2, pot);
        pot++;
    }
    return res;
}

int minacum = 501;
int bits;

bool ors(vector<int> vec){
    int n;
    
    n = vec[0];

    for (int i = 1; i < vec.size(); i++){
        n = n | vec[i];
    }
    if(n == bits) return true;
    
    return false;

}


void back1(int i, vector<int> acum, int minc){

    if(i == nums.size() + 1) return;

    if(nums[i] == bits){
        minacum = 1;
        return;
    }

    if(minc > 1){

        if( ors(acum) ){
            
            if(minc < minacum){
                minacum = minc;
            }
            return;
        }
    }
    back1(i + 1, acum, minc);

    acum.push_back(nums[i]);
    minc++;

    back1(i + 1, acum, minc);


}

int main(){

    int C, n;
    string ent;
    vector<int> y;
    
    cin >> C;

    while(C--){
        minacum = 501;
        nums.clear();

        cin >> bits >> n;


        for (int i = 0; i < n; i++){
            cin >> ent;
            nums.push_back(conv(ent));
            cout << " num:"<< conv(ent) << endl;
        }

        bits = pow(2, bits) - 1;
        
        back1(0, y, 0);

        if(minacum < 501)
            cout << minacum << endl;
        else
            cout << -1 << endl;
    }


    return 0;
}