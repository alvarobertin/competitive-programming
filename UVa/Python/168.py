from sys import stdin

def main():

    lines = stdin.readlines()
    p = 0
    while p < len(lines) - 1:
        temp = ""
        #A:BCD;B:AD;D:BG;F:H;G:DEH;E:FGH;H:EG;C:AD. A C 3
        conex = {}
        visited = {}
        
        line = lines[p].strip().split()
        Actual = line[1]
        Anterior = line[2]
        k = int(line[3])


        maze = line[0]
        node = maze[0]
        i = 1
        while i < len(maze):
            if maze[i] == ';' :
                conex[node] = temp
                temp = ""
                node = maze[i + 1]
                i += 1
            elif maze[i] == '.' :
                conex[node] = temp
                visited[node] = 0
                temp = ""
            elif maze[i] != ':' :
                visited[maze[i]] = 0
                temp += maze[i]

            i += 1


        flag = False
                
        light = ""
        acum = 1

        while not flag : 
            
            flag = True
            i = 0
            if Actual in conex:
                while i < len(conex[Actual]) :

                    aux = conex[Actual][i]

                    if visited[aux] != 1  and aux != Anterior : 
                        
                        if acum % k == 0 :
                            visited[Actual] = 1
                            light += Actual
                        
                        acum += 1 
                        Anterior = Actual
                        Actual = aux
                        flag = False
                        break
                    
                
                    i += 1
        
        if light != "" :
            print(light[0], end="")
            i = 1
            while i < len(light) :
                print(" {}".format(light[i]), end = "")
                i += 1 
            print(" /{}".format(Actual))
        else :
            print("/{}".format(Actual))
        

        p += 1


main()