// File: film.cpp
// Author: Kevin Lien

#include "film.h"

Film::Film(std::string cn,
          std::string title,
          std::string subj,
          std::string dir,
          std::string notes,
          std::string year) : 
            Media(cn, title, subj, notes),
            director(dir), year(year) {}

bool Film::search_ot(const std::string& target) const {
  std::cout << target << std::endl;
  return false;
}
