from random import randint

n = randint(2,100)
p = randint(2,n);
print(n,p)
for i in range(n):
	for j in range(n):
		print(randint(1,1000000000),end = ' ')
	print()
