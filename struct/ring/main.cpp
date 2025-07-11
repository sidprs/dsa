#include <iostream>
#include <vector>

// tesla interview

template<typename T>
struct node{
  T value;
  int index = 0;
};




template<typename T>
class RingBuffer {
 public:
  explicit RingBuffer(size_t cap)
      : capacity_{cap},
        size_{0},
        list_{nullptr},
        head_{0},
        tail_{0} 

    {
        if (cap == 0)
            throw std::invalid_argument("RingBuffer capacity must be > 0");
            list_ = new node<T>[cap];
    }

        

  
  // FIFO 
  // 1, 2, 3, 4
  // 5, 2, 3

  void push(T value){
    node<T> n{value, size_};

    if(this->size_ == this->capacity_){
      std::cout << "overwrite" << std::endl;
      this->head_ = (this->head_ + 1) % this->capacity_;
    }
    this->size_++;
    list_[this->tail_] = n;    
    this->tail_ = (this->tail_ + 1) % this->capacity_;
    
 

  }

  node<T> pop(){
        node<T> n = list_[head_];
    if(!this->list_){
      std::cout << "error empty" << std::endl;
    }
    n.value = this->list_[this->head_].value;

    this->size_--;
   
    this->head_ = (this->head_ + 1) % this->capacity_;


    return n;
  }

 private:
  node<T> *list_;
  int capacity_;
  int size_;
  int head_;
  int tail_;
  

};

int main(int argc, char *argv[]) { 
  RingBuffer<int> r(4);

    r.push(1);
    r.push(2);
    r.push(3);
    r.push(4);
    r.push(5);           // overwrites 1

    auto n = r.pop();    // pops 











  return 0; }
