#include "graph.h"

void Graph::buildGraph(ifstream &input)
{
    int new_node;
    while (input >> new_node)
    {
        // Insert the root node
        node_list.push_back(Vertex(new_node, 0)); // Insert nodes into node_list
        adj_list.push_back(new list<int>);
        adj_list[adj_list.size() - 1]->push_back(new_node);

        // Insert adj_node
        int adj_node;
        while (input >> adj_node)
        {
            if (adj_node == -1)
                break;
            adj_list[adj_list.size() - 1]->push_back(adj_node);
        }
    }
}

void Graph::displayGraph()
{
    cout << "List of nodes: ";
    for (int i = 0; i < node_list.size() - 1; ++i)
        cout << node_list[i].label << ", ";
    cout << node_list[node_list.size() - 1].label << endl;

    for (int i = 0; i < adj_list.size(); ++i)
    {
        for (auto x : *adj_list[i])
        {
            if (x == adj_list[i]->front())
                cout << x << ": ";
            else
                cout << x << " ";
        }

        cout << endl;
    }
}