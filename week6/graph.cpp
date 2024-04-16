#include <iostream>

#define V 5

bool isPathExist(int graph[V][V], int src, int dest, bool visited[]) 
{
    if (src == dest)
        return true;

    visited[src] = true;

    for (int i = 0; i < V; ++i) 
    {
        if (graph[src][i] && !visited[i])
         {
            if (isPathExist(graph, i, dest, visited))
                return true;
        }
    }

    return false;
}

int main() 
{
    int graph[V][V] = 
    {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 1, 0},
        {0, 1, 1, 0, 1},
        {1, 1, 0, 1, 0}
    };
    
    int src;
    int dest;

    std::cout << "enter source node:";
    std::cin  >> src;
    
    std::cout << "enter destination";
    std::cin  >> dest;


    bool visited[V] = {false};

    if (isPathExist(graph, src, dest, visited))
        std::cout << "Path exists from node " << src << " to node " << dest << std::endl;
    else
        std::cout << "No path exists from node " << src << " to node " << dest << std::endl;

    return 0;
}