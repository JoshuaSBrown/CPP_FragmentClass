
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

Fragment::Fragment(vector<int> vertex, vector<vector<int>> edges){
  // iterate through all the vertices
  // and create new nodes for all of them
  auto it2 = edges.begin();
  auto it  = vertex.begin();
  while( it!=vertex.end() && it2!=edges.end()){
    SimpleNode<int> sn_temp(*it,*it2);
    this->sn.push_back(make_shared<SimpleNode<int>>(sn_temp));
    ++it;
    ++it2;
  } 
  // Assign the id of the fragment from a file scope id parameter 
  this->id = frag_id;
  frag_id++; 
}

// The function will only add an edge it will not add a node if the 
// edge does not correspond to a node already existing within the 
// fragment.
//
// Note that if the nodes the edges describe are not in the fragment
// then nothing is done. If one node is found then the edge for that
// node is updated but if the other one is not in the fragment a new
// node is NOT created (nothing is done). 
void Fragment::addEdge(vector<int> edge){
  // Look to see what vertices are described by the edges
  int ID1 = edge.at(0);
  int ID2 = edge.at(1);

  // Cycle through nodes
  for(auto it=this->sn.begin();it!=this->sn.end();++it){
    if(it->get()->getID()==ID1){
      //Check to see if ID1 is already got the connection to 
      //ID2 we should not add it if it does
      int add = 1; // 0 - don't add 1 - add
      for(auto it2=it->get()->begin();it2!=it->get()->end();++it2){
        if(*it2==ID2){
          // Don't add and exit
          add = 0;
          break;
        }
      }
      if(add){
        it->get()->addE(ID2);
      }
    }
    if(it->get()->getID()==ID2){
      int add = 1;
      for(auto it2=it->get()->begin();it2!=it->get()->end();++it2){
        if(*it2==ID1){
          add = 0;
          break;
        }
      }
      if(add){
        it->get()->addE(ID1);
      }
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
