#include "BufferedFile.h"

BufferedFile::BufferedFile(const string& file_name) 
  : std::fstream(file_name, fstream::in|fstream::out), getpos(0), putpos(0), 
    file(file_name), num_char(0) {}

BufferedFile::~BufferedFile() {
  truncate(file.c_str(), num_char);
  this->close();
}

istream& BufferedFile::get(char& c) {
  seekg(getpos);
  fstream::get(c);
  getpos = tellg();
  return *this;
}

ostream& BufferedFile::put(char c) {
  seekp(putpos);
  fstream::put(c);
  putpos = tellp();
  ++num_char;
  return *this;
}

ostream& BufferedFile::seekp (streampos pos) {
  assert(pos >= putpos);
  fstream::seekp(pos);
  return *this;
}

istream& BufferedFile::seekg (streampos pos) {
  assert(pos >= getpos);
  fstream::seekg(pos);
  return *this;
}