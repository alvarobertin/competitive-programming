#include <bits/stdc++.h>

using namespace std;

int main(){

	int N;

	string CityA, CityB;

	map<string, vector<string>> conex;

	queue<string> cola;
	bool first = true;

	while(cin >> N){
		
		conex.clear();

		if(!first){
			cout << '\n';
		}else{
			first = false; 
		}

		while(!cola.empty())
			cola.pop();

		for (int i = 0; i < N; ++i){

			cin >> CityA >> CityB;

			conex[CityA].push_back(CityB);

			conex[CityB].push_back(CityA);

		}
	
		string startNode, endNode;
	
		cin >> startNode >> endNode;


		cola.push(startNode);
		
		map<string, int> visited;

		visited[startNode] = 1;
		
		unordered_map<string, string> father;
		
		father[startNode] = startNode;
		
		bool flag = false;

		while( !cola.empty() ){

			string node = cola.front();

			cola.pop();

			if(node == endNode){
				flag = true;
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

		if(flag){

			vector<string> route;
			string node = endNode;
			while(node != startNode and father[node] != node){
				route.push_back(node);
				node = father[node];
			}
			route.push_back(startNode);
			reverse(route.begin(), route.end());

			for (int i = 1; i < route.size(); i++){
				cout << route[i - 1] << " " << route[i] << '\n';
			}
		
		}else{
			cout << "No route" << '\n';
		}

	}

	return 0;
}