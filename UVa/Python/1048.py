#Nicole Molineros Sánchez
#Código: 8946616
#Como miembro de la comunidad académica de la Pontificia Universidad Javeriana Cali me comprometo a seguir los más altos estándares de integridad académica.

from sys import stdin
from collections import deque
from heapq import heappop, heappush

# Usamos diccionarios para no tener problema con el n de la ciudad
adj = {} 
PrecioTiquete = {}
Iniciales = {}
######################################################################

visitados = {} # key: Estado y value = ints
padre = {} # key: Estado y value = Estado

def BFS(ruta):
    # Entrada: Recibimos como entrada una cola (ruta) 
    # Salida: Se realiza el State Space Search hasta encontrar un 
    # Estado en el cual la ruta esté totalmente vacia
    # por lo que se puede decir que se visitó todo el itinerario, 
    # entonces se retorna el estado (tupla) donde encontramos esa ruta vacia.
    global adj, PrecioTiquete, Iniciales, padre, visitados

    visitados = {}
    padre = {}
    heap = []
    inicial = ruta.popleft()

    rutaTuple = tuple(ruta)
    Estado = (0, inicial, -1, rutaTuple  )
    heappush(heap, Estado)
    visitados[ Estado ] = 1
    padre[Estado] = Estado

    while len(heap) != 0 :

        Estadou = heappop(heap)
        
        preciou = Estadou[0]
        u = Estadou[1]
        tiqueteu = Estadou[2]
        rutaTuple = Estadou[3]

        rutau = deque(rutaTuple)

        if len(rutau) == 0: 
            #Acá es donde se verifica que se haya llegado a un estado en el cual la ruta es vacia
            # O sea que ese estado sea la respuesta y la retornemos
            return Estadou

        for v, tiqv in adj[u]:
            preciov = PrecioTiquete.get(tiqv)
            rutav = deque()
            rutav = deque(rutau)

            if tiqueteu == tiqv:
                # Caso 1
                # Si u y v estan en el mismo tiquete, me muevo
                if len(rutau) > 0:
                    if rutau[0] == v: #  Si se cumple la ruta 
                        rutav.popleft()

                rutaTuple = tuple(rutav)
                Estadov = (preciou, v, tiqueteu, rutaTuple)


                if visitados.get(Estadov) != 1:
                    visitados[Estadov] = 1
                    padre[Estadov] = Estadou
                    heappush(heap, Estadov)

            elif Iniciales.get((u, tiqv)) == 1:
                # Caso 2
                # Si u y v no estan en el mismo tiquete, y v es una ciudad inicial en su tiquete
                if len(rutau) > 0:
                    if rutau[0] == v: #  Si se cumple la ruta 

                        rutav.popleft()
                
                rutaTuple = tuple(rutav)
                Estadov = (preciou + preciov, v, tiqv, rutaTuple)

                if visitados.get(Estadov) != 1:
                    visitados[Estadov] = 1
                    padre[Estadov] = Estadou
                    heappush(heap, Estadov)
    return None


def main():
    l = 0
    lines = stdin.readlines() # Se lee toda la entrada
    cases = 0
    global adj, PrecioTiquete, Iniciales, padre, visitados
    while l < len(lines) - 1: # Se itera la entrada (cada caso), como finaliza con un 0 entonces no se lee la ultima linea
        cases += 1
        adj = {}
        PrecioTiquete = {}
        Iniciales = {}

        nT = int(lines[l].strip()) # Guardamos el numero de tiquetes en nT
        l += 1
        for nTiquete in range(nT):
            tiquete = lines[l].strip().split() # Guardamos la linea y la separamos en espacios en la lista "tiquete" 
            l += 1
            precio = int(tiquete[0])
            
            u = int(tiquete[2]) 

            Iniciales[(u, nTiquete)] = 1 # Marcamos a la primera ciudad u como ciudad inicial en el tiquete nTiquete
            PrecioTiquete[nTiquete] = precio # Guardamos el precio del tiquete nTiquete 
            
            i = 3 # Iniciamos en 3, porque ya leimos el precio del tiquete, el numero de ciudades y la primera ciudad
            while i < len(tiquete):
                v = int(tiquete[i]) 
                if u not in adj: # inicializamos adj[u]  
                    adj[u] = []
                if v not in adj: # inicializamos adj[v]  
                    adj[v] = []
                adj[u].append( (v, nTiquete) ) # Ingresamos el hijo del nodo u, como una tupla (hijo, id tiquete)
                u = v
                i += 1

        nQ = int(lines[l].strip())
        l += 1
        
        for nquery in range(nQ):
            query = lines[l].strip().split()
            l += 1
            ruta = deque()

            i = 1
            while i < len(query):
                ruta.append(int(query[i]))
                i += 1
                
            ans = ()
            ans = BFS(ruta)

            if(ans != None):
                route = []
                node = ans

                if(node in padre):
                    while( padre [node] != node) : 
                        route.append(node)
                        if(node not in padre):
                            break
                        node = padre[node]
                route.append(node)
            
                print("Case {}, Trip {}: Cost = {}".format(cases, nquery + 1, ans[0]))
                print("  Tickets used:", end = "")

                anterior = -1
                j = len(route) - 1
                while j >= 0:
                    if anterior != route[j][2]:
                        print(" {}".format(route[j][2] + 1), end="" )
                        anterior = route[j][2]
                    j -= 1
                print()
            else:
                print("NO")

main()
