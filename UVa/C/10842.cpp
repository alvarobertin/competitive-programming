#include <climits>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct Arista{
  int u, v, peso;

  Arista(){}

  Arista(int x, int y, int p){
    u = x;
    v = y;
    peso = p;
  }

  bool operator<(Arista& a){
    return peso < a.peso;
  }
};

int n, total;
vector<Arista> aristas;
vector<int> idArbol(50000);
vector<Arista> mst;

void kruskal(){
  int i, u, v, p1, p2;
  
  for(i = 0; i < n; ++i)
    idArbol[i] = i;

  sort(aristas.begin(), aristas.end());

  for(vector<Arista>::iterator it = aristas.begin(); it != aristas.end(); ++it){
    u = it->u;
    v = it->v;

    if(idArbol[u] != idArbol[v]){
      mst.push_back(*it);
      total += it->peso;

      p1 = idArbol[u];
      p2 = idArbol[v];
      for(i = 0; i < n; ++i)
	if(idArbol[i] == p2)
	  idArbol[i] = p1;
    }
  }
}

int main(){
  int m, i, aux1, aux2, peso, cases, ans;


    cin >> cases;

    for (int x = 1; x <= cases; x++){
        aristas = vector<Arista>();
        mst = vector<Arista> ();
        ans = 1000;
        cin >> n >> m;
        for(i = 0; i < m; i++){
            cin >> aux1 >> aux2 >> peso;
            aristas.push_back(Arista(aux1, aux2, peso*-1));
        }
        kruskal();

        for(i = 0; i < mst.size(); ++i){
            if(mst[i].peso*-1 <= ans){
                ans = mst[i].peso*-1;
            }
        }
        cout << "Case #" << x << ": " << ans << endl;
    }
  
  
  return 0;
}
