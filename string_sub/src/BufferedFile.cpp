#include "BufferedFile.h"
using std::cout; 
using std::endl; 
BufferedFile::BufferedFile(const string& file_name) 
  : std::fstream(file_name, ios::in|ios::out), 
    getpos(0), 
    putpos(0), 
    file(file_name), 
    num_char(0),
    stop_reading(false)
    {}

BufferedFile::~BufferedFile() {
  //cout << "destructor\n";
  //print_deque();
  /*
  while(!char_deque.empty()) {
    char c = char_deque.front();
    this->put(c);
    char_deque.pop_front();
  }
  */
  truncate(file.c_str(), num_char);
  this->close();
}

BufferedFile& BufferedFile::get(char& c) {
  //print_deque();
  if (!char_deque.empty()) {
    c = char_deque.front();
    char_deque.pop_front();
    //cout << "  " << c << " from deque\n";
  }
  else {
    get_char_from_file(c);
    //cout << "  " << c << " from file\n";
  }
  return *this;
}

BufferedFile& BufferedFile::put(char c) {
  // if trying to put on a char before reading it
  if (getpos == putpos && !stop_reading) {
    char temp_c;
    get_char_from_file(temp_c);
    //if (good())
      char_deque.push_back(temp_c);
  }

  //cout << "getpos: " << getpos << " putpos: " << putpos << " putting " << c << endl;
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
  if (!good())
    stop_reading = true;
}

bool BufferedFile::eof() const {
  if (stop_reading && char_deque.empty())
    return true;
  else
    return fstream::eof();
}

// REMOVE
void BufferedFile::print_deque() {
  int size = char_deque.size();
  cout << "  deque has: ";
  for (int i = 0; i < size; ++i) {
    cout << char_deque.front() << " ";
    char_deque.push_back(char_deque.front());
    char_deque.pop_front();
  }
  cout << endl;
}
