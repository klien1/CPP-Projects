#ifndef STRINGSUB_H
#define STRINGSUB_H

#include "BufferedFile.h"
#include <cstring>

class StringSub {
  public:
    StringSub(const char*);
    void replace(const char*, const char*);

  private:
    BufferedFile bf;
    TrackingDeque<char> td;
};

#endif