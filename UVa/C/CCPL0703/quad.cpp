#include <bits/stdc++.h>
#define endl '\n'
#define vi vector<int>

using namespace std;


vector< pair<double, double> > points;

int tamanio = 0;

double maxacum = 0;

double dist(pair<double, double> a, pair<double, double> b){
    return sqrt((a.first - b.first)*(a.first - b.first) + (a.second - b.second)*(a.second - b.second));
}

void back1(int i, double acum, int tomados, vector< pair<double, double> > puntos){

    if(tomados == 2 && tamanio - i < 2) return;
    if(tomados == 1 && tamanio - i < 3) return;


    if(tomados == 5){


        acum *=  dist( puntos[0], puntos[tomados - 1] ) ;

        if(acum > maxacum)
            maxacum = acum;

        return;
    }

    if(i == tamanio) return;

    back1(i + 1, acum, tomados, puntos);
    
    if(puntos.size() > 0){
        acum *= dist( puntos[tomados - 1], points[i] );
    }
    puntos.push_back( points[i] );
    tomados++;

    back1(i + 1, acum, tomados, puntos);

}


int main(){

    int T, N;

    double X, Y;
    
    pair<double, double> test;

    cin >> T;


    while(T--){

        maxacum = 0;

        points.clear();

        cin >> N;

        for (int i = 0; i < N; i++){

            cin >> X >> Y;

            test.first = X;
            test.second = Y;

            points.push_back(test);
        }
        tamanio = points.size();
        vector< pair<double, double> > p;
        back1(0, 1.0, 0, p);


        cout << maxacum << endl;



    }



    return 0;
}