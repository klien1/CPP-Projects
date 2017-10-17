// Author: Kevin Lien
// File: stampbuf.cpp

#include "stampbuf.h"

stampbuf::stampbuf(const int& col, const int& row) 
    : max_col(col), max_row(row), cur_col(0), cur_row(0), 
      buf_size(max_col/3), buffer(new char[buf_size]) {

  setp(buffer, buffer+buf_size-1);
  stamping_press::insert_plate(max_col, max_row);
}

stampbuf::~stampbuf() {
  sync();
  stamping_press::eject_plate();
  delete [] buffer;
}

std::ostream& endrow(std::ostream& os) {
  // dynamic cast stampbuf because streambuf doesn't have stampbuf's function
  stampbuf* sbp = dynamic_cast<stampbuf*>(os.rdbuf());
  if (sbp) {
    os.flush();
    sbp->next_row();
  }
  return os;
}

// syncs the buffer and adds the extra character back to buffer
int stampbuf::overflow(int c) {
  if (sync()) {
    sputc(c);
    return 1;
  }
  return 0;
}

int stampbuf::sync() {
  if (!buffer || !pptr() || !pbase() || !epptr()) return 0;

  // prints everything in buffer until it reaches the current pptr
  for (int i = 0; buffer+i != pptr(); ++i) {
    try {
      // doesn't call set_die if current die is already set
      if (stamping_press::get_die() != buffer[i]) {
        stamping_press::set_die(buffer[i]);
      }
      stamping_press::stamp(cur_col, cur_row);
    } catch(...) {} // do nothing
    ++cur_col;    
  }
  // reset buffer pointers
  setp(pbase(), epptr());
  return 1;
}

// change the row and set col to 0
void stampbuf::change_cur_row(const int& row) {
  cur_row = row;
  cur_col = 0;
}

// increment to next row and set col to 0
void stampbuf::next_row() {
  ++cur_row;
  cur_col = 0;
}