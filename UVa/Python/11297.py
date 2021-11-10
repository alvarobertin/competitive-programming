from sys import stdin
#Segment tree is represented as a list
def minbuildX(a, v, l, r):
    global n, c, MAXN, mintree
    if l != r:
        m = l + ((r - l) >> 1) # (l + r) // 2
        minbuildX(a, 2 * v + 1, l, m)
        minbuildX(a, 2 * (v + 1), m + 1, r)
    minbuildY(a, v, l, r, 0, 0, c - 1)

def minbuildY(a, vx, lx, rx, vy, ly, ry):
    global n, c, MAXN, mintree
    if ly == ry:
        if lx == rx: mintree[vx][vy] = a[lx][ly]
        else: mintree[vx][vy] = min(mintree[2 * vx + 1][vy], mintree[2 * (vx + 1)][vy])
    else:
        m = ly + ((ry - ly) >> 1)
        minbuildY(a, vx, lx, rx, 2 * vy + 1, ly, m)
        minbuildY(a, vx, lx, rx, 2 * (vy + 1), m + 1, ry)
        mintree[vx][vy] = min(mintree[vx][2 * vy + 1], mintree[vx][2 * (vy + 1)])

#sum query
def minsumY(vx, vy, LY, RY, ly, ry): # sum(0, 0, n - 1, 2, 5)
    global n, c, MAXN, mintree
    ans = None
    if ly > ry: ans = float('inf')
    elif ly == LY and ry == RY: ans = mintree[vx][vy]
    else:
        m = LY + ((RY - LY) >> 1)
        ans = min(minsumY(vx, 2 * vy + 1, LY, m, ly, min(ry, m)), minsumY(vx, 2 * (vy + 1), m + 1, RY, max(ly, m + 1), ry))
    return ans

def minsumX(vx, LX, RX, lx, rx, ly, ry):
    global n, c, MAXN, mintree
    ans = None
    if lx > rx: ans = float('inf')
    elif lx == LX and rx == RX: ans = minsumY(vx, 0, 0, c - 1, ly, ry)
    else:
        m = LX + ((RX - LX) >> 1)
        ans = min(minsumX(2 * vx + 1, LX, m, lx, min(rx, m), ly, ry), minsumX(2 * (vx + 1), m + 1, RX, max(lx, m + 1), rx, ly, ry))
    return ans

#update query
def minupdateY(vx, LX, RX, vy, LY, RY, x, y, h):
    global n, c, MAXN, mintree
    if LY == RY:
        if LX == RX: mintree[vx][vy] = h
        else: mintree[vx][vy] = min(mintree[2 * vx + 1][vy], mintree[2 * (vx + 1)][vy])
    else:
        m = LY + ((RY - LY) >> 1)
        if y <= m: minupdateY(vx, LX, RX, 2 * vy + 1, LY, m, x, y, h)
        else: minupdateY(vx, LX, RX, 2 * (vy + 1), m + 1, RY, x, y, h)
        mintree[vx][vy] = min(mintree[vx][2 * vy + 1], mintree[vx][2 * (vy + 1)])

def minupdateX(vx, LX, RX, x, y, h):
    global n, c, MAXN, mintree
    if LX != RX:
        m = LX + ((RX - LX) >> 1)
        if x <= m: minupdateX(2 * vx + 1, LX, m, x, y, h)
        else: minupdateX(2 * (vx + 1), m +1, RX, x, y, h)
    minupdateY(vx, LX, RX, 0, 0, c - 1, x, y, h)

#MAXIMO
def maxbuildX(a, v, l, r):
    global n, c, MAXN, tree
    if l != r:
        m = l + ((r - l) >> 1) # (l + r) // 2
        maxbuildX(a, 2 * v + 1, l, m)
        maxbuildX(a, 2 * (v + 1), m + 1, r)
    maxbuildY(a, v, l, r, 0, 0, c - 1)

def maxbuildY(a, vx, lx, rx, vy, ly, ry):
    global n, c, MAXN, tree
    if ly == ry:
        if lx == rx: tree[vx][vy] = a[lx][ly]
        else: tree[vx][vy] = max(tree[2 * vx + 1][vy], tree[2 * (vx + 1)][vy])
    else:
        m = ly + ((ry - ly) >> 1)
        maxbuildY(a, vx, lx, rx, 2 * vy + 1, ly, m)
        maxbuildY(a, vx, lx, rx, 2 * (vy + 1), m + 1, ry)
        tree[vx][vy] = max(tree[vx][2 * vy + 1], tree[vx][2 * (vy + 1)])

#sum query
def maxsumY(vx, vy, LY, RY, ly, ry): # sum(0, 0, n - 1, 2, 5)
    global n, c, MAXN, tree
    ans = None
    if ly > ry: ans = 0
    elif ly == LY and ry == RY: ans = tree[vx][vy]
    else:
        m = LY + ((RY - LY) >> 1)
        ans = max(maxsumY(vx, 2 * vy + 1, LY, m, ly, min(ry, m)), maxsumY(vx, 2 * (vy + 1), m + 1, RY, max(ly, m + 1), ry))
    return ans

def maxsumX(vx, LX, RX, lx, rx, ly, ry):
    global n, c, MAXN, tree
    ans = None
    if lx > rx: ans = 0
    elif lx == LX and rx == RX: ans = maxsumY(vx, 0, 0, c - 1, ly, ry)
    else:
        m = LX + ((RX - LX) >> 1)
        ans = max(maxsumX(2 * vx + 1, LX, m, lx, min(rx, m), ly, ry), maxsumX(2 * (vx + 1), m + 1, RX, max(lx, m + 1), rx, ly, ry))
    return ans

#update query
def maxupdateY(vx, LX, RX, vy, LY, RY, x, y, h):
    global n, c, MAXN, tree
    if LY == RY:
        if LX == RX: tree[vx][vy] = h
        else: tree[vx][vy] = max(tree[2 * vx + 1][vy], tree[2 * (vx + 1)][vy])
    else:
        m = LY + ((RY - LY) >> 1)
        if y <= m: maxupdateY(vx, LX, RX, 2 * vy + 1, LY, m, x, y, h)
        else: maxupdateY(vx, LX, RX, 2 * (vy + 1), m + 1, RY, x, y, h)
        tree[vx][vy] = max(tree[vx][2 * vy + 1], tree[vx][2 * (vy + 1)])

def maxupdateX(vx, LX, RX, x, y, h):
    global n, c, MAXN, tree
    if LX != RX:
        m = LX + ((RX - LX) >> 1)
        if x <= m: maxupdateX(2 * vx + 1, LX, m, x, y, h)
        else: maxupdateX(2 * (vx + 1), m +1, RX, x, y, h)
    maxupdateY(vx, LX, RX, 0, 0, c - 1, x, y, h)

def main():
    global n, c, MAXN, tree, mintree
    n, c, MAXN = int(), int(), 1000
    mintree = [[0 for _ in range(MAXN * 4)] for _ in range(MAXN * 4)]
    tree = [[0 for _ in range(MAXN * 4)] for _ in range(MAXN * 4)]
    i = 0
    lines = stdin.readlines()
    n = int(lines[i].strip())

    j = 0
    a = []
    i += 1
    while j < n:
        Line = list(map(int, lines[i].strip().split()))
        a.append(Line)
        j += 1
        i += 1
    q = int(lines[i].strip())
    i += 1
    n = len(a)
    c = len(a[0])

    maxbuildX(a, 0, 0, n - 1)
    minbuildX(a, 0, 0, n - 1)
    count = 0
    while count < q:

        if(lines[i][0] == "q"):
            line = list(lines[i].strip().split()) 
            x1 = int(line[1]) - 1
            y1 = int(line[2]) - 1
            x2 = int(line[3]) - 1
            y2 = int(line[4]) - 1

            maxx = maxsumX(0, 0, n - 1, x1, x2, y1, y2)
            minn = minsumX(0, 0, n - 1, x1, x2, y1, y2)
            print(str(maxx) + " " + str(minn))
        else:
            line = list(lines[i].strip().split()) 
            x1 = int(line[1]) - 1
            y1 = int(line[2]) - 1
            h = int(line[3])
            maxupdateX(0, 0, n - 1, x1, y1, h)
            minupdateX(0, 0, n - 1, x1, y1, h)
        i += 1
        count += 1

main()