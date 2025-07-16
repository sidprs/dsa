#include <iostream>
using namespace std;

template<typename T>
struct node{
  int index;
  node<T> *next = nullptr;
  T value;
};


template<typename T>
class LinkedList {
  public:
    explicit LinkedList(int capacity)
      : capacity_{capacity},
        size_{0},
        head_{nullptr},
        tail_{nullptr}
    {}
  


  /*
    FIFO 

    a -> b -> c

    1. if its the first value (index  = 0)
       make the head the new_node
    2. if its not the first value then
       head -> next = new_node
       head = new_node

  */
    void push(const T& val) {
        if (size_ == capacity_) {
            std::cerr << "stack full\n";
            return;
        }
        auto* new_node = new node<T>;
        new_node->value = val;
        new_node->index = size_;
        new_node->next  = head_;   // old head follows the new node
        head_ = new_node;
        ++size_;
    }

    // LIFO pop: remove from the FRONT (head)  ───────────────────────────
    T pop() {
        if (!head_) {
            throw std::runtime_error("pop from empty stack");
        }
        node<T>* old_head = head_;
        T  ret   = old_head->value;
        head_    = old_head->next;   // move head forward
        delete old_head;
        --size_;
        return ret;
    }
    void insert(int index, const T& val)
    {
        if (!head_) {                         // empty list
            std::cerr << "empty list\n";
            return;
        }

        node<T>* curr = head_;
        while (curr && curr->index != index)  // search for the target node
            curr = curr->next;

        if (!curr) {                          // index not present
            std::cerr << "index " << index << " not found\n";
            return;
        }

        auto* new_node = new node<T>;
        new_node->value = val;
        new_node->index = ++size_;            // or whatever numbering you want
        new_node->next  = curr->next;
        curr->next      = new_node;
    }



    void print() const {
        for (node<T>* curr = head_; curr; curr = curr->next)
            std::cout << "node " << curr->index
                      << "  val "  << curr->value << '\n';
    }

  private:
    int capacity_;
    int size_;
    node<T> *head_;
    node<T> *tail_;





};





int main(){

  LinkedList<int> l(3);
  l.push(1);
  l.push(2);
  l.push(3);
  l.print();
  l.pop();
  cout << "----" <<endl;
  l.insert(1, -1);
  l.print();
  return 0;
}
