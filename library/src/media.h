// File: media.h

#ifndef MEDIA_H
#define MEDIA_H

#include <iostream>
// #include <fstream>
#include <string>

class Media {
  public:
    Media(std::string cn,
          std::string title,
          std::string subj);
    virtual ~Media();
    virtual void getName() const = 0;
  protected:
    std::string call_number;
    std::string title;
    std::string subject;
  private:
};

#endif