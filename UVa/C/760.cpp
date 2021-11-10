#include <bits/stdc++.h>

using namespace std;

string s1, s2;
int size1, size2;

pair<string, int> common(int i, int k){

    int sizeres = 0; 
    string res = "";
    while(i < size1 && k < size2){
        if(s1[i] != s2[k]){
            break;
        }
        res += s1[i];
        sizeres++;
        i++;
        k++;
    }
    return {res, sizeres};
}

int main(){

    bool flag = false;
    while(cin >> s1){
        cin >> s2;
        set<string> varias;
        if(flag) cout << '\n';
        flag = true;
        size1 = s1.size();
        size2 = s2.size();
        pair<string, int> res;
        int j = 0, maxlen = 0;
        for (int i = 0; i < size1; i++){
            for (int k = 0; k < size2; k++){
                if(s1[i] == s2[k]){
                    res = common(i, k);
                    if(res.second == maxlen){
                        varias.insert(res.first);
                    }else if(res.second > maxlen){
                        maxlen = res.second;
                        varias = set<string> ();
                        varias.insert(res.first);
                    }
                }
            }
        }
        if(varias.size() > 0){
            for (set<string>::iterator it = varias.begin(); it != varias.end(); it++){
                cout << *it << endl;
            }
        }else{
            cout << "No common sequence." << endl;
        }
    }
  
    return 0;
}
