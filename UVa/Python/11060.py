from sys import stdin
from collections import deque

MAX = 10000
adj = [[] for i in range(MAX)]
inc = [0 for i in range(MAX)]
n= int()
topo = []

def main():
    global n, topo
    n, m = list(map(int, stdin.readline().split()))
    vis = 0

    for i in range(n):
        vals = list(map(int, stdin.readline().split()))
        u = vals[0]
        for j in range(u):
            v = vals[j + 1]
            adj[i].append(v)
            inc[v] += 1

    print("Grafo")
    for i in range(n):
        print("Nodo %d:" % i)
        for j in range(len(adj[i])):
            print("%d" % adj[i][j], end = ' ')
        print("")

    print("Ordenamiento Topológico:")

    cola = deque()
    for i in range(n):
        if inc[i] == 0:
            cola.append(i)

    while len(cola) != 0:
        v = cola.popleft()
        topo.append(v)

        for i in range(len(adj[v])):
            u = adj[v][i]
            inc[u] -= 1
            if inc[u] == 0:
                cola.append(u)
        vis += 1

    if vis != n:
        print("Hay un ciclo")
    else:
        for i in range(n):
            print("%d" % topo[i], end = ' ')
    print("")

main()

    
    
