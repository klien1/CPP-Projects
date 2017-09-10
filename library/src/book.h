// File: book.h
// Author: Kevin Lien

#ifndef BOOK_H
#define BOOK_H

#include "media.h"

class Book : public Media {
  public:
    Book(std::string cn,
          std::string title,
          std::string subj,
          std::string auth,
          std::string desc,
          std::string pub,
          std::string city,
          std::string year,
          std::string series,
          std::string notes);
    bool search_cn(const std::string& target) const;
    bool search_ti(const std::string& target) const;
    bool search_su(const std::string& target) const;
    bool search_ot(const std::string& target) const;
  protected:
  private:
    std::string author;
    std::string description;
    std::string publisher;
    std::string city;
    std::string year;
    std::string series;
};

#endif