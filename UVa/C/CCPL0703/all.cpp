#include <bits/stdc++.h>

using namespace std;

bool div(int a, int b, int c){
    if((a - b) % c != 0)
        return false;
    return true;
}

int main(){
    int n, temp;
    cin >> n;
    vector <int> vec;
    while(n--){
        cin >> temp;
        vec.push_back(temp);
    }

    bool flag = true;

    for(int i = 0; i < vec.size(); i++){
        for(int j = 0; j < vec.size(); j++){
            for(int k = 0; k < vec.size(); k++){
                if(i != j && i != k && k != j){
                    if(!(div(vec[i], vec[j], vec[k])))
                        flag = false;
                }
            }
        }
    }
    
    if(flag)
        printf("yes\n");
    else
        printf("no\n");

    return 0;
}