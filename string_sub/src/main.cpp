#include "StringSub.h"

using namespace std;

// 1: old
// 2: new
// 3: file
int main(int argc, char const *argv[]) {
  if (argc != 4) {
    cout << "Invalid number of arguments.\n";
    return 1;
  }

  StringSub ss(argv[3], argv[1], argv[2]);
  const string srch = argv[1];
  const string repl = argv[2];
  unsigned int num_match = 0;
  char c;

  // get character while there are still characters to get
  while(!ss.get(c).eof()) {
    // if not reading from replace string and character matches
    if (!ss.replacing() && c == srch[num_match]) {
      ++num_match;
      if (num_match < srch.size())
        continue;
    }
    if (num_match == srch.size())
      ss.full_match();
    else if (num_match > 0)
      ss.part_match(num_match, c);
    else
      ss.put(c);
    num_match = 0;
  }
  return 0;
}
