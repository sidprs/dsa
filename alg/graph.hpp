#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>

// dijk
// 1. make node index 0 
//
//
//
//

template<typename T>
struct vertex{
  int index;
  int weight;
  T value;
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
    int KeySize_;
    
    void push(int,T);
    void printmap();
    

  private:
    int capacity_;
    // < vertex index,  list of all connected vertex 

};

template <class T>
void Graph<T>::push(int index, T vertex_value){
  vertex<T> *new_vertex = new vertex<T>;
  new_vertex->index = index;
  new_vertex->value = vertex_value;
  if(map[index].size() > 0){
    std::cout << "appending to existing list" << std::endl;
  }
  else{
    std::cout << "new list" << std::endl;
    KeySize_++;
  }
  map[index].push_back(new_vertex); 
}

template <class T>
void Graph<T>::printmap()
{
    for (const auto& [key, vec] : map)           // C++17 structured binding
    {
        std::cout << "key " << key << " : ";
        for (const auto* v : vec) {              // vec holds vertex<T>* pointers
            std::cout << v->value << ' ';        // print the payload, not the index
        }
        std::cout << '\n';
    }
}


int main (int argc, char *argv[]) {
  Graph<int> g (3);  
  g.push(0, 3);
  g.push(0, 2);
  g.push(1, 1);
  g.push(1, 2);
  g.push(1, 3);
  //g.push(1);


  g.printmap();

  std::cout <<g.KeySize_ << std::endl;

  return 0;
}

