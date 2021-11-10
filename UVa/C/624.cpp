#include <bits/stdc++.h>

#define endl '\n'

#define vi vector<int>

using namespace std;

vi resglo;

int maxacum = 0, maxi = 0;


void back1(int N, vi Tracks, int i, int acum, vi res){
    
    if(acum > N ) return;

    if(Tracks[i] == N){

        maxacum = N;
        resglo.clear();
        resglo.push_back(N);
        
        return;
    }
    else if(res.size() >= maxi && acum == N){
        maxi = res.size();
        resglo = res;
        maxacum = acum;
    
    }else if(acum > maxacum){
        maxi = res.size();
        resglo = res;
        maxacum = acum;
        
    }
    
    if(i == Tracks.size()) return;

    back1(N, Tracks, i + 1, acum, res);

    res.push_back(Tracks[i]);

    back1(N, Tracks, i + 1, acum + Tracks[i], res);

}

int main(){

    int N, temp, T;

    vi Tracks;

    while(cin >> N){
        resglo.clear();
        Tracks.clear();    
        maxacum = 0;    
        maxi = 0;
        
        cin >> T;

        for (int i = 0; i < T; i++){
            cin >> temp;
            Tracks.push_back(temp); 
        }

        back1(N, Tracks, 0, 0, resglo);

        cout << resglo[0];

        for (int i = 1; i < resglo.size(); i++){
            cout << " " << resglo[i];
        }
        
        cout << " sum:" << maxacum << endl; 
        
    }


	return 0;
}