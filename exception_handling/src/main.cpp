#include "orig_stack.h"
#include "Nausea.h"
#include <iostream>
#include <stdexcept>
using namespace std;

void f(Nausea n, Stack<Nausea> s) {
  cout << endl;
  s.push(n);
  s.push(n);
  s.push(n);
  s.push(n);
  Stack<Nausea> t(s);
  t.pop();
  s.pop();
  // cout << endl;
  // return n;
  // return n;
}

int main() {
  // Nausea::type=Nausea::default_ctor;
  Nausea::type=Nausea::copy_ctor;
  // Nausea::type=Nausea::assignment_op;
  // Nausea::trigger=22; // iteration where it gets triggered
  // Nausea::trigger=22; // iteration where it gets triggered
  Nausea::trigger=4; // iteration where it gets triggered
  Nausea n;
  cout << endl;

  // Stack<Nausea>
  Stack<Nausea> s;
  cout << endl;
  // f(n, s);
  s.push(n);
  s.push(n);
  s.push(n);
  s.push(n);
  cout << endl;
  s.status();
  cout << s.size() << endl;

  s.pop();
  s.status();














  // Stack<Nausea> s; cout << endl;
  // s.push(n);
  // s.push(n);
  // s.push(n);
  // s.push(n);
  // s.push(n);

  // cout << endl;
  // s.status();
  // cout << &s.pop() << endl;
  // s.status();
  // try {
  // cout << &s.pop() << endl;
    // s.pop();
  // } catch (exception& e) {
    // cout << e.what() << endl;
    // s.status();
  // }
  // cout << &s.pop() << endl;
  // s.pop();
  // cout << endl;
  // s.status();
  // try {
  //   Stack<Nausea> t(s);
  // } catch (exception& e) {
  //   cout << e.what() << endl;
  // }
  // t.status();
  // cout << endl;
  // Nausea n2 = f(n);
  // cout << endl;





















  // Stack<Nausea> s, t;
  // s.push(n);
  // s.push(n);
  // s.push(n);
  // s.push(n);
  // s.push(n);
  // s.push(n);
  // s.push(n);
  // s.push(n);
  // s.push(n);
  // s.push(n);
  // s.push(n);
  // s.status();
  // try {
  //   Stack<Nausea> t(s);
  // } catch (exception& e) {
  //   cout << e.what() << endl;
  // }







  // Stack<Nausea> s;
  // s.push(n); s.push(n);
  // s.push(n); s.push(n);
  // s.push(n); s.push(n);
  // s.push(n); s.push(n);
  // s.push(n); s.push(n);
  
  // cout << "b\n";
  // s.status();
  // try {
  //   s.push(n);

  // } catch (exception& e) {
  //   cout << e.what() << endl;
  //   cout << "a\n";
  //   s.status();
  // }









  // Stack<Nausea> t;
  // cout << endl;
  // try {
  //   f(t, n);
  // } catch (exception& e) {
  //   cout << e.what() << endl;
  //   // t.status();
  // }
  // t.pop();



// COPY CTOR
  // Stack<Nausea> s;
  // cout << endl;
  // s.push(n);
  // s.push(n);
  // s.push(n);
  // s.push(n);
  // cout << endl;
  // s.status();

    // Stack<Nausea> t(s);
    // t.status();
  // try {
  //   Stack<Nausea> t(s);
  // } catch (exception& e) {
  //   cout << e.what() << endl;
  // }
  // cout << endl;


// ASSIGNMENT
  // Stack<Nausea> s, t;
  // cout << endl;
  // try {
  //   Nausea n; cout << endl;
  //   s.push(n);
  //   s.push(n);
  //   s.push(n);
  //   s.push(n);
  //   s.push(n);
  //   s.push(n);

  // } catch (exception& e) {
  //   cout << endl;
  //   cout << e.what() << endl;
  // }

  // cout << "\ns status\n";
  // s.status();
  // cout << "\nt status\n";
  // t.status();
  // try {
  //   t = s;
  // } catch (exception& e) {
  //   cout << endl << e.what() << endl;
  //   cout << "\nt status exception\n";
  //   t.status();
  // }
  //   cout << "\nt status\n";
  //   t.status();


// KEEEP BELOW PUSH
  // s.status();
  // s.push(n); cout << endl;
  // s.push(n); cout << endl;
  // s.push(n); cout << endl;
  // cout << "before\n";
  // s.status();
  // try {
  //   s.push(n); cout << endl; // 4
  // } catch (std::exception& e) {
  //   cout << endl;
  //   cout << e.what() << endl;
  //   cout << "after\n";
  //   s.status();
  // } 
  // s.push(n); cout << endl;
  // s.push(n); cout << endl;
  // s.push(n); cout << endl;
  // s.push(n); cout << endl;
  // s.push(n); cout << endl; // 9
  // s.push(n); cout << endl; // 10
  // cout << "before\n";
  // s.status();
  // try {
  //   s.push(n); cout << endl; // 11 trigger 13-20
  // } catch (std::exception& e) {
  //   cout << endl;
  //   cout << e.what() << endl;
  //   cout << "after\n";
  //   s.status();
  // }
  // s.push(n); cout << endl; // 12 trigger 21
  // cout << "before\n";
  // s.status();
  // try {
  //   s.push(n); cout << endl; // 13 trigger 22
  // } catch(std::exception& e) {
  //   cout << endl;
  //   cout << e.what() << endl;
  //   cout << "after\n";
  //   s.status();
  // }
  // cout << "end status\n";
  // s.status();

  // Stack<Nausea> t;
  // cout << endl;
  // cout << "t status" << endl;
  // try {
  //   t = s;
  // } catch (std::exception& e) {
  //   cout << endl;
  //   cout << e.what() << endl;
  //   t.status();
  // }
}