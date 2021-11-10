from sys import stdin

def main():
    i = 0
    lines = stdin.readlines()
    
    while i < len(lines)-2:
        N = int(lines[i].strip())

        frecuencias = list(map(int, lines[i + 1].strip().split()))
        a = 0
        b = 0
        c = 0
        res = 0
        j = 0
        while j < N:
            a = frecuencias[j]
            b = frecuencias[(j + 1) % N]
            c = frecuencias[(j + 2) % N]

            if a < b and  b > c :
                res += 1
            elif a > b and b < c :
                res += 1
            j += 1

        print(res)

        i += 2

main()