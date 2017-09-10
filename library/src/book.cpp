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

void Book::getName() const {
  std::cout << "I am a Book. CN: " << call_number << std::endl;
}