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

    cin >> option;
    if (option == "1") {
      cout << "Type search result: ";
      cin >> pattern;
      vector<Media*> found = lib.search_cn(pattern);

      cout << "Results by call number:" << endl;
      for (const auto& media : found) {
        media->printCN();
      }
      cout << "You have found " << found.size() << " results." << endl << endl;
    }
    else if (option == "2") {
      cout << "Type search result: ";
      cin >> pattern;
      vector<Media*> found = lib.search_ti(pattern);

      cout << "Results by title:" << endl;
      for (const auto& media : found) {
        media->printTI();
      }
      cout << "You have found " << found.size() << " results." << endl << endl;
    }
    else if (option == "3") {
      cout << "Type search result: ";
      cin >> pattern;
      vector<Media*> found = lib.search_su(pattern);

      cout << "Results by subject:" << endl;
      for (const auto& media : found) {
        media->printSU();
      }
      cout << "You have found " << found.size() << " results." << endl << endl;
    }
    else if (option == "4") {
      cin >> pattern;
      vector<Media*> found = lib.search_ot(pattern);

      cout << "Results by other:" << endl;
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