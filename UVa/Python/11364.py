#https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=607&page=show_problem&problem=2349         
t = int(input(""))
i = 0
result = []
while i < t:

	n = int(input(""))
	x = input("")
	x = x.split(" ")
	newx = []
	for u in x:
		newx.append(int(u))
	x = newx
	x.sort()
	z = 0
	y = 0
	while z < len(x)-1:
		y += int(x[z+1]) - int(x[z])	
		z += 1
	result.append(y*2)
	i += 1

for g in result:
	print(g)
