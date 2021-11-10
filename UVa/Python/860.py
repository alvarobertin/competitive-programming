from sys import stdin
from math import log10

def main():
    i = 0
    lines = stdin.readlines()
    
    while i < len(lines)-1:
        Palabras = {}

        while i < len(lines)-1:
            line = list(lines[i].split())
            if len(line) != 0:
            
                if line[0] == "****END_OF_TEXT****" :
                    break
        
                for j in line:
                    for l in j:
                        if l == "," or l == '.' or l == ':' or l == ';' or l == '!' or l == '?' or l == '"' or l == '(' or l == ')' or l == '\n' :
                            j = j.replace(l, " ")

                    newPals = list(map(lambda x: x.upper(), j.split()))

                    for k in newPals:
                        if k not in Palabras:
                            Palabras[k] = 0
                        Palabras[k] += 1
                    
            i += 1

        Acum = 0
        for j in Palabras:
            Acum += Palabras[j]
        
        entropy = 0
        sigma = 0
        re = 0
        for j in Palabras:
            sigma += (Palabras[j]) * (log10(Acum) - log10(Palabras[j]))
        
        entropy = sigma/Acum
        re = (entropy / log10(Acum)) * 100

        print("{} {:.1f} {:.0f}".format(Acum, entropy, re))

        i += 1

main()