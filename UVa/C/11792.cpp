#include <bits/stdc++.h>

using namespace std;

int main(){

	int cases, a, b, t;

	
    vector<int> temp;
    map<int, int> lineas, important;

	queue<int> cola;
	bool first = true, flag;

    cin >> cases;
	while(cases--){
        cin >> a >> b;
        important.clear();
        lineas.clear();
        vector<vector<int>> conex(a + 1);

        for (int i = 0; i < b; i++){
            temp.clear();
            
            cin >> t;
            while (t){
                temp.push_back(t);
                cin >> t;
            }

            if(lineas[temp[0]] != 0){
                important[temp[0]] = 1;
            }
            lineas[temp[0]] = i + 1;
            
            
            for (int j = 0; j < temp.size() - 1; j++){

                
                conex[temp[j]].push_back(temp[j + 1]); 
                conex[temp[j + 1]].push_back(temp[j]);
                
                if(lineas[temp[j + 1]] != 0){
                    important[temp[j + 1]] = 1;
                }
                lineas[temp[j + 1]] = i + 1;
                
            }
            
        }
        
        map<int, int> acum;
        int o;

        for (auto j = important.begin(); j != important.end(); j++){
            o = 0;
        
            flag = false;
        
            int startNode = j->first;
            
            while(!cola.empty())
                cola.pop();

            cola.push(startNode);
            
            vector<int> visited(a + 1, 0);

            visited[startNode] = 1;
            map<int, int> d;
                                
            while( !cola.empty() ){

                int node = cola.front();

                cola.pop();
        
                for(int i = 0; i < conex[node].size(); ++i){

                    int aux = conex[node][i];

                    if( visited[aux] == 0 ){
                        cola.push(aux);
                        visited[aux] = visited[node] + 1;

                        if(important.find(aux) != important.end()){
                            acum[startNode] += visited[aux];
                        }
                    }
                
                }
            }   
            
        }
            

        int res;
        int min = 1215752191;
        for (auto& x: acum) {
            //cout << x.first <<  ": "<< x.second << endl; 
                if(x.second < min){
                    res = x.first;
                    min = x.second;
                }
        }
        cout << "Krochanska is in: " << res << endl;

    
        // for( auto& x : conex){
        //     cout << x.first << ":";
        //     for(int i = 0; i < (x.second).size() ; i++){
        //         cout << " " << x.second[i];
        //     }
        //     cout << endl;
        // }

	}

	return 0;
}

