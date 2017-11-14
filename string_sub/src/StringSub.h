#ifndef STRINGSUB_H
#define STRINGSUB_H

#include "BufferedFile.h"

class StringSub {
  public:
    StringSub(const string&);
    void replace(const string&, const string&);

  private:
    BufferedFile bf;
    TrackingDeque<char> td;
};

#endif