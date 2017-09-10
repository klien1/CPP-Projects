// File: media.h
// Author: Kevin Lien

#ifndef MEDIA_H
#define MEDIA_H

#include <iostream>

#include <string>

class Media {
  public:
    Media(std::string cn,
          std::string title,
          std::string subj,
          std::string notes);
    virtual ~Media();
    // virtual void getName() const = 0;
    virtual bool search_cn(const std::string& target) const = 0;
    virtual bool search_ti(const std::string& target) const = 0;
    virtual bool search_su(const std::string& target) const = 0;
    virtual bool search_ot(const std::string& target) const = 0;
  protected:
    std::string call_number;
    std::string title;
    std::string subject;
    std::string notes;
  private:
};

#endif