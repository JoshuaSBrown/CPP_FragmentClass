
#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "FragmentClass.hpp"

using namespace std;

static int frag_id = 0;

Fragment::Fragment(vector<int> vertex){
  // Cycle throught the vertex vector and add each vertex as an empty node
  // but with an id that is equal to the vertex
  for(auto it = vertex.begin();it!=vertex.end();++it){
    cout << *it << endl;
    SimpleNode<int> sn_temp(*it);
    this->sn.push_back(make_shared<SimpleNode<int>>(sn_temp));
  }
  // Assign the id of the fragment from a file scope id parameter
  this->id = frag_id;
  frag_id++;
}

Fragment::Fragment(vector<int> vertex, vector<vector<int>> neighbors){
  // iterate through all the vertices
  // and create new nodes for all of them
  auto it2 = neighbors.begin();
  auto it  = vertex.begin();
  while( it!=vertex.end() && it2!=neighbors.end()){
    SimpleNode<int> sn_temp(*it,*it2);
    this->sn.push_back(make_shared<SimpleNode<int>>(sn_temp));
    ++it;
    ++it2;
  }
  // Assign the id of the fragment from a file scope id parameter
  this->id = frag_id;
  frag_id++;
}

void Fragment::addEdge(vector<int> edge){
  int ID1 = edge.at(0);
  int ID2 = edge.at(1);
  addVertex(ID1);
  addVertex(ID2);
  // Cycle through nodes
  for(auto it=this->sn.begin();it!=this->sn.end();++it){
    if(it->get()->getID()==ID1){
      it->get()->addE(ID2);
    }
    if(it->get()->getID()==ID2){
      it->get()->addE(ID1);
    }
  }

}

// This function works by checking to see if the vertex already exists
// in the fragment. If the vertex does not exist it adds it to the
// fragment.
void Fragment::addVertex(int vert){
  // Cycle through nodes to see if the vertex has already been added
  int add = 1; // add the vertex if add == 1 after the for loop
  for(auto it=this->sn.begin();it!=this->sn.end();++it){
    if(it->get()->getID()==vert){
      add = 0;
      break;
    }
  }
  if(add){
    SimpleNode<int> sn_temp(vert);
    this->sn.push_back(make_shared<SimpleNode<int>>(sn_temp));
  }
}

ostream & operator<<(ostream &os,const Fragment frag){
  os << "Fragment id " << frag.id << endl;
  os << "Vertices in Fragment and their edges" << endl;
  // Cycle through nodes
  int size = frag.sn.size();
  int node_index = 0;
  while(node_index<size){
    os << frag.sn.at(node_index).get()->getID() << "\t";
    for(auto it = frag.sn.at(node_index).get()->begin();it!=frag.sn.at(node_index).get()->end();++it){
      os << *it << " " ;
    }
    os << endl;
    node_index++;
  }
  os << "Finished"<< endl;
}

struct _node{
  bool visited = false;
  int previous = -1;
  int id;
};

typedef struct _node node;

std::vector<Fragment> findSmallCycles(std::vector<int> all_vertices, std::vector<std::vector<int>> all_neighbors{
  std::vector<std::vector<int>> visited_neighbors = all_neighbors;
  bool visited = false;
  for (int i=0; i<all_vertices.size(); i++){
    if (visited_neighbors.at(i).size() < 2){
      all_vertices.erase(all_vertices.begin()+i);
      visited_neighbors.erase(visited_neighbors.begin()+i);
      i--;
    }
  }
  node curr;
  curr.previous = all_vertices.at(0);
  curr.id = curr.visited_neighbors.at(0);
  visited_neighbors.erase(curr.previous)
}

/* 1. Duplicate the vector of neighbors, which will store the ids of the visited neighbors.
 * 2. Iterate through all the vertices and remove the ones that have only one connection.
 * 3. Pick the first atom of the vector all_vertices.
 * 4. Mark it as visited. Go to the first atom connected to it.
 * 5. Check if it has been visited already. If not, go to 6. If yes, go to 7.
 * 6. Remove the id of the atom it came from from its visited neighbors. Go to 4.
 *
 * 7. "Extract all elements between the repeating ids. store in new obj."
 * 8.
 *
 *
 *
 */
}
