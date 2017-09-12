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
  std::cout << target << std::endl;
  return false;
}
