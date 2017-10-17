// Author: Kevin Lien
// File: stampstream.cpp

#include "stampstream.h"

stampstream::stampstream(const int& row, const int& col) 
  : std::ostream(new stampbuf(row, col)) {}

stampstream::~stampstream() {
  // frees new stampbuf
  delete rdbuf(); 
}