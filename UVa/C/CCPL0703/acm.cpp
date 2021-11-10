#include <bits/stdc++.h>

using namespace std;


int bits;

void back1(vector<string> &strings, int k, vector<string> acum, int &minacum){
    if(k == strings.size()){
        vector<int> temp(bits, 0);
        
        int p = 0;

        for (int i = 0; i < acum.size(); i++){
            for (int j = 0; j < acum[i].size(); j++){

                if(acum[i][j] == '1' && temp[j] == 0){
                    temp[j] = 1;
                    p++;
                }


            }

            
        }
        if(p == bits && acum.size() < minacum){
            minacum = acum.size();
        }
        return;
    }

    back1(strings, k + 1, acum, minacum);

    acum.push_back(strings[k]);
    back1(strings, k + 1, acum, minacum);
}

int main(){

    int C, n;
    string ent;

    vector<string> strings;
    vector<string> acum;
    int minacum;
    
    cin >> C;

    while(C--){
        strings.clear();
        acum.clear();

        minacum = 501;
        cin >> bits >> n;

        for (int i = 0; i < n; i++){
            cin >> ent;
            strings.push_back(ent);
        }

        back1(strings, 0, acum, minacum);

        if(minacum < 501)
            cout << minacum << endl;

        else
            cout << "-1" << endl;


    }








    return 0;
}