# from dust i have come, dust i will be

'''
Cn is the nth catalan number
C0=C1=1,
Cn=sum(Ck*Cn-k-1), k=0 to n-1 n>=2
'''

data=[0]*1100
data[0]=1
data[1]=1

for i in range(2,1001):
    for j in range(i):
        data[i]+=(data[j]*data[i-j-1])

for line in sys.stdin:
    n=int(line)

    print(data[n])

'''
can be used to get various solutions
details: https://cp-algorithms.com/combinatorics/catalan-numbers.html
'''
