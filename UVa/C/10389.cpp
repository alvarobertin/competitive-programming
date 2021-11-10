#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<pair<double, double> > > adj(50000);
vector<int> p(50000);
vector<double> d(50000);

void inicializar(int s){
  for(int i = 0; i < n; ++i){
    d[i] = INT_MAX;
    p[i] = -1;
  }

  d[s] = 0;
}

void dijkstra(int s){
  int i, j, k, u, v;
  double peso, costo;
  priority_queue<pair<double, double>, vector<pair<double, double>>, greater<pair<double, double>> > cola;
  
  inicializar(s);
  cola.push(make_pair(0, s));

  while(!cola.empty()){
    costo = cola.top().first;
    u = cola.top().second;
    cola.pop();

    if(costo == d[u]){
        for(j = 0; j < adj[u].size(); ++j){
            v = adj[u][j].first;
            peso = adj[u][j].second;
            if(d[u] != INT_MAX && d[u] + peso < d[v]){
                d[v] = d[u] + peso;
                p[v] = u;
                cola.push(make_pair(d[v], v));
            }
        }
    }
  }
}
vector<pair<double, double>> cords;

double distancia(int i, int j){
    return sqrt( (cords[i].first - cords[j].first)*(cords[i].first - cords[j].first) + (cords[i].second - cords[j].second)*(cords[i].second - cords[j].second));
}

int main(){
    int m, i, k, q, aux1, aux2, peso, cases;
    double iniciox, inicioy, schoolx, schooly;
    
    string line;

    cin >> cases;
    while(cases--){
        cords.clear();
        adj = vector<vector<pair<double, double> > > (5000);
        map<pair<int, int>, int> lineas;
        p = vector<int> (50000);
        d = vector<double> (50000);

        cin >> iniciox >> inicioy >> schoolx >> schooly;
        cin.ignore();
        cords.push_back({iniciox, inicioy});
        lineas[{iniciox, inicioy}] = -1;
        getline(cin, line);
        int nline = 1;
        while (line != ""){
            
            stringstream ss(line);
            string aux;
            while(ss >> aux1 >> aux2){
                if(aux1 != -1 && aux2 != -1){
                    cords.push_back({aux1, aux2});
                    lineas[{aux1, aux2}] = nline;
                    lineas[{aux2, aux1}] = nline;
                }
            }
            nline++;
            getline(cin, line);
        }
        cords.push_back({schoolx, schooly});
        lineas[{schoolx, schooly}] = -2;
        
        

        for (int i = 0; i < cords.size(); i++){
            for (int j = 0; j < cords.size(); j++){
                
                if(i != j){
                    if(lineas[cords[i]] == lineas[cords[j]] && abs(i - j) == 1){
                        adj[i].push_back({j, distancia(i, j)});
                        adj[j].push_back({i, distancia(j, i)});
                    }else{
                        adj[i].push_back({j, distancia(i, j)*4.0});
                        adj[j].push_back({i, distancia(j, i)*4.0});
                    }
                }   

            }
        }
        n = cords.size();
        dijkstra(0);  

        // for(i = 0; i < c; ++i)
        //     cout << "Distancia a nodo " << i << ": " << d[i] << endl;  

        //int(round(d[cords.size() - 1]*1.5/1000.0 ))
        cout << int(round(d[cords.size() - 1]*1.5/1000.0 )) << endl;
        if(cases)
            cout << endl;
    }
  

  
    return 0;
}
