#ifndef _FRAGMENT_CLASS_
#define _FRAGMENT_CLASS_

#include <vector>
#include <memory>
#include <string>

#include "../CPP_SimpleNode/SimpleNode.hpp"

// This class is responsible for taking a vector with the id's of a vertex
// and the vectors of the each vertex that describe the connections
// The class object can then search through the vector and determine where
// cycles exist. When cycles are found it will spawn new fragments.

class Fragment {
  private:
    // A fragment contains nodes which each must have a unique id
    // The nodes correspond to each of the vertex
    int id;
    std::vector<std::shared_ptr<SimpleNode<int>>> sn;
  public:

    Fragment(std::vector<int> vertex);
    Fragment(std::vector<int> vertex, std::vector<std::vector<int>> neighbors);
    void addEdge(std::vector<int> edge);
    void addVertex(int vert);

    friend std::ostream & operator<<(std::ostream &os, Fragment frag);
};
#endif

// This function will go through a list of vertices and all the edges between
// the vertices and find all the fragments
// As it finds smaller and smaller fragments the original fragments will be split
// Once there are no smaller fragments. A vector of all the small fragments will
// be returned
