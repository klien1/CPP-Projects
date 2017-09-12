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

    void printCN() const {std::cout << call_number << std::endl;}
    void printTI() const {std::cout << title << std::endl;}
    void printSU() const {std::cout << subject << std::endl;}
    // virtual void print() const = 0;

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