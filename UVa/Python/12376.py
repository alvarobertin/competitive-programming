from sys import stdin

def main():
    i = 1
    lines = stdin.readlines()
    cases = 1
    while i < len(lines):
        if(len(lines[i]) < 2):
            i += 1

        n, m = map(int, lines[i].strip().split())
        i += 1
        Lu = list(map(int, lines[i].strip().split()))
        Lu.pop(0)
        i += 1

        edges = {}

        for j in range(m):
            a, b = map(int, lines[i].strip().split())
            if a in edges:
                edges[a].append(b)
            else:
                edges[a] = [b]
            i += 1
        j = 0
        res = 0
        
        while j in edges:
            maxi = 0
            for k in (edges[j]):
                if Lu[k - 1] > maxi:
                    maxi = Lu[k - 1]
                    j = k
            res += Lu[j - 1]
        
        print("Case {}: {} {}".format(cases, res, j))
        cases += 1

        i += 1

        

main()