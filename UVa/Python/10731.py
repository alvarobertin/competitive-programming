from sys import stdin
from collections import deque

n = numSCC = t = 0
adj = {}
visitado = {}
sccInd = {}
enPila = {}
pila = deque()
sccNodos = []

def tarjanAux(v):
    global n, numSCC, t, adj, visitado, sccInd, enPila, pila, sccNodos
    w = 0
    t += 1
    visitado[v] = sccInd[v] = t
    
    pila.appendleft(v)

    enPila[v] = True
    i = 0
   
    while i < len(adj[v]) :
        w = adj[v][i]
        if visitado[w] == -1 :
            tarjanAux(w)
            sccInd[v] = min(sccInd[v], sccInd[w])
        elif enPila[w] :
            sccInd[v] = min(sccInd[v], visitado[w])
        i += 1

    if sccInd[v] == visitado[v] :
        sccNodos.append([])
        numSCC += 1
        while pila[0] != v :
            enPila[pila[0]] = False
            sccNodos[numSCC - 1].append(pila[0])
            pila.popleft()
        enPila[pila[0]] = False
        sccNodos[numSCC - 1].append(pila[0])
        pila.popleft()
    

def tarjan() :
    global n, numSCC, t, adj, visitado, sccInd, enPila, pila, sccNodos

    for it in adj:
        if(visitado[it] == -1):
            tarjanAux(it)




def main():
    global n, numSCC, t, adj, visitado, sccInd, enPila, pila, sccNodos
    li = 0
    lines = stdin.readlines()

    while li < len(lines) - 1:
        line = lines[li].strip().split()
        n = int(line[0])
    
        numSCC = t = 0
        adj = {}
        visitado = {}
        sccInd = {}
        enPila = {}
        pila = deque()
        sccNodos = []

        j = 0
        while j < n:    
            li += 1
            line = lines[li].strip().split()
            i = 0
            while i < 5 : 
                if( line[5] not in adj):
                    adj[line[5]] = []
                if(line[i] not in adj):
                    adj[line[i]] = []
                adj[ line[5] ].append( line[i])
                sccInd[line[i]] = visitado[line[i]] = -1
                enPila[line[i]] = False
                i += 1
            j += 1
        
        tarjan()

        i = 0
        while i < len(sccNodos) :
            sccNodos[i].sort()
            i += 1


        sccNodos.sort()

        i = 0
        while i < len(sccNodos):
            print(sccNodos[i][0], end = "")
            j = 1
            while j < len(sccNodos[i]):
                print(" {}".format(sccNodos[i][j]), end = "" )
                j += 1
            print()
            i += 1
        

        li += 1
        if li < len(lines) - 1:
            print()

        

main()