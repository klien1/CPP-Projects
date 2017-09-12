// File: main.cpp
// Author: Kevin Lien

#include <iostream>

#include "library.h"

using namespace std;

int main() {
  Library lib;
  string pattern;
  cout << "enter a pattern for call number: ";
  cin >> pattern;
  cout << "All results:\n";
  vector<Media*> found = lib.search_cn(pattern);
  for (const auto& media : found) {
    media->printMedia();
  }
  cout << "You have found " << found.size() << " results.\n";
  return 0;
}