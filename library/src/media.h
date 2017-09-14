// File: media.h
// Author: Kevin Lien

#ifndef MEDIA_H
#define MEDIA_H

#include <iostream>
#include <string>

class Media {
  public:
    Media(const std::string& cn,
          const std::string& title,
          const std::string& subj,
          const std::string& notes);
    virtual ~Media();

    bool search_cn(const std::string& target) const;
    bool search_ti(const std::string& target) const;
    bool search_su(const std::string& target) const;
    virtual bool search_ot(const std::string& target) const = 0;
    virtual void print() const = 0;
    
  protected:
    const std::string call_number;
    const std::string title;
    const std::string subject;
    const std::string notes;

    bool kmp(const std::string& target, const std::string& haystack) const;

  private:
    // kmp helper function
    int* kmp_prefix(const std::string& target) const;
};

#endif