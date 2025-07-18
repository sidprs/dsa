#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>


// 
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







template<typename T>
class Graph{
  public:
    explicit Graph(int cap) :
      capacity_{cap},
      KeySize_{0},
      //vertex_list_(new vertex[cap])
      {}
      
    std::unordered_map <int,std::vector<vertex<T>*>> map; 
    
    void push(int, T, int);
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

template <class T>
void Graph<T>::push(int index, T vertex_value, int weight){
  vertex<T> *new_vertex = new vertex<T>;
  new_vertex->index = index;
  new_vertex->value = vertex_value;
  new_vertex->weight = weight;
  if(map[index].size() < 0){
    this->KeySize_++;
  }
  map[index].push_back(new_vertex); 
}

template <class T>
void Graph<T>::PrintMap()
{
    for (const auto& [key, vec] : map)           // C++17 structured binding
    {
        std::cout << "key " << key << " : ";
        for (const auto* v : vec) {              // vec holds vertex<T>* pointers
            std::cout << "[ " << v->value << " , " << v->weight << " ] " ;        
        }
        std::cout << '\n';
    }
}

template<class T>
void Graph<T>::PrintDFS()
{


}


template<class T>
void Graph<T>::PrintBFS()
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
  g.push(0, 3, 2);
  g.push(0, 2, 1);
  g.push(1, 1, 1);
  g.push(1, 2, 1);
  g.push(1, 3, 1);
  //g.push(1);


  g.PrintMap();

  std::cout <<g.KeySize_ << std::endl;

  return 0;
}
/*
TODO:
  implement min-heap so i can properly create a Graph
  implement all other functions 



*/





