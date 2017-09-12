// File: periodic.cpp
// Author: Kevin Lien

#include "periodic.h"

Periodic::Periodic(std::string cn,
          std::string title,
          std::string subj,
          std::string auth,
          std::string desc,
          std::string pub,
          std::string pub_his,
          std::string series,
          std::string notes,
          std::string rel_ti,
          std::string other_ti,
          std::string gov_num) : 
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
