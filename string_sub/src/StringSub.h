#ifndef STRINGSUB_H
#define STRINGSUB_H

#include "BufferedFile.h"

using std::cout;
using std::endl;

class StringSub {
  public:
    StringSub(const string&);
    void replace(const string&, const string&);

  private:
    BufferedFile bf;
    // unsigned int match;
    TrackingDeque<char> td;
};

#endif