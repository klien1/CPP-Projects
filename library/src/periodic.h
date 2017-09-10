// File: periodic.h
// Author: Kevin Lien

#ifndef PERIODIC_H
#define PERIODIC_H

#include "media.h"

class Periodic : public Media {
  public:
    Periodic(std::string cn,
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
      std::string gov_num);
    bool search_cn(const std::string& target) const;
    bool search_ti(const std::string& target) const;
    bool search_su(const std::string& target) const;
    bool search_ot(const std::string& target) const;
  protected:
  private:
    std::string author;
    std::string description;
    std::string publisher;
    std::string publishing_history;
    std::string series;
    std::string related_titles;
    std::string other_forms_of_title;
    std::string govt_doc_number;
};

#endif