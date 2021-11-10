#include <bits/stdc++.h>

using namespace std;

int n, precioF;
vector<vector<pair<int, int> > > adj(50000);
vector<vector<int>> iniciales;  // La ciudad es inicial en un Tiquete x si inicales[x] == 1
pair< queue<int>, vector<int> > ans;

//
vector<int> precioTiquete;

map<pair< pair< queue<int>, vector<int> >, int>, pair< pair< queue<int>, vector<int> >, int>> padres;
map< pair< pair< queue<int>, vector<int> >, int> , int > visitado;

/*
Cada estado cuenta de:
    pair< pair< queue<int>, vector<int> >, int>

    1) Cola(Ruta) en la cual quito las ciudades obligatorias que voy avanzando
    2) NodoActual
    3) TiqueteActual
    4) PrecioActual

*/


/* 

Los estados van a ser una cola en la cual quito las ciudades obligatorias que voy avanzando, y un vector para guardar: 
1) el nodo actual y 2) En qué tiquete se está trabajando ahora mismo 

pair< queue<int>, vector<int>(2) >

*/


void BFS(int s, queue<int> ruta){
    int i, j, k, u, v, peso, costo, tiquete;
    // Hay que tener una cola en el trio, para identificar cómo va la ruta
    priority_queue< pair< int, pair< queue<int>, vector<int> > >, 
    vector< pair< int, pair< queue<int>, vector<int> > > >, 
    greater< pair< int, pair< queue<int>, vector<int> > > > > cola;
    queue<int> rutaTemp;

    pair< queue<int>, vector<int> > temp, temp2;

    ruta.pop();
    temp.first = ruta;
    temp.second.push_back(s);
    temp.second.push_back(-1);

    
    cola.push(make_pair(0, temp));
    visitado[{temp, 0}] = 1;
    padres[{temp, 0}] = {temp, 0};

    while(!cola.empty()){

        costo = cola.top().first;

        temp = cola.top().second;
        
        u = temp.second[0];

        cola.pop();

        //cout << ruta.front() + 1 << endl;
        
        if(temp.first.empty()){
            ans = temp;
            precioF = costo;
            break;
        }

        //if(costo == d[temp.second[0]]){
            for(j = 0; j < adj[u].size(); ++j){
                v = adj[u][j].first;
                peso = precioTiquete[adj[u][j].second];
                rutaTemp = temp.first;   // Para que no quede los cambios anteriores de la ruta

                /*Si u tiene la misma idTiquete que v, entonces puedo moverme y no sumo precio.*/
                
                
                if( adj[u][j].second == temp.second[1] ){
                    
                    //cout << u + 1 << " u | v f" << v + 1 << " " << peso << endl; 
                    
                    if(!rutaTemp.empty()){
                        if(v == rutaTemp.front()){
                            rutaTemp.pop();
                        }
                    }

                    temp2 = pair< queue<int>, vector<int> >();

                    temp2.first = rutaTemp; // ruta

                    temp2.second.push_back(v);

                    temp2.second.push_back(temp.second[1]); // Avanzamos en el mismo tiquete

                    if(visitado[{temp2, costo}] == 0){

                        cola.push(make_pair(costo, temp2));
                        visitado[{temp2, costo}] = 1;

                        padres[{temp2, costo}] = {temp, costo};

                        //d[v] = d[u]; // sirve?
                    }
                    
                }
                else{
                    /*Si u no tiene la misma idTiquete que v, pero u es un inicial de la 
                    misma idTiquete que v entonces puedo moverme, pero si sumo precio */
                    
                    //tiquete = conec(u, v); 

                    if( iniciales[u][adj[u][j].second] == 1){
                        
                        tiquete = adj[u][j].second;
                        //cout << u + 1 << " u | v " << v + 1 << " " << peso << endl; 
                        if(!rutaTemp.empty()){
                            if(v == rutaTemp.front()){
                                rutaTemp.pop();
                            }
                        }
                        temp2 = pair< queue<int>, vector<int> >();

                        temp2.first = rutaTemp; // ruta 

                        temp2.second.push_back(v);

                        temp2.second.push_back(tiquete); // Cambiamos de tiquete
                        
                        if(visitado[{temp2, costo + peso}] == 0){

                            cola.push(make_pair(costo + peso, temp2));
                            visitado[{temp2, costo + peso}] = 1;

                            padres[{temp2, costo + peso}] = {temp, costo};

                            //d[v] = d[u] + peso; // sirve?
                        }
                    }



                }

            }
       // }
    }
}

int main(){
    int m, aux1, aux2, peso, tiquetes, cotizar, itinerarios, casos;
    queue<int> r;
    vector<int> ResTiquetes;

    cin >> tiquetes;

    casos = 0;

    while(tiquetes != 0){
        casos++;
        //Reinicio de variables
        adj = vector<vector<pair<int, int> > >(10000);
        iniciales = vector<vector<int>>(400, vector<int>(400, 0)); 
        precioTiquete = vector<int>();

        for ( int i = 0; i < tiquetes; i++){
            cin >> peso >> m;

            precioTiquete.push_back(peso);
            
            cin >> aux1;
            iniciales[aux1 - 1][i] = 1;
            for (int j = 1; j < m; j++){
                cin >> aux2;
                adj[aux1 - 1].push_back(make_pair(aux2 - 1, i));
                // adj[aux1 - 1] ACA ESTA EL ERROR
                aux1 = aux2;
            }
            
        }
        
        cin >> cotizar;

        for (int i = 1; i <= cotizar; i++){
            r = queue<int>();
            cin >> itinerarios;

            for ( int j = 0; j < itinerarios; j++){
                cin >> aux1;
                r.push(aux1 - 1);
            }

            padres = map<pair< pair< queue<int>, vector<int> >, int>, pair< pair< queue<int>, vector<int> >, int>>();
            visitado = map< pair< pair< queue<int>, vector<int> >, int> , int >();
        
            BFS(r.front(), r);

            printf("Case %d, Trip %d: Cost = %d\n", casos, i, precioF);

            // Hay que modificar esto porque es sacado de mi solucion
            pair< pair< queue<int>, vector<int> >, int> nodo = {ans, precioF};
            
            vector< pair< queue<int>, vector<int> > > path;

            while(nodo != padres[nodo]){
                path.push_back(nodo.first);
                //cout << nodo.first << " " << nodo.second << endl;
                nodo = padres[nodo];
            }
            path.push_back(nodo.first);
            //cout << nodo.first << " " << nodo.second << endl;

            reverse(path.begin(), path.end());

            int actual;
            actual = -1;
            for (int k = 1; k < path.size(); k++){
                if(path[k].second[1] != -1 && actual != path[k].second[1]){
                    ResTiquetes.push_back(path[k].second[1]);
                    actual = path[k].second[1]; 
                }
                // cout << path[k].second[0] + 1 << " path " << path[k].second[1] + 1 << endl;
            }
            
        
            printf("  Tickets used:");

            for (int j = 0; j < ResTiquetes.size(); j++){
                printf(" %d", ResTiquetes[j] + 1);
            }
            printf("\n");

            // int te;
            // for (int s = 0; s < 500000; s++){
            //     te = 0;
            // }
        
        }
        

        

        cin >> tiquetes;
    }

  return 0;
}
