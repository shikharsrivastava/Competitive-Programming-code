from random import randint

t = 1
print(t)
n = randint(1,100000)
print(n)
for i in range(n):
	x = randint(-10000,10000)
	y = randint(-10000,10000)
	print('+',x,y)
