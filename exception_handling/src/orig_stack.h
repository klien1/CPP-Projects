// Kevin Lien
// File: orig_stack.h


#ifndef STACK_H
#define STACK_H

#include <iostream>
using std::cerr;
using std::endl;

template <typename T>
class Stack
{
  public:
    Stack();
    Stack(const Stack<T>&);
    ~Stack();
    Stack& operator=(const Stack<T>&);
    int size() const;
    void push(const T&);
    T& pop();
    void status();
  private:
    static const int chunk_size;
    int current_size;
    unsigned maximum_size;
    T* base;
};


template <typename T>
const int Stack<T>::chunk_size=10;

template<typename T>
void Stack<T>::status() {
  cerr << endl << "max: " << maximum_size << endl;
  cerr << "cur: " << current_size << endl;
  cerr << "base: " << base << endl << endl;
}

template <typename T>
Stack<T>::Stack()
:current_size(-1),maximum_size(chunk_size),base(new T[chunk_size]) // default
{

}

template <typename T>
Stack<T>::Stack(const Stack<T>& s)
: maximum_size(s.maximum_size), base(new T[s.maximum_size]) // default
{
  if(s.current_size>-1)
  {
    try {
      for(current_size=0; current_size<=s.current_size; current_size++) {
        base[current_size]=s.base[current_size]; // assignment
      }
    } catch (...) {
      current_size = 0;
      delete [] base;
      throw;
    }
    current_size--;
  }
}

template <typename T>
Stack<T>::~Stack()
{
  delete [] base;
}

template <typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& s)
{
  T* temp = new T[s.maximum_size]; // default exception allocate mem
  if(s.current_size>-1)
  {
    try {
      for(int x=0; x<=s.current_size; x++)
        temp[x]=s.base[x]; // assignment exception
    } catch (...) {
      delete temp;
      throw;
    }
  }

  delete [] base;
  base = temp;
  this->maximum_size = s.maximum_size;
  this->current_size = s.current_size;
  return *this;
}

template <typename T>
void Stack<T>::push(const T& element) // copy ctor
{
  if((unsigned)this->current_size==maximum_size-1)
  { 
    T* new_buffer = new T[maximum_size+chunk_size]; // default allocated memory
    try {
      for(int x=0; x<current_size; x++)
        new_buffer[x]=base[x]; // assignment
    } catch (...) {
      delete new_buffer;
      throw;
    }
    delete [] base;
    base=new_buffer; // pointer of generic type
    maximum_size+=chunk_size;
  }
  base[this->current_size+1]=element; // assignment
  this->current_size++;
}

template <typename T>
T& Stack<T>::pop()
{
  if (current_size < 0)
    throw "Empty";
  return base[current_size--]; // copy ctor if not reference
}

template <typename T>
int Stack<T>::size() const
{
  return current_size+1; // not changing stack
}

#endif