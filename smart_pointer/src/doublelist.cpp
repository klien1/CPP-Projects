//Source: https://www.tutorialspoint.com/data_structures_algorithms/doubly_linked_list_program_in_c.htm
//Enhanced test code and corrected logic bug in insertLast on empty list.

// Kevin Lien
// Smart pointers
#include <cstdio>
#include <cstdlib>
#include <memory>

using namespace std;

struct node {
  int data;
  int key;

  shared_ptr<node> next;
  weak_ptr<node> prev;
};

//this link always point to first Link 
shared_ptr<node> head = nullptr;

//this link always point to last Link 
shared_ptr<node> last = nullptr;
shared_ptr<node> current = nullptr;

//is list empty
bool isEmpty(){
  return head == nullptr;
}

int length(){
  int length = 0;
  shared_ptr<node> current;

  for(current = head; current != nullptr; current = current->next){
    length++;
  }

  return length;
}

//display the list in from first to last
void displayForward(){

  //start from the beginning
  shared_ptr<node> ptr = head;

  //navigate till the end of the list
  printf("\n[ ");

  while(ptr != nullptr){        
    printf("(%d,%d) ", ptr->key, ptr->data);
    ptr = ptr->next;
  }

  printf(" ]");
}

//display the list from last to first
void displayBackward(){

  //start from the last
  shared_ptr<node> ptr = last;

  //navigate till the start of the list
  printf("\n[ ");

  while(ptr != nullptr){    

    //print data
    printf("(%d,%d) ", ptr->key, ptr->data);

    //move to next item
    ptr = ptr->prev.lock();
    printf(" ");
  }

  printf(" ]");
}


//insert link at the first location
void insertFirst(int key, int data){

  //create a link
  shared_ptr<node> link = make_shared<node>();
  link->key = key;
  link->data = data;

  if(isEmpty()){
    //make it the last link
    last = link;
  }else {
    //update first prev link
    head->prev = link;
  }

  //point it to old first link
  link->next = head;

  //point first to new first link
  head = link;
}

//insert link at the last location
void insertLast(int key, int data){

  //create a link
  shared_ptr<node> link = make_shared<node>();
  link->key = key;
  link->data = data;

  if(isEmpty()){
    //make it the last link
    head = link;
  }else {
    //make link a new last link
    last->next = link;     
    //mark old last node as prev of new link
    link->prev = last;
  }

  //point last to new last node
  last = link;
}

//delete first item
shared_ptr<node> deleteFirst(){

  //save reference to first link
  shared_ptr<node> tempLink = head;

  //if only one link
  if(head->next == nullptr){
    last.reset();
  } else {
    head->next->prev.reset();
  }

  head = head->next;
  //return the deleted link
  return tempLink;
}

//delete link at the last location

shared_ptr<node> deleteLast(){
  //save reference to last link
  shared_ptr<node> tempLink = last;

  //if only one link
  if(head->next == nullptr){
    head.reset();
  }else {
    last->prev.lock()->next.reset();
  }

  last = last->prev.lock();

  //return the deleted link
  return tempLink;
}

//delete a link with given key

shared_ptr<node> deleteLink(int key){

  //start from the first link
  shared_ptr<node> current = head;
  shared_ptr<node> previous = nullptr;

  //if list is empty
  if(head == nullptr){
    return nullptr;
  }

  //navigate through list
  while(current->key != key){
    //if it is last node

    if(current->next == nullptr){
      return nullptr;
    }else {
      //store reference to current link
      previous = current;

      //move to next link
      current = current->next;             
    }
  }

  //found a match, update the link
  if(current == head) {
    //change first to point to next link
    head = head->next;
  }else {
    //bypass the current link
    current->prev.lock()->next = current->next;
  }    

  if(current == last){
    //change last to point to prev link
    last = current->prev.lock();
  }else {
    current->next->prev.lock() = current->prev.lock();
  }

  return current;
}

bool insertAfter(int key, int newKey, int data){
  //start from the first link
  shared_ptr<node> current = head; 

  //if list is empty
  if(head == nullptr){
    return false;
  }

  //navigate through list
  while(current->key != key){

    //if it is last node
    if(current->next == nullptr){
      return false;
    }else {           
      //move to next link
      current = current->next;             
    }
  }

  //create a link
  shared_ptr<node> newLink = make_shared<node>();
  newLink->key = newKey;
  newLink->data = data;

  if(current == last) {
    newLink->next.reset(); 
    last = newLink; 
  }else {
    newLink->next = current->next;         
    current->next->prev = newLink;
  }

  newLink->prev = current; 
  current->next = newLink; 
  return true; 
}

int main() 
{

  printf("initial length=%d\n", length());
  insertLast(0,-10);
  insertFirst(1,10);
  insertFirst(2,20);
  insertFirst(3,30);
  insertFirst(4,1);
  insertFirst(5,40);
  insertFirst(6,56); 
  insertFirst(7,50); 
  printf("subsequent length=%d\n", length());

  printf("\nList (First to Last): ");  
  displayForward();

  printf("\n");
  printf("\nList (Last to first): "); 
  displayBackward();

  printf("\nList , after deleting first record: ");
  deleteFirst();        
  displayForward();

  printf("\nList , after deleting last record: ");  
  deleteLast();
  displayForward();

  printf("\nList , insert after key(4) : ");  
  insertAfter(4,7, 13);
  displayForward();

  printf("\nList  , after delete key(4) : ");  
  deleteLink(4);
  displayForward();
  printf("\n");
}
