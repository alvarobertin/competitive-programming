#include <bits/stdc++.h>
using namespace std;

vector<string> words;
set<char> conjunto;
string res;
map<char, string> conex;
map<char, int> indegree;
map<char, int> outdegree;
map<char, int> visitado;


void recur(int i, int j, int sizes, int sizetotal){
    if(words[i][j] == ' ' || words[i][j] == '\n' || words[i][j] == '\0')
        return;
    else
        conjunto.insert(words[i][j]);
    
    if(i >= sizetotal - 1 || j >= sizes )
        return;

    if(words[i][j] == words[i + 1][j]){
        recur(i, j + 1, sizes, sizetotal);
    }    
    else{

        conex[ words[i][j] ] += words[i + 1][j];
        
        if ( indegree.find(words[i][j]) == indegree.end() )
            indegree[ words[i][j] ] = 0;

        indegree[ words[i + 1][j] ] += 1;
        outdegree[ words[i][j] ] += 1;
        
        conjunto.insert(words[i + 1][j]);

        return;
    }
}

void dfs(char v){
  char u;
  visitado[v] = 1;

  for(int i = 0; i < conex[v].size(); ++i){
    u = conex[v][i];
    if(visitado[u] == 0){
      dfs(u);
    }
  }
  res.push_back(v);

}


int main(){

	int N, C, Q, sizes, sizetotal;
    
    string word;
    words.clear();
    indegree.clear();
    outdegree.clear();

	while(cin >> word){

        if(word == "#" ){
            res = "";
            sizetotal = words.size();
            
            for (int i = 0; i < sizetotal; i++){
                recur(i, 0, words[i].size(), sizetotal);
            }   
            // for (auto& x: conjunto) {
            //     cout << "'" << x << endl;
            //     //cout << x.first << ": " << x.second << '\n';
            // }    

            char startNode;
            for ( map<char, int>::iterator it = indegree.begin(); it != indegree.end(); it++){
                if((*it).second == 0){
                    startNode = (*it).first;
                    break;
                }
            }
            if(conjunto.size() > 1)
                dfs(startNode);
            else
                res = words[0][0];
            
            reverse(res.begin(), res.end());
            cout << res << endl;

            res = "";
            conex.clear();
            visitado.clear();
            indegree.clear();
            outdegree.clear();
            words.clear();
            conjunto.clear();
        }else{
            words.push_back(word);
        }
        
    
	}

	return 0;
}