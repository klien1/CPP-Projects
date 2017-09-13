// File: film.h
// Author: Kevin Lien

#ifndef FILM_H
#define FILM_H

#include "media.h"

class Film : public Media {
  public:
    Film(const std::string& cn,
          const std::string& title,
          const std::string& subj,
          const std::string& dir,
          const std::string& notes,
          const std::string& year);

    bool search_ot(const std::string& target) const;
    void print() const;

  private:
    std::string director;
    std::string year;
};

#endif