#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

bool diff(string a, string b){
    int dif = 0;
    for (int i = 0; i < a.length(); i++){
        if(a[i] != b[i])
            dif++;
        if(dif > 1)
            return false;
    }
    if(dif > 1)
        return false;    
    return true;
}

int main(){

	int N, C, Q;

    string word;
    vector<string> words;

	map<string, vector<string>> conex;

	queue<string> cola;

    cin >> N;

	while(N--){
        
		conex.clear();

        cin >> word;
		while (word != "*"){
            words.push_back(word);
            cin >> word;
		}


        /*While o for? donde termina input de cases*/
        while (int z = 0; z < Q; z++){
        
            string startNode, endNode;
        
            cin >> startNode >> endNode;

            
            while(!cola.empty())
                cola.pop();

            cola.push(startNode);
            
            map<string, int> visited;

            visited[startNode] = 1;
            
            unordered_map<string, string> father;
            
            father[startNode] = startNode;
            
            while( !cola.empty() ){

                string node = cola.front();

                cola.pop();

                if(node == endNode){
                    break;
                } 
        
                for(auto i = 0; i < conex[node].size(); ++i){

                    string aux = conex[node][i];

                    if( visited[aux] != 1 ){
                        cola.push(aux);
                        visited[aux] = 1;
                        father[aux] = node;
                    }
                
                }
            
            }

            
            vector<string> route;
            string node = endNode;
            while(node != startNode and father[node] != node){
                route.push_back(node);
                node = father[node];
            }
            route.push_back(startNode);
            reverse(route.begin(), route.end());

            for (int i = 0; i < route.size(); i++){
                cout << route[i][0];
            }
            cout << '\n';
        
            
        }
        if(N)
            cout << '\n';

	}

	return 0;
}