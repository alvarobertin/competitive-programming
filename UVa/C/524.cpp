#include <bits/stdc++.h>

#define endl '\n'

#define vi vector<int>

using namespace std;

vector<vi> Ans;

bool primo(int a){
    if(a == 2 || a == 3 || a == 5 || a == 7 || a == 11 || a == 13 || a == 17 || a == 19 || a == 23 || a == 29 || a == 31)
        return true;
    return false;
}

void back1(int N, vi res, vi acum){

    if(acum.size() == N){
        Ans.push_back(acum);
        return;
    }

    for (int i = 2; i <= N; i++){
        if( primo(i + acum[acum.size() - 1]) && res[i]){
            if( acum.size() + 1 == N ){
                if(primo(1 + i)){
                    res[i] = 0;
                    acum.push_back(i);
                    
                    back1(N, res, acum);
                    
                    res[i] = 1;
                    acum.pop_back();                            
                }
            }
            else{
                res[i] = 0;
                acum.push_back(i);
                
                back1(N, res, acum);
                
                res[i] = 1;
                acum.pop_back();                 
            }
        }
    }
}

int main(){

    int N, c = 1;

    while(cin >> N){
        

        vi res(N + 1, 1), acum;

        acum.push_back(1);

        back1(N, res, acum);

        if(c == 1)
            cout << "Case " << c++ << ":" << endl;
        else
            cout << "\nCase " << c++ << ":" << endl;

        for (int i = 0; i < Ans.size(); i++){
            
            cout << Ans[i][0];

            for (int j = 1; j < Ans[i].size(); j++){

                cout << " " << Ans[i][j];

            }

            cout << endl;
            
        }
        
        Ans.clear();

    }


	return 0;
}