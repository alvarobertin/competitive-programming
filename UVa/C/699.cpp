#include <bits/stdc++.h>

using namespace std;

map<int, pair<int, int>> binary;
map<int, int> values, ans;
int id;

void DFS(int root, int set){
    if(binary.find(root) == binary.end()) return;

    ans[set] += values[root];
    if(binary[root].first != -1)
        DFS(binary[root].first, set - 1);
    if(binary[root].second != -1)
        DFS(binary[root].second, set + 1);
}


void recur(int root){
    
    int izq, der, idtemp;
    cin >> izq;
    if(izq != -1){
        binary[root].first = id;
        idtemp = id++;
        values[idtemp] = izq;
        recur(idtemp);
    }else{
        binary[root].first = -1;
    }

    cin >> der;
    if(der != -1){
        binary[root].second = id;
        idtemp = id++;
        values[idtemp] = der;
        recur(idtemp);
    }else{
        binary[root].second = -1;
    }

}

int main(){
    int root, idRoot, cases = 1;
    map<int, int>::iterator it;
    cin >> root;
    
    while(root != -1){
        binary = map<int, pair<int, int>> ();
        ans = map<int, int> ();
        values = map<int, int> ();
        id = 0;
        values[id] = root;
        idRoot = id++;
        recur(idRoot);

        DFS(idRoot, 0);
        
        printf("Case %d:\n", cases++);
        it = ans.begin();
        printf("%d", (*it).second);
        it++;
        for ( ; it != ans.end(); it++){
            printf(" %d", (*it).second);
        }
        printf("\n\n");

        cin >> root;
    }

	return 0;
}