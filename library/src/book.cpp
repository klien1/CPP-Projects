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
  if (kmp(target, description) || kmp(target, notes) || kmp(target,year)) {
    return true;
  }
  return false;
}
