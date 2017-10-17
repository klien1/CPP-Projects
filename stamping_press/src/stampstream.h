// Author: Kevin Lien
// File: stampstream.h

#ifndef STAMPSTREAM_H
#define STAMPSTREAM_H

#include <ostream>
#include "row.h"
#include "stampbuf.h"

class stampstream : public std::ostream {
  public:
    stampstream(const int&, const int&);
    ~stampstream();
};

#endif