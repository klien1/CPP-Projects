// File: periodic.cpp
// Author: Kevin Lien

#include "periodic.h"

Periodic::Periodic(const std::string& cn,
          const std::string& title,
          const std::string& subj,
          const std::string& auth,
          const std::string& desc,
          const std::string& pub,
          const std::string& pub_his,
          const std::string& series,
          const std::string& notes,
          const std::string& rel_ti,
          const std::string& other_ti,
          const std::string& gov_num) : 
            Media(cn, title, subj, notes),
            author(auth),
            description(desc),
            publisher(pub),
            publishing_history(pub_his),
            series(series),
            related_titles(rel_ti),
            other_forms_of_title(other_ti),
            govt_doc_number(gov_num) {}

bool Periodic::search_ot(const std::string& target) const {
  if (kmp(target, description) || kmp(target, notes) ||
      kmp(target, series) || kmp(target, related_titles)) {
    return true;
  }
  return false;
}

void Periodic::print() const {
  std::cout << std::setw(25) << std::left << "Call number: " << call_number << std::endl;
  std::cout << std::setw(25) << std::left << "Title: " << title << std::endl;
  std::cout << std::setw(25) << std::left << "Subject: " << subject << std::endl;
  std::cout << std::setw(25) << std::left << "Author: " << author << std::endl;
  std::cout << std::setw(25) << std::left << "Description: " << description << std::endl;
  std::cout << std::setw(25) << std::left << "Publisher: " << publisher << std::endl;
  std::cout << std::setw(25) << std::left << "Publishing History: " << publishing_history << std::endl;
  std::cout << std::setw(25) << std::left << "Series: " << series << std::endl;
  std::cout << std::setw(25) << std::left << "Notes: " << notes << std::endl;
  std::cout << std::setw(25) << std::left << "Related Titles: " << related_titles << std::endl;
  std::cout << std::setw(25) << std::left << "Other Titles: " << other_forms_of_title << std::endl;
  std::cout << std::setw(25) << std::left << "Govt Doc Number: " << govt_doc_number << std::endl << std::endl;
}