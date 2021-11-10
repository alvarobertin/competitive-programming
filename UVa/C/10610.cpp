#include <bits/stdc++.h>

using namespace std;

struct cord{
    double x;
    double y;
    int id; 
};

bool comprobar(cord node, cord aux, double v, double t){
    double dist = sqrt( (node.x - aux.x)*(node.x - aux.x) + (node.y - aux.y)*(node.y - aux.y) );
    if((dist / v) <= t + 0.0001){
        return true;
    }
    return false;
}


int main(){

    double v, t;
    vector<cord> nodos;
    string line;
    
    double x1, y1, x2, y2;

    cin >> v >> t;
    while (v && t){
        cord startNode, endNode, temp;
        nodos.clear();

        t = t*60;
        cin >> x1 >> y1;
        cin >> x2 >> y2;

        startNode.x = x1;
        startNode.y = y1;
        startNode.id = 0;
        nodos.push_back( startNode );

        endNode.x = x2;
        endNode.y = y2;
        endNode.id = 1;
        nodos.push_back( endNode );


        cin.ignore();
        getline(cin, line);
        int id = 2;
        while (line != ""){

            stringstream ss(line);

            ss >> x1;
            ss >> y1;
            temp.x = x1;
            temp.y = y1;
            temp.id = id++;
            nodos.push_back( temp );

            getline(cin, line);
        }
        
        bool flag = false;
        queue<cord> cola;
        while(!cola.empty())
            cola.pop();

        cola.push(startNode);
        
        map<int, int> visited;

        visited[startNode.id] = 1;
        int acum = 0;
        unordered_map<int, int> father;
            
        father[startNode.id] = startNode.id;            
        while( !cola.empty() ){

            cord node = cola.front();

            cola.pop();

            if(node.id == endNode.id){
                flag = true;
                break;
            } 
    
            for(int i = 0; i < nodos.size(); ++i){

                cord aux = nodos[i];

                if( visited[aux.id] != 1 && comprobar(node, aux, v, t) ){
                    
                    cola.push(aux);
                    visited[aux.id] = 1;
                    father[aux.id] = node.id;
                }
            
            }
        
        }
        int node = endNode.id;
        while(node != startNode.id && father[node] != node){
            acum++;
            node = father[node];
        }


        if(flag)
            cout << "Yes, visiting " << acum - 1 << " other holes." << endl;
        else
            cout << "No." << endl;


        cin >> v >> t;
    }
    

	return 0;
}