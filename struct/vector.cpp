

// how does a vector work
#pragma once

template<class T>
class Vector{

    public:
    typedef T * iterator;

    Vector();
    Vector(unsigned int size);
    Vector(unsigned int size, const T & initial);
    Vector(const Vector<T> & v);      
    ~Vector();

    unsigned int capacity() const;
    unsigned int size() const;
    bool empty() const;
    iterator begin();
    iterator end();
    T & front();
    T & back();
    void push_back(const T & value); 
    void pop_back();  

    void reserve(unsigned int capacity);   
    void resize(unsigned int size);   

    T & operator[](unsigned int index);  
    Vector<T> & operator=(const Vector<T> &);
    void clear();
    
    private:
        unsigned int size_;
        unsigned int cap_;
        T * buff_;

};

// no void because this is a constructor not a function

template <typename T>
Vector<T>::Vector()
    : size_(0), cap_(0), buff_(nullptr) {
}

template <typename T>
Vector<T>::Vector(unsigned int size)
    : size_(size), cap_(size) {
    buff_ = new T[cap_];
}


// ( size, all the values they are set to )
template <typename T>
Vector<T>::Vector(unsigned int size, const T & initial)
    : size_(size), buff_(new T[size]) {

    for(unsigned int i = 0; i < buff_->length(); i++){
        buff_[i] = initial;
    }
}
template <typename T>
Vector<T>::Vector(const Vector<T> & v){
    // pass a vector to copy? whats the difference between this and the copy constructor

}


int main(){
    return 0;
}