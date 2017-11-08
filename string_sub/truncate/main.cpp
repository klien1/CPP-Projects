#include <unistd.h> // truncate
#include <sys/types.h> // truncate
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
  char c;
  int count = 0;
  string a = "test.txt";
  fstream fs(a, ios::in|ios::out);
  while(fs.get(c)) {
    cout << c << endl;
    count++;
  }

  truncate(a.c_str(), count-1);
  return 0;
}
