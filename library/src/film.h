// File: film.h
// Author: Kevin Lien

#ifndef FILM_H
#define FILM_H

#include "media.h"

class Film : public Media {
  public:
    Film(std::string cn,
          std::string title,
          std::string subj,
          std::string dir,
          std::string notes,
          std::string year);
    void getName() const;
  protected:
  private:
    std::string director;
    std::string year;
};

#endif