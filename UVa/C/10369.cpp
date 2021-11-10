#include <climits>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

struct Arista{
  int u, v;
  double peso;

  Arista(){}

  Arista(int x, int y, double p){
    u = x;
    v = y;
    peso = p;
  }

  bool operator<(Arista& a){
    return peso < a.peso;
  }
};

int n, numConjuntos, satellites;
double total;
vector<Arista> aristas;
vector<int> idArbol(50000);
vector<Arista> mst;

void kruskal(){
    int i, u, v, p1, p2;
    total = 0;
    mst = vector<Arista> ();

    for(i = 0; i < n; ++i)
        idArbol[i] = i;

    sort(aristas.begin(), aristas.end());

    for(vector<Arista>::iterator it = aristas.begin(); it != aristas.end(); ++it){

        u = it->u;
        v = it->v; 

        if(idArbol[u] != idArbol[v]){
            mst.push_back(*it); 

            if(it->peso > total)
                total = it->peso;
            numConjuntos -= 1;
            if(numConjuntos == satellites)
                break;

            p1 = idArbol[u];
            p2 = idArbol[v];
            for(i = 0; i < n; ++i){
                if(idArbol[i] == p2){
                    idArbol[i] = p1;       
                }
            }
        }
    }
}

int main(){
    int m, i, aux1, aux2, peso, cases;

    vector<pair<int, int>> coordinates;

    pair<int, int> temp;

    cin >> cases;
    while(cases--){
        aristas = vector<Arista>();
        coordinates = vector<pair<int, int>> ();

        cin >> satellites >> n;

        numConjuntos = n;

        for (int i = 0; i < n; i++){
            cin >> aux1 >> aux2;
            
            temp.first = aux1;
            temp.second = aux2;
            coordinates.push_back(temp);
        }
        
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if(j != i){
                        double a = pow((coordinates[i].first - coordinates[j].first), 2);
                        double b = pow((coordinates[i].second - coordinates[j].second), 2);
                        aristas.push_back(Arista(i, j, sqrt(a + b)));
                }   
            }
        }
        kruskal();

        printf("%.2f\n", total);
    }

  return 0;
}
