#code
depth=[]
evens=0
odds=0
# def dfs(graph,visited,node,count):
#     global tocount

#     if visited[node]:
#         return 0
    
#     visited[node]=True
#     evendist=0
#     for i in range(len(graph[node])):
#         evendist=evendist+dfs(graph,visited,graph[node][i],count+1)
        
#     if count%2==0 and count!=0 and tocount[node]:
#         return 1+evendist
#     else:
#         return evendist

def dfs(graph,visited,node,count):
    global depth,evens,odds

    if visited[node]:
        return
    
    depth[node]=count

    if count%2==0:
    	evens=evens+1
    else:
    	odds=odds+1
    visited[node]=True
    for i in range(len(graph[node])):
        dfs(graph,visited,graph[node][i],count+1)
        
           


T=int(input())

for i in range(T):
    N=int(input())
    if N==1:
        print(0)
        continue
    
    edges=list(map(int,input().strip().split(' ')))
    
    graph=list()
    for j in range(N):
        graph.append(list())
    
    visited=list()
    for j in range(N):
        visited.append(False)

    depth=list()
    for j in range(N):
        depth.append(0)

    for j in range(N-1):
        graph[edges[0]-1].append(edges[1]-1)
        graph[edges[1]-1].append(edges[0]-1)
        
        del(edges[0])
        del(edges[0])
        
    count=0
    evens=0
    odds=0

    dfs(graph,visited,0,count)

    count=evens*(evens-1)/2 + odds*(odds-1)/2

    # for j in range(N):
    # 	for k in range(j+1,N):
    # 		if (depth[j]+depth[k])%2==0:
    # 			count=count+1

        
        
    print(int(count))
        
    
        
    