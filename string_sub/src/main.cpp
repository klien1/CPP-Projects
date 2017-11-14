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
    return 1;
  }

  StringSub ss(argv[3]);
  ss.replace(argv[1], argv[2]);
  return 0;
}
