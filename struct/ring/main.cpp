#include <iostream>
#include <vector>

// tesla interview

class RingBuffer {
 public:
  explicit RingBuffer(int cap)
      : capacity_{cap},
        size_{0},
        list_{new int[capacity_]},
        head_{0},
        tail_{0} {}

 private:
  int capacity_;
  int size_;
  int *list_;
  int head_;
  int tail_;
};

int main(int argc, char *argv[]) { return 0; }
