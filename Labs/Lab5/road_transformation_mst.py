inp = list(map(int, input().split()))
N = inp[0]
M = inp[1]
k = inp[2]
G = []
for i in range(M):
    inp = list(map(int, input().split()))
    G.append((inp[2], inp[0]-1, inp[1]-1))
G.sort()

parents = []
for i in range(N):
    parents.append(i)

def findSet(city):
    if city == parents[city]:
        return city
    else:
        return findSet(parents[city])
    
MST = []   

for i in range(len(G)):
    u = G[i][1] 
    v = G[i][2]
    if findSet(u) != findSet(v):
        MST.append([G[i][1]+1, G[i][2]+1, G[i][0]])
        parents[findSet(u)] = parents[findSet(v)]
            
# print(MST)
costs = list(list(zip(*MST))[2])
total_cost = sum(costs)
# print(sum(costs))

trans = 0

if len(MST) != N - 1:
    print("-1")
else:
    for i  in range(len(costs)):
        if costs[-1] == 0:
            costs.pop()
            continue
        total_cost += (1 - costs.pop())
        trans += 1
        if total_cost <= k:
            break

    if total_cost > k:
        print("-1")
    else:
        print(trans)
       
    
        

