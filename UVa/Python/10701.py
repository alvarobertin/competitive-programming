from sys import stdin
def printpostorder(inorder, preorder, n): 
    # https://www.geeksforgeeks.org/print-postorder-from-given-inorder-and-preorder-traversals/?ref=rp
    global res
    
    if preorder[0] in inorder: 
        root = inorder.index(preorder[0]) 

    if root != 0: # left subtree exists 
        printpostorder(inorder[:root], 
        preorder[1:root + 1], 
        len(inorder[:root])) 

    if root != n - 1: # right subtree exists 
        printpostorder(inorder[root + 1:], 
        preorder[root + 1:], 
        len(inorder[root + 1:])) 
    res += (preorder[0])
		

def main():
    global res
    i = 1
    lines = stdin.readlines()
    while i < len(lines):
        res = ""
        line = lines[i].strip().split()
        n = int(line[0])
        preorder = line[1]
        inorder = line[2]
        printpostorder(inorder, preorder, n) 

        print(res)
    
        i += 1

        

main()