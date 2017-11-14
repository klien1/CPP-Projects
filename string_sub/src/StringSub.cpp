#include "StringSub.h"

StringSub::StringSub(const char* file) : bf(file) { }
void StringSub::replace(const char* oldstring, const char* newstring) {
  char c;
  const char* tc = oldstring;

  while(bf.get(c)) {
    // if match is found // call replace function
    if (c == *tc) {
      ++tc;
      if (tc-oldstring == (int)strlen(oldstring)) {
        // match a newstring.size() different depending on oldstring and new
        if (strlen(oldstring) >= strlen(newstring)) {
          for (unsigned int i = 0; i < strlen(newstring); ++i) 
            bf.put(newstring[i]);
        } else {
          for (unsigned int i = 0; i < tc-oldstring; ++i) {
            td.push_back(newstring[i]);
            bf.put(td.front());
            td.pop_front();
          }
          for (unsigned int i = tc-oldstring; i < strlen(newstring); ++i) 
            td.push_back(newstring[i]);
        }
        tc = oldstring;
      }
    }
    else {
      if (tc-oldstring > 0) {
        const char *j = oldstring;
        bf.put(oldstring[0]);
        for (unsigned int i = 1; i < tc-oldstring; ++i) {
          if (oldstring[i] == *j) {
            j++;
          } else {
            // if during recalc match ends
            if (j-oldstring > 0) {
              for (unsigned int k = 0; k < j-oldstring; ++k)
                bf.put(oldstring[k]);
            }
            bf.put(oldstring[i]);
            j = oldstring;
          }
        }
        if (c == *j) j++;
        else j = oldstring;
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
      if (*tc == *oldstring)
        bf.put(temp_char);
    }
  }

  while(!td.empty()) {
    if (!bf.good())
      bf.clear();
    bf.put(td.front());
    td.pop_front();
  }
}