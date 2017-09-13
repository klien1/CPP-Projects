// File: book.h
// Author: Kevin Lien

#ifndef BOOK_H
#define BOOK_H

#include "media.h"

class Book : public Media {
  public:
    Book(const std::string& cn,
          const std::string& title,
          const std::string& subj,
          const std::string& auth,
          const std::string& desc,
          const std::string& pub,
          const std::string& city,
          const std::string& year,
          const std::string& series,
          const std::string& notes);

    bool search_ot(const std::string& target) const;
    void print() const;

  private:
    std::string author;
    std::string description;
    std::string publisher;
    std::string city;
    std::string year;
    std::string series;
};

#endif