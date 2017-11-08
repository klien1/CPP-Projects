#include <iostream>
using namespace std;

#include "TrackingDeque.h"

int main() {
  TrackingDeque<char> mybuffer;
  mybuffer.push_front('A');
  mybuffer.push_back('B');
  cout << "Front of deque is: " << mybuffer.front() << endl;
  TrackingDeque<char> test(mybuffer);
  mybuffer.pop_front();
  cout << "Front of deque is: " << mybuffer.front() << endl;
  mybuffer.pop_front();
  test.push_front('C');

  while(!test.empty()) {
    cout << "Back of test deque is: " << test.back() << endl;
    test.pop_back();
  }
  return 0;
}
