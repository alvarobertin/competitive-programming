#include <bits/stdc++.h> 
using namespace std;

map<string, vector<string>> conex;
map<string, int> indegree;
map<string, int> outdegree;

string tomayus(string pal){

    for(int i = 0; i < pal.size(); i++){
        if(pal[i] >= 65  && pal[i] <= 90){
            pal[i] = pal[i] + 32;
        }
    }

    return pal;
}

bool comprobar(map<string, int> a){
    for (map<string,int>::iterator i = a.begin(); i != a.end(); i++){

        if((*i).second != 0){
            return false;
        }
    }
    return true;
}

int main(){

    string name, name2, pref;

    vector< vector<string>> prefs;

    cin >> name >> name2;

    while( !(name == "*" && name2 == "*") ){
        cin.ignore();
        conex.clear();
        indegree.clear();
        vector<string> temp;

        for(int j = 0; j < 2; j++){
            prefs.clear();
            vector<string> v;
            getline(cin, pref);

            stringstream ss(pref);
            string aux;

            while(ss >> aux){
                if(aux == "," || aux == ";"){ 
                    if(v.size() == 0){
                        v.push_back("a");
                    }
                    prefs.push_back(v);
                    v.clear();
                }
                v.push_back(aux);
            }            
        
            for (int i = 0; i < prefs.size(); i++){
                for (int k = 0; k < prefs[i].size() - 1; k++){

                    if( conex.find(prefs[i][k]) == conex.end() )                        
                        conex[prefs[i][k]] = temp;
                    if( indegree.find(prefs[i][k]) == indegree.end())
                        indegree[prefs[i][k]] = 0;
                        
                    conex[prefs[i][k]].push_back(prefs[i][k + 1]);
                    indegree[prefs[i][k + 1]] += 1;        
                
                }
            
            }
        }
        
        queue<string> cola;
        string startNode;
        map<string, int> visited;
        vector<string> toposort;

        for ( map<string, int>::iterator it = indegree.begin(); it != indegree.end(); it++){
            if((*it).second == 0 && visited[ (*it).first ] != 1 ){

                startNode = (*it).first;
                toposort.push_back(startNode);
                
                while(!cola.empty())
                    cola.pop();

                cola.push(startNode);
                

                visited[startNode] = 1;
                                        
                while( !cola.empty() ){

                    string node = cola.front();

                    cola.pop();
            
                    for(auto i = 0; i < conex[node].size(); ++i){

                        string aux = conex[node][i];

                        if( visited[aux] != 1){
                            indegree[aux] -= 1;
                            
                        }

                        if( indegree[aux] == 0){
                            visited[aux] = 1;
                            cola.push(aux);
                            toposort.push_back(aux);
                        }
                    
                    }
                
                }


            }
        }

        string res = "N";
        if(comprobar(indegree)){
            res = "F";
        }else{


            for ( map<string, int>::iterator it = indegree.begin(); it != indegree.end(); it++){
                
                
                if((*it).second == 1 ){
                    
                    map<string, int> cpyindegree = indegree;
                    map<string, int> cpyvisited = visited;
                    vector<string> cpytoposort = toposort;
                    
                    
                    startNode = (*it).first;
                    cpyindegree[startNode] -= 1;
                    //cout << "start "<< startNode << endl;
                    cpytoposort.push_back(startNode);
                    
                    while(!cola.empty())
                        cola.pop();

                    cola.push(startNode);
                    

                    cpyvisited[startNode] = 1;
                                            
                    while( !cola.empty() ){
                        string node = cola.front();

                        cola.pop();
                
                        for(auto i = 0; i < conex[node].size(); ++i){
                            string aux = conex[node][i];

                            if( cpyvisited[aux] != 1){
                                cpyindegree[aux] -= 1;
                                
                            }

                            if( cpyindegree[aux] == 0 && cpyvisited[aux] != 1){
                                cpyvisited[aux] = 1;
                                cola.push(aux);
                                cpytoposort.push_back(aux);
                            }
                        
                        }
                    
                    }
                    if( comprobar(cpyindegree)){
                        res = "P";
                        break;
                    }else{
                        res = "N";
                    }   
                }
            }            


        }
        cout << res << endl;

        cin >> name >> name2;
        
    }



	return 0;
}