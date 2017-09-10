// File: library.h
// Author: Kevin Lien

#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>

#include "media.h"
#include "book.h"
#include "film.h"
#include "periodic.h"
#include "video.h"

class Library {
  public:
    Library();
    ~Library();
  protected:
  private:
    std::vector<Media*> media;
};

#endif