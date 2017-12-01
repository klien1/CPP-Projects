#include "BufferedFile.h"

BufferedFile::BufferedFile(const string& file_name) 
  : std::fstream(file_name, ios::in|ios::out), 
    getpos(0), 
    putpos(0), 
    file(file_name), 
    num_char(0),
    stop_reading(false) {}

BufferedFile::~BufferedFile() {
  truncate(file.c_str(), num_char);
  this->close();
}

BufferedFile& BufferedFile::get(char& c) {
  if (!char_deque.empty()) {
    c = char_deque.front();
    char_deque.pop_front();
  }
  else 
    get_char_from_file(c);
  
  return *this;
}

BufferedFile& BufferedFile::put(char c) {
  // if trying to put on a char before reading it
  if (getpos == putpos && !stop_reading) {
    char temp_c;
    get_char_from_file(temp_c);
    char_deque.push_back(temp_c);
  }

  // if trying to put character after end of file
  if (!good()) 
    this->clear();
  
  seekp(putpos);
  fstream::put(c);
  putpos = tellp();
  ++num_char;
  return *this;
}

BufferedFile& BufferedFile::seekp (streampos pos) {
  assert(pos >= putpos);
  fstream::seekp(pos);
  return *this;
}

BufferedFile& BufferedFile::seekg (streampos pos) {
  assert(pos >= getpos);
  fstream::seekg(pos);
  return *this;
}

void BufferedFile::do_over(char c) {
  char_deque.push_front(c);
}

void BufferedFile::get_char_from_file(char& c) {
  seekg(getpos);
  fstream::get(c);
  getpos = tellg();
  // stop_reading prevents gets after eof is reached
  if (!good())
    stop_reading = true;
}

bool BufferedFile::eof() const {
  if (stop_reading && char_deque.empty())
    return true;
  else
    return fstream::eof();
}
