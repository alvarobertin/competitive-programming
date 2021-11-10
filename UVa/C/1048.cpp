#include <bits/stdc++.h>

using namespace std;

struct Estado {
    int NodoActual, TiqueteActual, Precio, ruta;

    bool operator<(const Estado &other) const{
        return tie(Precio, NodoActual, TiqueteActual, ruta) < tie(other.Precio, other.NodoActual ,other.TiqueteActual ,other.ruta);
    }
    bool operator>(const Estado &other) const{
        return tie(Precio, NodoActual, TiqueteActual, ruta) > tie(other.Precio, other.NodoActual ,other.TiqueteActual ,other.ruta);
    }

    bool operator!=(const Estado &other) const{
        return (Precio != other.Precio) || 
                (TiqueteActual != other.TiqueteActual) || 
                (NodoActual != other.NodoActual) ||
                (ruta != other.ruta);
    }
    bool operator==(const Estado &other) const{
        return (Precio == other.Precio) && 
                (TiqueteActual == other.TiqueteActual) && 
                (NodoActual == other.NodoActual) &&
                (ruta == other.ruta);
    }
};



int n;
vector<vector<pair<int, int> > > adj;
vector<int> PrecioTiquete, rutaVec;
vector<vector<int>> Iniciales;
map<Estado, int> visitados;
map<Estado, Estado> padre;


Estado BFS(int s){
    int i, j, k, u, v, pesov, costou, inicial, tiqueteu, tiquetev, rutau, rutav;
    Estado Estadotemp, Estadou, Estadov;
    priority_queue<Estado, vector<Estado>, greater<Estado> > cola;


    visitados = map<Estado, int> ();
    padre = map<Estado, Estado> ();


    inicial = s;

    Estadotemp.NodoActual = inicial;
    Estadotemp.TiqueteActual = -1;
    Estadotemp.Precio = 0;
    Estadotemp.ruta = 1;
    cola.push(Estadotemp);
    visitados[Estadotemp] = 1;
    padre[Estadotemp] = Estadotemp;


    while(!cola.empty() ){

        Estadou = cola.top();
        costou = cola.top().Precio;
        u = cola.top().NodoActual;
        rutau = cola.top().ruta;
        tiqueteu = cola.top().TiqueteActual;
        cola.pop();

        if(rutau == rutaVec.size() - 1 ) return Estadou;


        for(j = 0; j < adj[u].size(); ++j){
            
            v = adj[u][j].first;
            pesov = PrecioTiquete[adj[u][j].second];
            tiquetev = adj[u][j].second;

            rutav = rutau;
            if(rutau < rutaVec.size() -1 )
                if(rutaVec[rutau] == v){ /* Si se cumple la ruta  */
                    rutav++;
                }

            if( tiqueteu == tiquetev ){
            /*Caso 1*/
            /* Si u y v estan en el mismo tiquete, me muevo*/
                //cout  << rutau.front() << " a " << v << endl;
                
                Estadov.NodoActual = v;
                Estadov.TiqueteActual = tiqueteu;
                Estadov.Precio = costou;
                Estadov.ruta = rutav;

                if( visitados[Estadov] == 0){
                    // cout << u << " A " << v << endl; 
                    visitados[Estadov] = 1;
                    padre[Estadov] = Estadou;                    
                    cola.push(Estadov);
                    
                }
            }
            else if( Iniciales[u][tiquetev] == 1){
            /* Caso 2 */
            /* Si u y v no estan en el mismo tiquete, y v es una ciudad inicial en su tiquete*/ 
                // cout  << rutau.front() << " a " << v << endl; 

                Estadov.NodoActual = v;
                Estadov.TiqueteActual = tiquetev;
                Estadov.Precio = costou + pesov;
                Estadov.ruta = rutav;

                if( visitados[Estadov] == 0){
                    //cout << u << " B " << v << endl; 
                    visitados[Estadov] = 1;
                    padre[Estadov] = Estadou;                    
                    cola.push(Estadov);
                }
                

            }

        }

    }
    return Estadou;
}

int main(){
    int m, i, aux1, aux2, peso, NT, cases, anterior, maximo, nciudades;
    vector<int> temp;
    Estado ans;
    vector< Estado > path;
    queue<int> ruta;
    Estado nodo;
    cases = 0;
    cin >> NT;
    map<int, int> ciudades;

    while(NT != 0){
        cases++;
        adj = vector<vector<pair<int, int> > >(50000);
        PrecioTiquete = vector<int> (30);
        Iniciales = vector<vector<int>> (30, vector<int>(30, 0));
        visitados.clear();
        ciudades.clear();
        nciudades = 0;


        for (int i = 0; i < NT; i++){
            cin >> peso >> n;
            temp = vector<int>(0);
            for (int j = 0; j < n; j++){
                cin >> aux1;

                if (ciudades.find(aux1) == ciudades.end()){
                    ciudades[aux1] = nciudades;
                    nciudades += 1;
                }

                if(j == 0 ){
                    Iniciales[ciudades[aux1]][i] = 1;
                }
                temp.push_back(ciudades[aux1]);
            }
            PrecioTiquete[i] = peso;
            if(temp.size() != 0)
                for (int j = 0; j < temp.size() - 1; j++){
                    adj[temp[j]].push_back(make_pair( temp[j + 1], i));
                }
        }
        
        cin >> n;

        for (int q = 1; q <= n; q++){
            rutaVec = vector<int>();
            cin >> m;

            for (int i = 0; i < m; i++){
                cin >> aux1;
                rutaVec.push_back(ciudades[aux1]);
            }
            rutaVec.push_back(0);

    
            ans = BFS(rutaVec[0]);

            path = vector< Estado > ();
            nodo = ans;

            while( nodo != padre[nodo] ){
                path.push_back(nodo);
                nodo = padre[nodo];
            }
            path.push_back(nodo);

            printf("Case %d, Trip %d: Cost = %d\n", cases, q, ans.Precio);
            printf("  Tickets used:");

            anterior = -1;
            for (int i = path.size() - 1; i >= 0; i--){
                if(anterior != path[i].TiqueteActual){
                    printf(" %d", (path[i].TiqueteActual + 1));
                    anterior = path[i].TiqueteActual;
                }
            }
            printf("\n");

        }

        cin >> NT;
    }

    return 0;
}
