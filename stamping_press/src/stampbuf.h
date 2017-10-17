// Author: Kevin Lien
// File: stampbuf.h

#ifndef STAMPBUF_H
#define STAMPBUF_H

#include <streambuf>
#include "stampstream.h"
#include "stamp.h"

std::ostream& endrow(std::ostream&);
class stampbuf : public std::streambuf {
  friend std::ostream& endrow(std::ostream&);

  public:
    stampbuf(const int&, const int&);
    ~stampbuf();
    void change_cur_row(const int&);

  protected:
    int overflow(int);
    int sync();
    void next_row();

  private:
    int max_col;
    int max_row;
    int cur_col;
    int cur_row;
    int buf_size;
    char* buffer;
};

#endif