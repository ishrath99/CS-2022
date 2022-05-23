#!/bin/python3

import os

def DFS(adjacents, centers, u, k, visited, total_distance):
    for v in adjacents[u]:
        node = v[0]
        distance = v[1]
        
        if node not in visited:
            visited.append(node)
            total_distance += distance
            
            
            if node == n:
                fish_varieties = []
                for i in range(0,k):
                    fish_varieties.append(0)
                    
                for node in visited:
                    for i in centers[node - 1]:
                        fish_varieties[i-1] = 1
                paths.append([total_distance, fish_varieties])
            else:
                DFS(adjacents, centers, node-1, k, visited, total_distance)

            visited.pop()
            total_distance -= distance

def get_paths(adjacents, centers):
    global paths 
    visited = [1]
    paths = []
    total_distance = 0
    DFS(adjacents, centers, 0, k, visited, total_distance)
    return paths
            
def find_possible_path(p1, p2):
    if p2 == []:
        fishes = p1[1]
        if 0 in fishes:
            return False
        return True

    fishes = []
    for i in range(k):
        fishes.append(p1[1][i] + p2[1][i])
    
    if 0 in fishes:
        return False
    return True

#
# Complete the 'shop' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER n
#  2. INTEGER k
#  3. STRING_ARRAY centers
#  4. 2D_INTEGER_ARRAY roads
#

def shop(n, k, centers, roads):
    global adjacents
    
    for i in range (0, len(centers)):
        centers[i] = centers[i].split()

    centers = [j[1:] for j in centers]

    for j in centers:
        for i in range (0, len(j)):
            j[i] = int(j[i])

    adjacents = []
    for i in range(1, n + 1):
        adj = []
        for j in roads:
            if (j[0] == i):
                adj.append([j[1], j[2]])
            elif (j[1] == i):
                adj.append([j[0], j[2]])
        adjacents.append(adj)

    paths = get_paths(adjacents, centers)
    
    minimum_time = 20000001
    
    for i in range(len(paths)):
        p1 = paths[i]
        time = p1[0]
        if find_possible_path(p1, []) and minimum_time > time:
            minimum_time = time
    
    for i in range(len(paths)-1):
        for j in range(i+1,len(paths)):
            p1 = paths[i]
            p2 = paths[j]
            time = max(p1[0], p2[0])
            if find_possible_path(p1, p2) and minimum_time > time:
                minimum_time = time
                
    return minimum_time
                

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    first_multiple_input = input().rstrip().split()

    n = int(first_multiple_input[0])

    m = int(first_multiple_input[1])

    k = int(first_multiple_input[2])

    centers = []

    for _ in range(n):
        centers_item = input()
        centers.append(centers_item)

    roads = []

    for _ in range(m):
        roads.append(list(map(int, input().rstrip().split())))

    res = shop(n, k, centers, roads)

    fptr.write(str(res) + '\n')

    fptr.close()
