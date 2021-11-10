#include <bits/stdc++.h>

using namespace std;

int main(){

	int N, C, Q;

	string CityA, CityB;

	map<string, vector<string>> conex;

	queue<string> cola;
	bool first = true;

    cin >> N;

	while(N--){
        
        cin >> C >> Q;

		conex.clear();


		for (int i = 0; i < C; ++i){

			cin >> CityA >> CityB;

			conex[CityA].push_back(CityB);

			conex[CityB].push_back(CityA);

		}

        for (int z = 0; z < Q; z++){
        
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