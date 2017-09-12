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
    bool search_cn(const std::string& target) const;
    bool search_ti(const std::string& target) const;
    bool search_su(const std::string& target) const;
    virtual bool search_ot(const std::string& target) const = 0;

    // void printMedia(const std::string& word) const {std::cout << "I am a media searching for " << word;}
    void printMedia() const {std::cout << call_number << std::endl;}

    bool kmp(const std::string& target, const std::string& haystack) const;
  protected:
    std::string call_number;
    std::string title;
    std::string subject;
    std::string notes;
  private:
    // kmp helper function
    int* kmp_prefix(const std::string& target) const;
};

#endif