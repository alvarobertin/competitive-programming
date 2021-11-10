#include <bits/stdc++.h>

using namespace std;

int main(){

	int k;

	string nodo, maze, temp;
    char Actual, Anterior, node;

	map<char, string> conex;
    map<char, int> visited;


	queue<int> cola;
	bool first = true, flag;

    cin >> maze;
	while(maze != "#"){
        temp = "";
		conex.clear();
        visited.clear();

        //A:BCD;B:AD;D:BG;F:H;G:DEH;E:FGH;H:EG;C:AD. A
        cin >> Actual >> Anterior >> k;

        node = maze[0];
        for (int i = 1; i < maze.size(); i++){
            if( maze[i] == ';'){
                conex[node] = temp;
                temp = "";
                node = maze[i + 1];
                i++;
            }else if(maze[i] == '.'){
                conex[node] = temp;
                visited[node] = 0;
                temp = "";
            }
            else if(maze[i] != ':'){
                visited[maze[i]] = 0;
                temp.push_back(maze[i]);
            }
        }
        // for (auto& x: conex) {
        //     cout << x.first << ": " << x.second << '\n';
        // }  

        flag = false;
                
        string light = "";
        int acum = 1;

        while( !flag ){
            
            flag = true;

            for(int i = 0; i < conex[Actual].size(); ++i){

                int aux = conex[Actual][i];

                if( visited[aux] != 1  && aux != Anterior){
                    
                    if(acum % k == 0){
                        visited[Actual] = 1;
                        light.push_back(Actual);
                    }
                    acum++; 
                    Anterior = Actual;
                    Actual = aux;
                    flag = false;
                    break;
                }
            
            }
        
        }
        if(light != ""){
            cout << light[0];
            for (int i = 1; i < light.size(); i++){
                cout << " " << light[i]; 
            }
            cout << " /"<< Actual << endl;

        }else{
            cout << "/"<< Actual << endl;
        }
            
        cin >> maze;
	}

	return 0;
}