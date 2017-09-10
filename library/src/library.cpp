// File: library.cpp

// #include <iostream>
// #include <vector>
#include <fstream>

#include "library.h"

// using namespace std;

Library::Library() {
  std::ifstream inFile;

  inFile.open("book.txt");

  if (!inFile) {
    std::cerr << "unable to open book.txt" << std::endl;
  }

  std::string cn;
  std::string title;
  std::string subj;
  std::string auth;
  std::string desc;
  std::string pub;
  std::string city;
  std::string year;
  std::string series;
  std::string notes;

  // while(!getline(inFile, cn, '|').eof()) {
  while(getline(inFile, cn, '|')) {
    getline(inFile, title, '|');
    getline(inFile, subj, '|');
    getline(inFile, auth, '|');
    getline(inFile, desc, '|');
    getline(inFile, pub, '|');
    getline(inFile, city, '|');
    getline(inFile, year, '|');
    getline(inFile, series, '|');
    getline(inFile, notes, '\n');
    this->media.push_back(new Book(cn, title, subj, auth, desc, pub, city, year, series, notes));
  }

  inFile.close();

  for (const Media* m_obj : media) {
    m_obj->getName();
  }
}

Library::~Library() {
  for (const Media* media_obj : media) {
    delete media_obj;
  }
}

// int main() {


  // for (const Media* m_obj : media) {
  //   m_obj->getName();
  // }


  // for (unsigned int i = 0; i < media.size(); ++i) {
    // cout << media[i]->getName();
  // }
  // Book *b = new Book("1", "2", "3", "4", "5", "6", "7", "8", "9", "10");
  // b->getName()
  // Film *f = new Film();

  // Media *media_array[2] = {b, f};
  // media_array[1]->getName();
  // media_array[0]->getName();
  // media_array[1]->get_num();
  // cout << media_array[1]->get_num() << endl;
  // cout << media_array[0]->get_num() << endl;

  // virtual objects needs virtual destructor
  // media_array[0]/;
  // cout << media_array[0].get_num() << endl;
  // cout << b.get_num() << endl;
// }