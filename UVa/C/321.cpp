#include <bits/stdc++.h>

using namespace std;

int r, acum, de, cercano;
bool fans;
vector<vector<int>> conex(12);
vector<vector<int>> luz(12);
vector<int> ans(4);
pair<int, string> res;
//map<pair<int, pair<int, string>>, int> visited;
map<pair<int, string>, int> visited;
map<pair<int, string>, pair<int, string>> p;

string gen(int n){
    string s = "";
    for (int i = 0; i < n; i++){
        s += "0";
    }
    return s;
}

bool checkAns(pair<int, string> v){
    
    if(v.first != r - 1 ) return false;
    for (int i = 0; i < (v.second).size() - 1; i++){
        if(v.second[i] == '1') return false;
    }
    return true;

}

void bfs(pair<int, string> s){
    string binary, result;
    int i, j, k, peso, costo;
    pair<int, string> u, v;
    //, 
    queue<pair<int, string>>  cola;
    
    p[s] = s;

    cola.push(s);

    visited[s] = 1;
    
    while(!cola.empty()){
        u = cola.front();
        cola.pop();
        
        if(checkAns(u)){
            fans = true;
            res = u;
            break;
        }

        for(i = 0; i < conex[u.first].size(); i++){

            v = {conex[u.first][i], u.second};
            
            if(visited[v] == 0 && u.second[v.first] == '1' ){
                    visited[v] = 1;               
                    //cout << v.first << ": " << v.second << endl;
                    p[v] = u;

                    cola.push(v);
                    
            }
            
            for(j = 0; j < luz[u.first].size(); j++){
                result = u.second;
                if(result[luz[u.first][j]] ==  '1' && u.first != luz[u.first][j]) result[luz[u.first][j]] =  '0';
                else result[luz[u.first][j]] =  '1';
                
                v = {conex[u.first][i], result};
             
                if(visited[v] == 0 && result[v.first] == '1' ){
                    visited[v] = 1;               
                    //cout << v.first << ": " << v.second << endl;
                    p[v] = u;

                    cola.push(v);
                    
                }

            } 
        }
    }
}

int main(){
    int m, d, s, aux1, aux2, peso, cases = 1;


    cin >> r >> d >> s;

    while(r){

        fans = false;
        conex = vector<vector<int>> (12);
        luz = vector<vector<int>> (12);
        ans = vector<int> (4);
        //map<pair<int, pair<int, string>>, int> visited;
        visited.clear();
        p.clear();
        
        for (int i = 0; i < d; i++){
            cin >> aux1 >> aux2;
            aux1--;
            aux2--;
            conex[aux1].push_back(aux1);
            conex[aux1].push_back(aux2);
            conex[aux2].push_back(aux1);
            conex[aux2].push_back(aux2);
        }
        
        for (int i = 0; i < s; i++){
            cin >> aux1 >> aux2;
            aux1--;
            aux2--;
            luz[aux1].push_back(aux2);
        }
        string temp = gen(r);
        temp[0] = '1';

        pair<int, string> inicial = {0, temp};

        
        bfs(inicial);

        if(fans){

            pair<int, string> nodo = res;
            
            vector<pair<int, string>> path;
            while(nodo != p[nodo]){
                path.push_back(nodo);
                //cout << nodo.first << " " << nodo.second << endl;
                nodo = p[nodo];
            }
            path.push_back(nodo);
            //cout << nodo.first << " " << nodo.second << endl;

            reverse(path.begin(), path.end());

            int anterior = 0;
            temp = "";
            vector<string> impri;
            for (int i = 1; i < path.size(); i++){
                
                for (int j = 0; j < path[i].second.size(); j++){
                    if(path[i].second[j] == '1' && path[i - 1].second[j] == '0'){
                        temp = "- Switch on light in room ";
                        temp += to_string(j + 1); 
                        temp += ".";
                        impri.push_back(temp);
                        //cout << "- Switch on light in room " << j + 1 << "." << endl;
                    }else if(path[i].second[j] == '0' && path[i - 1].second[j] == '1'){
                        temp = "- Switch off light in room ";
                        temp += to_string(j + 1); 
                        temp += ".";
                        impri.push_back(temp);
                        //cout << "- Switch off light in room " << j + 1 << "." << endl;
                    }
                }
                
                if(path[i].first != path[i - 1].first){
                        temp = "- Move to room ";
                        temp += to_string(path[i].first + 1); 
                        temp += ".";
                        impri.push_back(temp);
                        //cout << "- Move to room " << path[i].first + 1 << "." << endl;
                }
            }

            cout << "Villa #" << cases++ << endl;
            cout << "The problem can be solved in " << impri.size() << " steps:" << endl;
            if(impri.size() > 0){
                cout << impri[0];
                for (int j = 1; j < impri.size(); j++){
                    cout << "\n" << impri[j]; 
                }
                cout << endl;
            }
        }else{
            cout << "Villa #" << cases++ << endl;
            cout << "The problem cannot be solved." << endl;
        }
        cout << endl;

        cin >> r >> d >> s;
    }

  
    return 0;
}
