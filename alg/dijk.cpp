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
  T value;
};


template<typename T>
class Graph{
  public:
    explicit Graph(int cap) :
      capacity_{cap},
      size_{0}
      //vertex_list_(new vertex[cap])
      {}
      
    std::unordered_map <int,std::vector<vertex<T>>> map; 
    int size_;
    
    void push(int,T);
    void printmap();
    

  private:
    int capacity_;
    // < vertex index,  list of all connected vertex 




};

template <class T>
void Graph<T>::push(int index, T vertex_value){
  vertex<T> new_vertex;
  new_vertex.index = index;
  new_vertex.value = vertex_value;
  if(map[index].size() > 0){
    std::cout << "appending to existing list" << std::endl;
  }
  else{
    std::cout << "new list" << std::endl;
    size_++;
  }
  map[index].push_back(new_vertex); 
}

template <class T>
void Graph<T>::printmap(){
  for(int i = 0 ; i < map.first; i++){
    for(int j = 0; j < map[i].second; j++){

    }
  }



}


int main (int argc, char *argv[]) {
  Graph<int> g (3);  
  g.push(0, 3);
  g.push(0, 2);
  g.push(1, 2);
  //g.push(1);

  std::cout <<g.size_ << std::endl;

  return 0;
}

