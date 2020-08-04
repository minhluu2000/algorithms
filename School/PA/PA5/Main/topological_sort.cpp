// topological sort

#include <iostream>
#include <stdexcept>

#include "graph.h"

void Graph::compute_indegree()
{
  for (int i = 0; i < adj_list.size(); ++i)
  {
    for (auto x : *adj_list[i])
    {
      if (x != adj_list[i]->front())
        node_list[x - 1].indegree += 1;
    }
  }
}

void Graph::topological_sort()
{
  cout << "Topological sorting..." << endl;
  queue<Vertex *> q;
  int counter = 0;

  for (int i = 0; i < node_list.size(); ++i)
  {
    if (node_list[i].indegree == 0)
      q.push(&node_list[i]);
  }

  while (!q.empty())
  {
    Vertex *v = q.front();
    q.pop();
    v->top_num = ++counter;

    for (int adj_node : *adj_list[v->label - 1])
    {
      if (--node_list[adj_node - 1].indegree == 0)
        q.push(&node_list[adj_node - 1]);
    }
  }
  if (counter != node_list.size())
    throw invalid_argument("Cycle found!");
}

void Graph::print_top_sort()
{
  vector<Vertex> clone = node_list;
  for (int i = 0; i < clone.size(); ++i)
  {
    for (int j = 0; j < clone.size() - i - 1; ++j)
    {
      if (clone[j].top_num > clone[j + 1].top_num)
      {
        Vertex temp = clone[j];
        clone[j] = clone[j + 1];
        clone[j + 1] = temp;
      }
    }
  }
  cout << "Topological sort: ";
  for (auto node : clone)
    cout << node.label << " ";
  cout << endl;
}
