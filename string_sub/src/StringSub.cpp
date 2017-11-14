#include "StringSub.h"

StringSub::StringSub(const string& file) : bf(file) { }

void StringSub::replace(const string& oldstring, const string& newstring) {
  char c;
  unsigned int match = 0;
  while(bf.get(c)) {
    // if match is found // call replace function
    if (c == oldstring[match]) {
      ++match;
      if (match == oldstring.size()) {
        // match a newstring.size() different depending on oldstring and new
        if (oldstring.size() >= newstring.size()) {
          for (unsigned int i = 0; i < newstring.size(); ++i) 
            bf.put(newstring[i]);
        } else {
          for (unsigned int i = 0; i < match; ++i) {
            td.push_back(newstring[i]);
            bf.put(td.front());
            td.pop_front();
          }
          for (unsigned int i = match; i < newstring.size(); ++i) 
            td.push_back(newstring[i]);
        }
          match = 0;
      }
    }
    else {
      if (match > 0) {
        unsigned int j = 0;
        bf.put(oldstring[0]);
        for (unsigned int i = 1; i < match; ++i) {
          if (oldstring[i] == oldstring[j]) {
            j++;
          } else {
            // if during recalc match ends
            if (j > 0) {
              for (unsigned int k = 0; k < j; ++k)
                bf.put(oldstring[k]);
            }
            bf.put(oldstring[i]);
            j = 0;
          }
        }
        if (c == oldstring[j]) j++;
        else j = 0;
        match = j;
      }
      // temp char that hold cur character or characer in deque
      char temp_char = c;
      if (!td.empty()) {
        temp_char = td.front();
        td.pop_front();
        td.push_back(c);
      }
      // if there is a match from recalculating, dont put
      if (match == 0)
        bf.put(temp_char);
    }
  }

  while(!td.empty()) {
    if (!bf.good())
      bf.clear();
    bf.put(td.front());
    td.pop_front();
  }

  if (!bf.good()) bf.clear();
}