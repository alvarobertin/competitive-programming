#include <bits/stdc++.h>

using namespace std;

int n, distMax, nodoMax, distMax2, nodoMax2;
vector<vector<int> > adj(2600), adj1(2600), adj2(2600);

pair<int, int> blockA;
vector<int> alturas(2600);
int diametroAux(int v, int padre){
    int i, maxDiam, nodo, alt1, alt2;
    
    maxDiam = alt1 = alt2 = 0;

    for(i = 0; i < adj[v].size(); ++i){
        nodo = adj[v][i];
        pair<int, int> temp = {v, nodo};
        pair<int, int> temp2 = {nodo, v};
        if(nodo != padre && temp != blockA && temp2 != blockA){
            //adj1[v].push_back(nodo);
            maxDiam = max(maxDiam, diametroAux(nodo, v));
            alturas[v] = max(alturas[v], alturas[nodo] + 1);
            if(alturas[nodo] + 1 > alt1){
                alt2 = alt1;
                alt1 = alturas[nodo] + 1;
            }
            else if(alturas[nodo] + 1 > alt2)
                alt2 = alturas[nodo] + 1;
        }
    }
    return max(alt1 + alt2, maxDiam);
}

int diametro(int nodo){
    alturas = vector<int> (2600);
    return diametroAux(nodo, -1);
}

void dfsAux(int v, int padre){
    int w, i;  
    for(i = 0; i < adj[v].size(); ++i){
        w = adj[v][i];
        pair<int, int> temp = {v, w};
        pair<int, int> temp2 = {w, v};
        if(w != padre && temp != blockA && temp2 != blockA){
            adj1[v].push_back(w);
            adj1[w].push_back(v);
            dfsAux(w, v);
        }
    }
}

pair<int, int> centro(vector<vector<int> > ad){
    set<int> nodosCentro;
    int i, v, nivelMax = 0, radio;
    int grado[2600];
    int nivel[2600];
    queue<int> cola;

    for(i = 0; i < n; ++i){
        nivel[i] = 0;
        grado[i] = ad[i].size();
    }

    for(i = 0; i < n; ++i)
        if(grado[i] == 1)
            cola.push(i);

    while(!cola.empty()){
        v = cola.front();
        cola.pop();

        for(i = 0; i < ad[v].size(); ++i){
            grado[ad[v][i]]--;

            if(grado[ad[v][i]] == 1 ){
                cola.push(ad[v][i]);
                nivel[ad[v][i]] = nivel[v] + 1;
                nivelMax = max(nivelMax, nivel[ad[v][i]]);
            }
        }
    }

    for(i = 0; i < n; ++i){
        if(nivel[i] == nivelMax)
            nodosCentro.insert(i);
    }
    int diametro;
    diametro = (nodosCentro.size() >= 2) ? (nivelMax + 1)*2 - 1 : nivelMax*2 ;

    return {*nodosCentro.begin(), diametro };
}



int main(){
    int m, i, aux1, aux2, rad, cases, v, w, dinicial, unionA, unionB, dFinal;
    set<int> nodosCentro, nodosCentro2;
    cin >> cases;

    while(cases--){
        int resFinal = INT_MAX, resA, resB, resAA, resBB;
        adj = vector<vector<int> > (2600);


        cin >> n;
        vector<pair<int,int>> conex;
        for(i = 0; i < n - 1; i++){
            cin >> aux1 >> aux2;
            adj[aux1 - 1].push_back(aux2 - 1);
            adj[aux2 - 1].push_back(aux1 - 1);
            conex.push_back({aux1-1, aux2-1});
        }

        blockA = {-1, -1};
        dinicial = diametro(0);

        for (i = 0; i < n - 1; i++){
            v = conex[i].first;
            w = conex[i].second;
            
            blockA = {v, w};

            adj1 = vector<vector<int> > (2600);
            dfsAux(w, -1);
            adj2 = adj1;
            adj1 = vector<vector<int> > (2600);
            dfsAux(v, -1);
                        
            if(adj2[w].size() > 0){
                pair<int, int> temp = centro(adj2);
                unionB = temp.first;
                aux2 = temp.second;
                
            }
            else{
                unionB = w;
                aux2 = 0;
            }

            if(adj1[v].size() > 0){
                pair<int, int> temp = centro(adj1);
                unionA = temp.first;
                aux1 = temp.second;
                
            }
            else{
                unionA = v;
                aux1 = 0;
            }

            float a = ceil(float(aux1)/2);
            float b = ceil(float(aux2)/2);

            dFinal = max(aux1, max(aux2, int(a + b) + 1 ) );
            pair<int, int> temp = {unionB, unionA};
            pair<int, int> temp2 = {unionA, unionB};

            if(dFinal < dinicial && dFinal < resFinal && temp != blockA && temp2 != blockA){
                resFinal = dFinal;
                resA = v;
                resB = w;
                resAA = unionA;
                resBB = unionB;
                
            } 
            
        }
        
        cout << resFinal << endl;
        cout << resA + 1 << " " << resB + 1<< endl;
        cout << resAA + 1 << " " << resBB + 1 << endl;
    }
    return 0;
}
