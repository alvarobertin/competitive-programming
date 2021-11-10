#include <bits/stdc++.h>

using namespace std;

int main(){

	int N, C, Q, base, n;

	string nodo, a, b;

	map<int, vector<int>> conex;

	queue<int> cola;
	bool first = true, flag;


	while(cin >> N){
        
		conex.clear();

		for (int i = 0; i < N; ++i){

			cin >> nodo;
            a = "";
            b = "";
            for (int j = 0; nodo[j] != '-'; j++){
                a.push_back(nodo[j]);
            }
            
            base = stoi(a);
            
            for (int j = a.size() + 1; j < nodo.size(); j++){
                if(nodo[j] != ',' && nodo[j] != '-'){
                    b.push_back(nodo[j]);
                }else{
                    n = stoi(b);
                    conex[base].push_back(n);
                    b = "";
                }
            }
            if(b.size() > 0){
                n = stoi(b);
                conex[base].push_back(n);
            }
            
            
		}
        cout << "-----" << endl;

        cin >> Q;
        for (int z = 0; z < Q; z++){
            flag = false;
        
            int startNode, endNode;
        
            cin >> startNode >> endNode;

            
            while(!cola.empty())
                cola.pop();

            cola.push(startNode);
            
            map<int, int> visited;

            visited[startNode] = 1;
            
            unordered_map<int, int> father;
            
            father[startNode] = startNode;
            
            while( !cola.empty() ){

                int node = cola.front();

                cola.pop();

                if(node == endNode){
                    flag = true;
                    break;
                } 
        
                for(int i = 0; i < conex[node].size(); ++i){

                    int aux = conex[node][i];

                    if( visited[aux] != 1 ){
                        cola.push(aux);
                        visited[aux] = 1;
                        father[aux] = node;
                    }
                
                }
            
            }
            
            vector<int> route;
            int node = endNode;
            while(node != startNode && father[node] != node){
                route.push_back(node);
                node = father[node];
            }
            route.push_back(startNode);
            
            reverse(route.begin(), route.end());


            if(flag){
                cout << route[0];
                for (int i = 1; i < route.size(); i++){
                    cout << " " << route[i];
                }
                cout << '\n';
            }else{
                cout << "connection impossible" << endl;
            }
            
        }
	}

	return 0;
}