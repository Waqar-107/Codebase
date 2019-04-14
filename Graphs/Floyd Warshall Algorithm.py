#from dust i have come, dust i will be

import sys

def floydWarshall(dist,n):

    for k in range(1,n):
        for i in range(1,n):
            for j in range(1,n):
                if dist[i][k]+dist[k][j]<dist[i][j]:
                    dist[i][j]=min(dist[i][k]+dist[k][j], dist[i][j])

    for i in range(1,n):
        for j in range(1,n):
            sys.stdout.write(str(dist[i][j])+" ")

        print()


inf=1000000000
n,m=map(int,input().split())

adj=[[inf]*(n+1) for i in range(n+1)]
for i in range(1,m+1):
    u,v,d=map(int,input().split())
    adj[u][v]=d

for i in range(1,n+1):
    adj[i][i]=0

floydWarshall(adj,n+1)
