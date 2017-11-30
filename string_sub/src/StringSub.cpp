#include "StringSub.h"

using std::cout;
using std::endl;

StringSub::StringSub(
  const string& file, 
  const string& srch, 
  const string& repl) 
  : bf(file), 
    srch(srch), 
    repl(repl),
    repl_count(0),
    srch_count(0),
    num_match(0),
    use_repl(false)
    {}

StringSub& StringSub::get(char& c) {
  if (srch_count > 0) {
    c = srch[num_match-srch_count];
    --srch_count;
    //cout << "get " << c << " from srch" << endl;
  }
  else if(repl_count > 0) {
    c = repl[repl.size()-repl_count];
    --repl_count;
    //if (repl_count == 0)
    //  use_repl = false;
    //cout << "get " << c << " from repl" << endl;
  }
  else if(!this->eof()) {
    ////cout << "get from file" << endl;
    bf.get(c);
  }
  return *this;
}

StringSub& StringSub::put(char c) {
  if (repl_count < 1) use_repl = false;
  bf.put(c);
  return *this;
}

bool StringSub::eof() const {
  return bf.eof();
}

bool StringSub::replacing() const {
  /*
  if (repl_count > 0)
    return true;
  return false;
  */
  return use_repl;
}

void StringSub::full_match() {
  repl_count = repl.size();
  use_repl = true;
}

void StringSub::part_match(int part_match, char c) {
  /*
  a
  ...aa...
  ...a
       ^
      ^
  a
  aa
  ^
  char_deque.push_front(srch[0]);
  bf.put(char_deque.front());
  char_deque.pop_front();
  */
  bf.put(srch[0]);
  //std:://cout << srch[0];
  num_match = part_match;
  srch_count = part_match - 1;
  repl_count = 0;
  //srch_count = repl_count;
  bf.do_over(c);
}
