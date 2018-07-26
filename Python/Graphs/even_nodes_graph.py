#code

# Given a connected acyclic graph with N nodes and N-1 edges, find out the pair of nodes that are at even distance from each other.

# Input:

# The first line of input contains an integer T denoting the number of test cases.

# First line of each test case contains a single integer N denoting the number of nodes in graph.

# Second line of each test case contains N-1 pair of nodes xi , yi denoting that there is an edges between them.


# Output:

# For each test case output a single integer denoting the pair of nodes which are at even distance.


# Constraints:

# 1<=T<=10

# 1<=N<=10000

# 1<=xi,yi<=N

# Example

# Input

# 1

# 3

# 1 2 2 3

# Output

# 1

# Explanation:

# Only such pair is (1,3) where distance b/w them is 2


############################################################################################




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
        
    
        
    