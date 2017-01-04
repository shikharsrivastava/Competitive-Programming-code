from math import *
from fractions import *
def gcd(a,b):
 while a%b != 0:
  a,b=b,a%b
 return b

def lcm(a,b):
 a,b=abs(a),abs(b)
 return (a*b)//gcd(a,b)

t=int(input())
n,k=map(int, input().split())
a,b,m=map(int, input().split())
c=list(map(int,input().split()))
d=list(map(int,input().split()))

y=max(m,n)
f = [[0 for i in range(y+1)] for j in range(y+1)]


for i in range(1,y+1):
 f[i][1]=i


for i in range(1,y+1):
 for j in range(2,i+1):
  frac1=Fraction(1,f[i-1][j-1])
  frac2=Fraction(1,f[i][j-1])
  f[i][j]=int(floor(1.0/float(frac1-frac2)))

l=1
for i in range(1,k+1):
 l=lcm(l,f[n][i])
l=l%1000000007
print(l)


for i in range(0,t-1):
 n=1+(a*l+c[i])%m
 k=1+(b*l+d[i])%n
 l=1
 for j in range(1,k+1):
  l=lcm(l,f[n][j])
 l=l%1000000007
 print(l)
 


