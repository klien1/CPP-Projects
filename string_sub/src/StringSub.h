#ifndef STRINGSUB_H
#define STRINGSUB_H

#include "BufferedFile.h"

class StringSub {
  public:
    StringSub(const string&, const string&, const string&);
    StringSub& get(char& c);
    StringSub& put(char c);
    bool eof() const;
    bool replacing() const;
    void full_match();
    void part_match(int, char);
  private:
    BufferedFile bf;
    const string srch;
    const string repl;
    int repl_count;
    int srch_count;
    int num_match;
    bool use_repl;
    int srch_offset;
};

#endif
