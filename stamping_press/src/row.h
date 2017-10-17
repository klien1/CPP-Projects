// Author: Kevin Lien
// File: row.h

#ifndef ROW_H
#define ROW_H

#include <ostream>
#include "stampstream.h"

class row {
  friend std::ostream& operator<<(std::ostream&, const row&);

  public:
    row(const int&);
    int get_row() const;

  private:
    int row_num;
};

#endif