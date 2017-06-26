#include <iostream>
#include <vector>
#include <memory>

#include "FragmentClass.hpp"

using namespace std;

int main(void){

  cout << "Testing Fragment Constructor" << endl;
  {
    vector<int> v;
    v.push_back(1);
    Fragment frag = Fragment(v);
  }

  cout << "Testing Second Fragment Constructor" << endl;
  { 
    vector<vector<int>> edges;
    vector<int> array; 
    array.push_back(2);
    array.push_back(3);
    edges.push_back(array);
    vector<int> array2;
    array2.push_back(1);
    array2.push_back(3);
    edges.push_back(array2);
   
    vector<int> vertex;
    vertex.push_back(1);
    vertex.push_back(2);
  
    Fragment frag = Fragment(vertex,edges);
    
  } 

  cout << "Testing Fragment output << " << endl;
  { 
    vector<vector<int>> edges;
    vector<int> array; 
    array.push_back(2);
    array.push_back(3);
    edges.push_back(array);
    vector<int> array2;
    array2.push_back(1);
    array2.push_back(3);
    edges.push_back(array2);
   
    vector<int> vertex;
    vertex.push_back(1);
    vertex.push_back(2);
  
    Fragment frag = Fragment(vertex,edges); 
    cout << frag << endl;
  }

  return 0;
}
