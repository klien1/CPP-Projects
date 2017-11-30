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
using std::ios;

class BufferedFile : public fstream {
  public:
    BufferedFile(const string&);
    ~BufferedFile();
    BufferedFile& get(char&);
    BufferedFile& put(char);
    BufferedFile& seekg (streampos);
    BufferedFile& seekp (streampos);
    void do_over(char);
    bool eof() const;

  private:
    streampos getpos;
    streampos putpos;
    const string file;
    int num_char;
    TrackingDeque<char> char_deque;
    bool stop_reading;

    void get_char_from_file(char&);

    void print_deque() ;
};

#endif
