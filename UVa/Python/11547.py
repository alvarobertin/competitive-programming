# 11547 https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=607&page=show_problem&problem=2542

#“Multiplynby 567, then divide the result by 9, then add 7492, 
#then multiply by 235, then divideby 47, then subtract 498. What is the digit in the tens column?”



t = int(input(""))
i = 0
n = []
while i < t:
	n.append(int(input("")))
	i +=1

result = []

for p in n:
	x = p

	x = x*567
	x = x//9
	x = x+7492
	x = x*235
	x = x//47
	x =x-498

	x = (abs(x)%100)//10
	result.append(x)

for z in result:
	print(z)
