#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

void DFSprint(const std::unordered_map<char, std::vector<char> >& graph, char start) {
    std::vector<char> visited; // To keep track of visited nodes
    std::stack<char> stack; // Use stack for DFS
    stack.push(start);

    while (!stack.empty()) {
        char vertex = stack.top();
        stack.pop();

        // Check if not visited
        if (std::find(visited.begin(), visited.end(), vertex) == visited.end()) {
            visited.push_back(vertex);
            std::cout << vertex << " "; // Print visited node

            // Iterate through the neighbors of the current vertex
            for (auto it = graph.at(vertex).rbegin(); it != graph.at(vertex).rend(); ++it) {
                char neighbour = *it;
                if (std::find(visited.begin(), visited.end(), neighbour) == visited.end()) {
                    stack.push(neighbour);
                }
            }
        }
    }
}

void DFSprintRecursive(const std::unordered_map<char, std::vector<char> >& graph, char start, std::vector<char>& visited) {
    visited.push_back(start);
    std::cout << start << " "; // Print visited node

    for (auto neighbour : graph.at(start)) {
        if (std::find(visited.begin(), visited.end(), neighbour) == visited.end()) {
            DFSprintRecursive(graph, neighbour, visited);
        }
    }
}

int main() {
    // Graph representation
    std::unordered_map<char, std::vector<char> > graph = {
        {'a', {'b', 'c'}},
        {'b', {'d', 'e'}},
        {'c', {'f'}},
        {'d', {}},
        {'e', {'f'}},
        {'f', {}}
    };

    // Start DFS from node 'a'
    std::cout << "DFS starting from node a: ";
    DFSprint(graph, 'a');
    std::cout << std::endl;

    std::cout << "DFS starting from node a (recursive): ";
    std::vector<char> visited;
    DFSprintRecursive(graph, 'a', visited);
    std::cout << std::endl;

    return 0;
}


