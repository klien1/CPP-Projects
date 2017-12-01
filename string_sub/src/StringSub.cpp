#include "StringSub.h"

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
    use_repl(false),
    srch_offset(0) {}

StringSub& StringSub::get(char& c) {
  // if search count exists, use search string
  if (srch_count > 0) {
    c = srch[num_match-srch_count];
    // reset starting offset to 0 when done reading search string
    --srch_count;
    if (srch_count == 0)
      srch_offset = 0;
  }
  // else if use replace string if replace count exists
  else if(repl_count > 0) {
    c = repl[repl.size()-repl_count];
    --repl_count;
  }
  // else get a character if not end of file in buffered file
  else if(!bf.eof()) {
    bf.get(c);
  }
  return *this;
}

StringSub& StringSub::put(char c) {
  // set use replace string here to prevent reading replaced characters
  if (repl_count < 1) 
    use_repl = false;
  bf.put(c);
  return *this;
}

bool StringSub::eof() const {
  return bf.eof();
}

bool StringSub::replacing() const {
  return use_repl;
}

void StringSub::full_match() {
  repl_count = repl.size();
  use_repl = true;
}

// partial match found in srch string
void StringSub::part_match(int part_match, char c) {
  if (srch_count == 0) {
    num_match = part_match;
    bf.do_over(c); // push unmatched letter to front of deque
  }
  /*
     Search offset is starting position of index if partial match
     is found in a partial match.
  */
  bf.put(srch[srch_offset]); // put first char to prevent inf loops
  // set start pos of srch string
  srch_count = num_match - 1 - srch_offset;
  ++srch_offset;
}
