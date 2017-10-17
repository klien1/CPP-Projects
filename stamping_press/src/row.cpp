// Author: Kevin Lien
// File: row.cpp

#include "row.h"

row::row(const int& row) : row_num(row) {}

int row::get_row() const {
  return row_num;
}

std::ostream& operator<<(std::ostream& os, const row& r) {
  stampbuf* sbp = dynamic_cast<stampbuf*>(os.rdbuf());
  os.flush();
  sbp->change_cur_row(r.get_row());
  return os;
}