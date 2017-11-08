// File: TrackingDeque.h
// Author: Kevin Lien

#ifndef TRACKINGDEQUE_H
#define TRACKINGDEQUE_H

#include <deque>
#include <iostream>

using std::deque;

template <typename T>
class TrackingDeque : public deque<T> {
  public:
    TrackingDeque();
    ~TrackingDeque();
    void push_front(const T&);
    void push_front(T&&); // c++11 implementation
    void push_back(const T&);
    void push_back(T&&); // c++11 implementation
  private:
    unsigned int max_size;
};

template <typename T>
TrackingDeque<T>::TrackingDeque() : max_size(0) { }

template <typename T>
TrackingDeque<T>::~TrackingDeque() {
  std::cout << "---> " << max_size << " <---" << std::endl;
}

template <typename T>
void TrackingDeque<T>::push_front(const T& val) {
  try {
    deque<T>::push_front(val);
    if (max_size < deque<T>::size()) max_size = deque<T>::size();
  } catch(...) { }
}

// part of c++11 implementation of deque
template <typename T>
void TrackingDeque<T>::push_front(T&& val) {
  try {
    deque<T>::push_front(val);
    if (max_size < deque<T>::size()) max_size = deque<T>::size();
  } catch(...) { }
}

template <typename T>
void TrackingDeque<T>::push_back(const T& val) {
  try {
    deque<T>::push_back(val);
    if (max_size < deque<T>::size()) max_size = deque<T>::size();
  } catch(...) { }
}

// part of c++11 implementation of deque
template <typename T>
void TrackingDeque<T>::push_back(T&& val) {
  try {
    deque<T>::push_back(val);
    if (max_size < deque<T>::size()) max_size = deque<T>::size();
  } catch(...) { }
}

#endif