from sys import stdin
from collections import deque
import math

n = 0
t = 0
numSCC = 0
adj = []
visitado = []
sccInd = []
enPila = []
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
    

def tarjan():
    global n, numSCC, t, adj, visitado, sccInd, enPila, pila, sccNodos
    i = 0
    while i < n :
        sccInd[i] = visitado[i] = -1
        enPila[i] = False
        i += 1
    i = 0
    while i < n :
        if visitado[i] == -1 :
            tarjanAux(i)
        i += 1    



def main():
    global n, numSCC, t, adj, visitado, sccInd, enPila, pila, sccNodos
    li = 0
    lines = stdin.readlines()

    while li < len(lines) - 1:
        line = lines[li].strip().split()
        n = int(line[0])
        m = int(line[1])
    
        numSCC = t = 0
        adj = [[] for i in range(50000)]
        visitado = [0 for i in range(50000)]
        sccInd = [0 for i in range(50000)]
        enPila = [False for i in range(50000)]

        pila = deque()
        sccNodos = []

        i = 0
        while i < m :
            li += 1
            line = lines[li].strip().split()
            aux1 = int(line[0])
            aux2 = int(line[1])
            j = int(line[2])
            if j == 1:
                adj[aux1 - 1].append(aux2 - 1)
            else:
                adj[aux1 - 1].append(aux2 - 1)
                adj[aux2 - 1].append(aux1 - 1)
            i += 1
            
        tarjan()
    
        if numSCC == 1 :
            print(1)
        else :
            print(0)


        li += 1

        

main()