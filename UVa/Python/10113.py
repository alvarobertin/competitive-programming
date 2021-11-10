from sys import stdin
from queue import Queue
import math

def main():
    i = 0
    lines = stdin.readlines()

    values = {}
    conex = {}

    while i < len(lines) - 1:

        line = lines[i].strip().split()

        if(line[0] == "!"):
            # ! 6 shirt = 15 sock
            priceA = int(line[1])
            itemA = line[2]
            priceB = int(line[4])
            itemB = line[5]
            

            if itemA not in conex:
                conex[itemA] = [itemB]
            else:
                conex[itemA].append(itemB)

            if itemB not in conex:
                conex[itemB] = [itemA]
            else:
                conex[itemB].append(itemA)

            values[(itemA, itemB)] = (priceA, priceB)
            values[(itemB, itemA)] = (priceB, priceA)
            
        elif(line[0] == "?"):
            cola = Queue()
            flag = False
            startNode = line[1]
            endNode = line[3]
                    
            cola.put(startNode) 
            
            visited = {}

            visited[startNode] = 1
            
            father = {}
            
            father[startNode] = startNode
            
            while cola.empty() == False :

                node = cola.get()

                if node == endNode :
                    flag = True
                    break
                x = 0
                while x < len(conex[node]): 

                    aux = conex[node][x]
                    
                    if aux not in visited :
                        cola.put(aux)
                        visited[aux] = 1
                        father[aux] = node
                    x += 1
            
            route = []
            node = endNode

            if(node in father):
                while(node != startNode and father[node] != node) : 
                    route.append(node)
                    if(node not in father):
                        break
                    node = father[node]
            
            route.append(startNode)
            
            acumA = 1
            acumB = 1
            mcd = 0
            
            if flag :
                x = 0
                while x < len(route) - 1 :
                    acumA *= values[ (route[x], route[x + 1]) ][0]
                    acumB *= values[ (route[x], route[x + 1]) ][1]
                    x += 1

                mcd = math.gcd(acumA, acumB)
                acumA = int(acumA/mcd)
                acumB = int(acumB/mcd)

                print("{} {} = {} {}".format(acumB, startNode, acumA, endNode))
            else:
                print("? {} = ? {}".format(startNode, endNode))

        i += 1

        

main()