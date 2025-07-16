#include <iostream>

using namespace std;


template<typename T>
struct node{
  T value;
  int index;
};


int *x = new int[3];

template<typename T>
class Queue{
  public:
    explicit Queue(int capacity) :
      capacity_{capacity},
      front_{0},
      back_{0},
      size_{0},
      list_(new node[capacity])
      {}


  void push(T data){
    // FIFO is Queue
    // LIFO is Stack
    node<T> new_node = new node<T>;
    new_node.value = data;
    new_node.index = this->size_;

    if(size_ == capacity_){
      std::cout<<"error" <<std::endl;
    }

    if(this->size_ == 0){
      front_ = back_ = new_node;
    } 
    else{
      back_ ++;
      list_[back_].value = data;
      list_[back_].index = size_; 
    }

    // 1 _ _  
    // 1 2 _ 
    // 2 _ _ 

    


    
  }


  private:
    node<T> * list_;
    int size_;
    int front_;
    int back_;
    int capacity_;

};

int main(){



  return 0;
}
