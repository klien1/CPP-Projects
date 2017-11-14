
#ifndef BUFFERED_FILE_H
#define BUFFERED_FILE_H

#include <fstream>
#include <string>
#include <cassert>
#include "TrackingDeque.h"

#include <unistd.h> // truncate
#include <sys/types.h> // truncate

using std::string;
using std::fstream;
using std::istream;
using std::ostream;
using std::streampos;

class BufferedFile : public fstream {
  public:
    BufferedFile(const string&);
    ~BufferedFile();
    istream& get(char&);
    ostream& put(char);
    istream& seekg (streampos);
    ostream& seekp (streampos);

  private:
    streampos getpos;
    streampos putpos;
    const string file;
    int num_char;
};

#endif