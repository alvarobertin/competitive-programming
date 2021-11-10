from sys import stdin

def binUp(v, num, low, hi):
    mid = (low + hi) // 2
    if(low == mid):
        return hi
    if(v[mid] <= num):
        return binUp(v, num, mid, hi)
    else:
        return binUp(v, num, low, mid)

def main():
    i = 0
    lines = stdin.readlines()
    while i < len(lines):
        Popes = []
        Y = int (lines[i].strip())
        i += 1
        P = int (lines[i].strip())
        i += 1
        j = 0
        while j < P:
            Popes.append( int(lines[i].strip() )) 
            i += 1
            j += 1

        res = 0
        j = 0
        k = 0
        mi = 0
        ma = 0

        while k < P:
            n = binUp(Popes, Popes[k] + Y - 1, k, P)
            if(Popes[n - 1] - Popes[k] < Y and n - k > res and k != 0 ):
                mi = k
                ma = n - 1
                res = n - k 

            if(n == P): 
                break
            k += 1

        print("{} {} {}".format(res, Popes[mi], Popes[ma]))    

    
    
        i += 1

        

main()