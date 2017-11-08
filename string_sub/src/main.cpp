#include <iostream>
#include "StringSub.h"

// #include <unistd.h> // truncate
// #include <sys/types.h> // truncate
using namespace std;

// 1: old
// 2: new
// 3: file
int main(int argc, char const *argv[]) {
  if (argc != 4) {
    cout << "Invalid number of arguments.\n";
  }

  // const string t = argv[3];
  // string t = argv[3];
  StringSub ss(argv[3]);
  ss.replace(argv[1], argv[2]);
  // truncate(t, 5);
  // StringSub ss("test.txt");
  // StringSub ss("../string_substitution/string_sub_testing_suite/origfiles/File01.txt");
  return 0;
}
