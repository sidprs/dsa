#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <queue>
#include <string>
#include <sstream>
#include <iterator>
// 
//
//
//
//

template<typename T>
struct vertex{
  int index;
  T weight;
  int value;
  bool visited = false;
};

template<typename T>
struct ELEMENT{
    T key;
    // other fields as you see fit
};

template<typename T>
struct HEAP{
    int capacity;   	  /* capacity of the heap */
    int size;          	/* current size of the heap */
    ELEMENT<T> **A;        /* array of pointers to ELEMENT */
    // other fields as you see fit
};

struct Queue{



};


template<typename T>
class Graph{
  public:
    explicit Graph(int cap) :
      capacity_{cap},
      KeySize_{0}
      //vertex_list_(new vertex[cap])
      {}
      
    std::unordered_map <int,std::vector<vertex<T>*>> map; 
    
    void push(int, int , T);
    //        ind  val weight
    void PrintMap();
   

    void PrintDFS();
    void PrintBFS();
    void PrintDKstra();
    void TopoSort();
    void FindAndRemoveCycles();
    

  private:
    HEAP<T> h;
    int capacity_;
    int KeySize_;
    
    // < vertex index,  list of all connected vertex 

};

// makes it adj automatically because goated
template <class T>
void Graph<T>::push(int index, int vertex_value, T weight){
  vertex<T> *new_vertex = new vertex<T>;
  new_vertex->index = index;
  new_vertex->value = vertex_value;
  new_vertex->weight = weight;
  if(map[index].size() < 0){
    this->KeySize_++;
  }
  
  vertex<T> *comp =  new vertex<T>;
  comp->index = vertex_value;
  comp->value = index;

  map[index].push_back(new_vertex); 
  map[vertex_value].push_back(comp);
}

template<typename T>
void Graph<T>::PrintMap() {
    for (const auto& [key, vec] : map) {
        std::cout << "key " << key << " : ";

        for (std::size_t i = 0; i < vec.size(); ++i) {
            std::cout << vec[i]->value;          // print the stored value
            if (i + 1 < vec.size()) {
                std::cout << ", ";               // comma only between items
            }
        }
        std::cout << '\n';
    }
}

template<class T>
void Graph<T>::PrintBFS()
{
  int source = 0;
  std::queue<int> q;
  std::unordered_map<int, bool> visited;  // Use map instead of vector
  std::vector<int> result;
  
  // Initialize all vertices as unvisited
  for (const auto& [key, vec] : map) {
    visited[key] = false;
  }
  
  // Check if source exists in the graph
  if (map.find(source) == map.end()) {
    std::cout << "Source vertex " << source << " not found in graph" << std::endl;
    return;
  }
  
  // Push the source node to queue
  q.push(source);
  visited[source] = true;
  
  // BFS traversal
  while(!q.empty()){
    int curr = q.front();  // Get front element
    q.pop();               // Remove front element
    result.push_back(curr);
    
    // Visit all adjacent vertices
    for(auto &vertex_ptr : map[curr]){
      int adj_index = vertex_ptr->value;  // Use 'value' field which stores the connected vertex
      if(visited.find(adj_index) != visited.end() && !visited[adj_index]){
        visited[adj_index] = true;
        q.push(adj_index);
      }
    }
  }
  
  // Print the BFS traversal result
  std::cout << "BFS traversal: ";
  for(int i = 0; i <result.size(); i++)
  {
    if(i != result.size() - 1){
      std::cout << result[i] << " -> ";
    }
    else{
      std::cout << result[i]  << "\n";
    }


  }

}

  
template<class T>
void Graph<T>::PrintDFS()
{

  


}

template<class T>
void Graph<T>::PrintDKstra()
{



}


template<class T>
void Graph<T>::TopoSort()
{


}


template<class T>
void Graph<T>::FindAndRemoveCycles()
{


}


int main (int argc, char *argv[]) {
  std::cout << "[ node, weight ]" << std::endl;
  Graph<int> g (3);  
  g.push(0, 3, 1);
  g.push(0, 2, 1);
  g.push(1, 5, 1);
  g.push(1, 2, 1);
  g.push(1, 3, 1);
  //g.push(1);

  g.PrintMap();
  g.PrintBFS();
  // 0 -> 3, 2
  // 1 -> 5, 2, 3
  // 2 -> 0, 1
  // 3 -> 0, 1
  // 5 -> 1

  return 0;
}
/*
TODO:
  implement min-heap so i can properly create a Graph
  implement all other functions 



*/





