// File: periodic.h
// Author: Kevin Lien

#ifndef PERIODIC_H
#define PERIODIC_H

#include "media.h"

class Periodic : public Media {
  public:
    Periodic(const std::string& cn,
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
      const std::string& gov_num);

    bool search_ot(const std::string& target) const;
    void print() const;
 
  private:
    const std::string author;
    const std::string description;
    const std::string publisher;
    const std::string publishing_history;
    const std::string series;
    const std::string related_titles;
    const std::string other_forms_of_title;
    const std::string govt_doc_number;
};

#endif