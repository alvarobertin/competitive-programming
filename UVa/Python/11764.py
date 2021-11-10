#https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2864

T = int(input(""))
i = 0
rhigh = []
rlow = []
while i < T:

	n = int(input(""))

	x = input("")
	x = x.split(" ")
	newx = []
	for u in x:
		newx.append(int(u))
	x = newx

	z = 0
	high = 0
	low = 0
	while z < len(x)-1:

		if x[z] < x[z+1]:
			high +=1
		elif x[z] > x[z+1]:
			low +=1
		z += 1


	rhigh.append(high)
	rlow.append(low)

	i+=1
z = 1
while z <= T:
	print("Case "+str(z)+":",rhigh[z-1],rlow[z-1])
	z +=1