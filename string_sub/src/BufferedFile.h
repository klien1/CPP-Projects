
#ifndef BUFFERED_FILE_H
#define BUFFERED_FILE_H

#include <fstream>
#include <string>
#include "TrackingDeque.h"

#include <unistd.h> // truncate
#include <sys/types.h> // truncate

using std::string;
using std::fstream;
using std::istream;
using std::ostream;

class BufferedFile : public fstream {
  public:
    BufferedFile(const string&);
    ~BufferedFile();
    istream& get(char&);
    ostream& put(char);

  private:
    std::streampos getpos;
    std::streampos putpos;
    const string file;
    int num_char;
    // TrackingDeque<char> t_deq;
};

#endif