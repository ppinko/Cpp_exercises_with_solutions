/*
Having number of nodes - graph_nodes and vector of edges represented 
as vector of starting points and ending points - graph_from - graph_to,
create an adjacency list.
*/

#include <vector>
#include <iostream>
#include <iterator>

std::vector<std::vector<int>> adjacency_list (int graph_nodes, std::vector<int> graph_from,
    std::vector<int> graph_to);

std::vector<std::vector<int>> adjacency_list (int graph_nodes, std::vector<int> graph_from,
    std::vector<int> graph_to)
{
    std::vector<std::vector<int>> result (graph_nodes + 1, std::vector<int>(0, 0));
    for (int i = 0; i < graph_from.size(); ++i)
    {
        result[graph_from[i]].push_back(graph_to[i]);
        result[graph_to[i]].push_back(graph_from[i]);
    }
    return result;
}


int main(){
    int graph_nodes = 5;
    std::vector<int> graph_from {1, 2, 2, 3};
    std::vector<int> graph_to {2, 3, 4, 5};

    auto vec = adjacency_list(graph_nodes, graph_from, graph_to);
    for (int i = 0; i < vec.size(); ++i)
    {   
        if (i == 0)
            continue;
        std::cout << "Node n = " << i << ", edges to: ";
        for (int j = 0; j < vec[i].size(); ++j)
        {
            std::cout << vec[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}