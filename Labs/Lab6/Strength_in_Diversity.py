
def DFS(u):
    if visited[u]:
        return
    visited[u] = True
    global vertices
    vertices += 1
    
    for i in graph[u]:
        if not visited[i] :
            DFS(i)


inp = list(map(int, input().split()))
n = inp[0]
p = inp[1]

graph = [[] for i in range(n)]
visited = [False for i in range(n)]   

for i in range(p):
    inp = list(map(int, input().split()))
    u = inp[0]
    v = inp[1]
    
    graph[u].append(v)
    graph[v].append(u)

combinations = n*(n-1)/2
for i in range(n):
    vertices = 0
    DFS(i)
    combinations = combinations - vertices*(vertices-1)/2
    
print(int(combinations))

            
            
            
            