#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <list>
#include <queue>
#include <fstream>
#include <iostream>

using namespace std;

struct Vertex
{
  int label; // unique int for a vertex
  int indegree; // Part 2
  int top_num; // Part 2: topological sorting number
  Vertex(int l, int ind = 0, int tn = 0) : label(l), indegree(ind), top_num(tn) {} //Part 2
};

class Graph
{
private:
  vector<Vertex> node_list;
  vector<list<int> *> adj_list;

public:
  Graph(){}; // default constructor
  ~Graph()
  {
    for (int i = 0; i < adj_list.size(); ++i)
      delete adj_list[i];
  }
  // build a graph
  void buildGraph(ifstream &input);
  // display the graph
  void displayGraph();
  // topological sort
  void topological_sort(); // Part 2
  // find indegree
  void compute_indegree(); // Part 2
  // print topological sort
  void print_top_sort(); // Part 2
};

#endif
