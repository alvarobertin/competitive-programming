#include <bits/stdc++.h>

using namespace std;

vector<int> tree;
vector<int> a;
void add(int, int, int);
int query(int);
int query(int, int);

//build
void build(int n){
  for(int i = 0; i < n; ++i)
    add(i, a[i], n);
}

//update the Fenwick tree
void add(int idx, int val, int n){
  while(idx < n){
    tree[idx] += val;
    idx = idx | (idx + 1); // f(x) = x | (x + 1)
  }
}

//simple query
int query(int r){
  int res = 0;
  while(r >= 0){
    res += tree[r];
    r = (r & (r + 1)) - 1; // r = g(x) - 1    g(x) = x & (x + 1)
  }
  return res;
}

//range query
int query(int l, int r){
  return query(r) - query(l - 1);
}

int main(){
    int n = 9, aux1, aux2,cases = 1;
    string op;


    cin >> n;
    while(n != 0){
        tree = vector<int> (210000, 0);
        a = vector<int> ();
        for (int i = 0; i < n; i++){
            cin >> aux1;
            a.push_back(aux1);
        }
        build(n);

        cin >> op;
        cout << "Case " << cases++ <<":" << endl;
        while(op != "END"){
            cin >> aux1 >> aux2;
            if(op == "M"){
                cout << query(aux1 - 1 , aux2 - 1 ) << endl;
            }else{
                add(aux1 - 1 , aux2 - query(aux1 - 1 , aux1 - 1 ), n);
            }
            cin >> op;
        }


        cin >> n;
        if(n) cout << endl;
    }

    return 0;
}


