// File: main.cpp
// Author: Kevin Lien

#include <iostream>

#include "library.h"

using namespace std;

int main() {
  Library lib;
  string option, pattern;

  do {
    cout << "1. Search by call number." << endl;
    cout << "2. Search by title." << endl;
    cout << "3. Search by subject." << endl;
    cout << "4. Search by other." << endl;
    cout << "5. Exit" << endl;

    cout << "Choose an option (number): ";
    getline(cin, option);
    cout << "Enter search (case sensitive): ";
    if (option == "1") {
      getline(cin, pattern);
      const vector<const Media*> found = lib.search_cn(pattern);

      for (const Media* media : found) {
        media->print();
      }
    }
    else if (option == "2") {
      getline(cin, pattern);
      const vector<const Media*> found = lib.search_ti(pattern);

      for (const Media* media : found) {
        media->print();
      }
    }
    else if (option == "3") {
      getline(cin, pattern);
      const vector<const Media*> found = lib.search_su(pattern);

      for (const Media* media : found) {
        media->print();
      }
    }
    else if (option == "4") {
      getline(cin, pattern);
      const vector<const Media*> found = lib.search_ot(pattern);

      for (const Media* media : found) {
        media->print();
      }
    }
    else {
      cout << "Invalid option. Choose a number between 1-4." << endl << endl;
    }
  } while (!(option == "5" || option == "4" || option == "3" || option == "2" || option == "1"));

  return 0;
}