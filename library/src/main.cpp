// File: main.cpp
// Author: Kevin Lien

#include <iostream>

#include "library.h"

using namespace std;

int main() {
  Library lib;
  string option;

  do {
    string pattern;

    cout << "1. Search by call number." << endl;
    cout << "2. Search by title." << endl;
    cout << "3. Search by subject." << endl;
    cout << "4. Search by other." << endl;
    cout << "5. Exit" << endl;

    getline(cin, option);
    cout << "Enter search: ";
    if (option == "1") {
      getline(cin, pattern);
      vector<Media*> found = lib.search_cn(pattern);

      for (const auto& media : found) {
        media->print();
      }
      cout << "You have found " << found.size() << " results by call number." << endl << endl;
    }
    else if (option == "2") {
      getline(cin, pattern);
      vector<Media*> found = lib.search_ti(pattern);

      for (const auto& media : found) {
        media->print();
      }
      cout << "You have found " << found.size() << " results by title." << endl << endl;
    }
    else if (option == "3") {
      getline(cin, pattern);
      vector<Media*> found = lib.search_su(pattern);

      for (const auto& media : found) {
        media->print();
      }
      cout << "You have found " << found.size() << " results by subject." << endl << endl;
    }
    else if (option == "4") {
      getline(cin, pattern);
      vector<Media*> found = lib.search_ot(pattern);

      for (const auto& media : found) {
        media->print();
      }
      cout << "You have found " << found.size() << " results by other." << endl << endl;
    }
    else if (option == "5") {
      cout << "Exiting..." << endl;
    }
    else {
      cout << "Invalid option. Choose a number between 1-5." << endl << endl;
    }
  } while (option != "5");

  return 0;
}