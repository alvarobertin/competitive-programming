#include <bits/stdc++.h>
using namespace std;

map<pair<string, string>, pair<int, int>> values;
map<string, vector<string>> conex;

int main(){

    string command, itemA, itemB, eq;
    int priceA, priceB;

    cin >> command;
    while(command != "."){

        if(command == "!"){
            cin >> priceA >> itemA >> eq >> priceB >> itemB; 
            conex[itemA].push_back(itemB);
            conex[itemB].push_back(itemA);
            values[{itemA, itemB}] = {priceA, priceB};
            values[{itemB, itemA}] = {priceB, priceA};
        }else if(command == "?"){
        
            queue<string> cola;
            bool flag = false;
        
            string startNode, endNode;
            
            cin >> startNode >> eq >> endNode;
        
            cola.push(startNode);
            
            map<string, int> visited;

            visited[startNode] = 1;
            
            unordered_map<string, string> father;
            
            father[startNode] = startNode;
            
            while( !cola.empty() ){

                string node = cola.front();

                cola.pop();

                if(node == endNode){
                    flag = true;
                    break;
                } 
        
                for(int i = 0; i < conex[node].size(); ++i){

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
            while(node != startNode && father[node] != node){
                route.push_back(node);
                node = father[node];
            }
            route.push_back(startNode);
            
            int acumA = 1, acumB = 1, mcd;
            if(flag){
                for (int i = 0; i < route.size() - 1; i++){
                    acumA *= values[ {route[i], route[i + 1]} ].first;
                    acumB *= values[ {route[i], route[i + 1]} ].second;
                }

                mcd = __gcd(acumA, acumB);
                acumA = acumA/mcd;
                acumB = acumB/mcd;

                printf("%d %s = %d %s\n", acumB, startNode.c_str(), acumA, endNode.c_str());           

            }else{
                printf("? %s = ? %s\n", startNode.c_str(), endNode.c_str());
            }

        }

        cin >> command;
    }

  return 0;
}