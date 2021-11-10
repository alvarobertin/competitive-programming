from sys import stdin

def recur(line, i, a, b):
    global mem
    if (i, a, b) in mem:
        return mem[(i, a, b)]
    else:
        if i == len(line):
            mem[(i, a, b)] = a == b
        else:    
            mem[(i, a, b)] = recur(line, i + 1, a + line[i], b) or recur(line, i + 1, a, b + line[i])
        return mem[(i, a, b)]

def recur(line, i, a, X):
    global mem
    if (i, a) in mem:
        return mem[(i, a)]
    else:
        if a == X:
            mem[(i, a)] = True
        elif i == len(line):
            mem[(i, a)] = False
        else:    
            mem[(i, a)] = recur(line, i + 1, a) or recur(line, i + 1, a + line[i])
        return mem[(i, a)]

def solve(line):
    global mem
    mem = {}
    return recur(line, 0, 0, 0)


def main():
    cases = int(stdin.readline())

    for i in range(cases):
        line = list(map(int,stdin.readline().split()))
        if solve(line):
            print("YES")
        else:
            print("NO")



main()