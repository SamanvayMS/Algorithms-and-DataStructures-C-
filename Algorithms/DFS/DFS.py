graph = {
    'a' : ['b', 'c'],
    'b' : ['d', 'e'],
    'c' : ['f'],
    'd' : [],
    'e' : ['f'],
    'f' : []
}

def DFSprint(graph, start, visited):
    stack = [start]
    while len(stack) > 0:
        vertex = stack.pop()
        visited.append(vertex)
        for neighbour in graph[vertex]:
            if neighbour not in visited:
                stack.append(neighbour)
                
    return visited

def DFSprintRecursive(graph, start, visited):
    visited.append(start)
    for neighbour in graph[start]:
        if neighbour not in visited:
            DFSprintRecursive(graph, neighbour, visited)
    return visited
print("DFS using stack")
print(DFSprint(graph, 'a', []))

print("DFS using recursion")
print(DFSprintRecursive(graph, 'a', []))
