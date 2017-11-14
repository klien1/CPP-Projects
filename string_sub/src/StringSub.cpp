#include "StringSub.h"

StringSub::StringSub(const string& file) : bf(file) { }

void StringSub::replace(const string& oldstring, const string& newstring) {
  char c;
  const char* tc = oldstring.c_str();

  while(bf.get(c)) {
    // if match is found // call replace function
    if (c == *tc) {
      ++tc;
      if (tc-oldstring.c_str() == (int)oldstring.size()) {
        // match a newstring.size() different depending on oldstring and new
        if (oldstring.size() >= newstring.size()) {
          for (unsigned int i = 0; i < newstring.size(); ++i) 
            bf.put(newstring[i]);
        } else {
          for (unsigned int i = 0; i < tc-oldstring.c_str(); ++i) {
            td.push_back(newstring[i]);
            bf.put(td.front());
            td.pop_front();
          }
          for (unsigned int i = tc-oldstring.c_str(); i < newstring.size(); ++i) 
            td.push_back(newstring[i]);
        }
        tc = oldstring.c_str();
      }
    }
    else {
      if (tc-oldstring.c_str() > 0) {
        const char *j = oldstring.c_str();
        bf.put(oldstring[0]);
        for (unsigned int i = 1; i < tc-oldstring.c_str(); ++i) {
          if (oldstring[i] == *j) {
            j++;
          } else {
            // if during recalc match ends
            if (j-oldstring.c_str() > 0) {
              for (unsigned int k = 0; k < j-oldstring.c_str(); ++k)
                bf.put(oldstring[k]);
            }
            bf.put(oldstring[i]);
            j = oldstring.c_str();
          }
        }
        if (c == *j) j++;
        else j = oldstring.c_str();
        tc = j;
      }
      // temp char that hold cur character or characer in deque
      char temp_char = c;
      if (!td.empty()) {
        temp_char = td.front();
        td.pop_front();
        td.push_back(c);
      }
      // if there is a match from recalculating, dont put
      if (*tc == *oldstring.c_str())
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