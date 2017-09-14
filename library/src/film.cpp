// File: film.cpp
// Author: Kevin Lien

#include "film.h"

Film::Film(const std::string& cn,
            const std::string& title,
            const std::string& subj,
            const std::string& dir,
            const std::string& notes,
            const std::string& year) : 
              Media(cn, title, subj, notes),
              director(dir), year(year) {}

bool Film::search_ot(const std::string& target) const {
  if (kmp(target, notes) || kmp(target, director) || kmp(target, year)) {
    return true;
  }
  return false;
}

void Film::print() const {
  std::cout << std::endl << "Film" << std::endl << "====" << std::endl;
  std::cout << "Call Number: " << call_number << std::endl;
  std::cout << "Title: " << title << std::endl;
  std::cout << "Subject: " << subject << std::endl;
  std::cout << "Director: " << director << std::endl;
  std::cout << "Notes: " << notes << std::endl;
  std::cout << "Year: " << year << std::endl;
}