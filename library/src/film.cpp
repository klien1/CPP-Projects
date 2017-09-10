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
/*
    std::string author;
    std::string description;
    std::string publisher;
    std::string publishing_history;
    std::string series;
    std::string notes;
    std::string related_titles;
    std::string other_forms_of_title;
    std::string govt_doc_number;
    */

// void Film::getName() const {
//   std::cout << "I am a Film. CN: " << call_number << std::endl;
// }
bool Film::search_cn(const std::string& target) const {
  std::cout << target << std::endl;
  return false;
}

bool Film::search_ti(const std::string& target) const {
  std::cout << target << std::endl;
  return false;
}

bool Film::search_su(const std::string& target) const {
  std::cout << target << std::endl;
  return false;
}

bool Film::search_ot(const std::string& target) const {
  std::cout << target << std::endl;
  return false;
}
