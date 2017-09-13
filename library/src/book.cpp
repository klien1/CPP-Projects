// File: book.cpp
// Author: Kevin Lien

#include "book.h"


Book::Book(const std::string& cn,
            const std::string& title,
            const std::string& subj,
            const std::string& auth,
            const std::string& desc,
            const std::string& pub,
            const std::string& city,
            const std::string& year,
            const std::string& series,
            const std::string& notes) : 
              Media(cn, title, subj, notes), 
              author(auth), 
              description(desc),
              publisher(pub),
              city(city),
              year(year),
              series(series) {}

bool Book::search_ot(const std::string& target) const {
  if (kmp(target, description) || kmp(target, notes) || kmp(target, year)) {
    return true;
  }
  return false;
}

void Book::print() const {
  std::cout << std::setw(25) << std::left << "Call number: " << call_number << std::endl;
  std::cout << std::setw(25) << std::left << "Title: " << title << std::endl;
  std::cout << std::setw(25) << std::left << "Subject: " << subject << std::endl;
  std::cout << std::setw(25) << std::left << "Author: " << author << std::endl;
  std::cout << std::setw(25) << std::left << "Description: " << description << std::endl;
  std::cout << std::setw(25) << std::left << "Publisher: " << publisher << std::endl;
  std::cout << std::setw(25) << std::left << "City: " << city << std::endl;
  std::cout << std::setw(25) << std::left << "Year: " << year << std::endl;
  std::cout << std::setw(25) << std::left << "Series: " << series << std::endl;
  std::cout << std::setw(25) << std::left << "Notes: " << notes << std::endl << std::endl;
}