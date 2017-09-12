// File: book.cpp
// Author: Kevin Lien

#include "book.h"

Book::Book(std::string cn,
          std::string title,
          std::string subj,
          std::string auth,
          std::string desc,
          std::string pub,
          std::string city,
          std::string year,
          std::string series,
          std::string notes) : 
            Media(cn, title, subj, notes), 
            author(auth), 
            description(desc),
            publisher(pub),
            city(city),
            year(year),
            series(series) {}

bool Book::search_ot(const std::string& target) const {
  std::cout << target << std::endl;
  return false;
}
