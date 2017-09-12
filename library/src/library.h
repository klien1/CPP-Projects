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
    const std::vector<Media*>& search_cn(const std::string& target);
    const std::vector<Media*>& search_ti(const std::string& target);
    const std::vector<Media*>& search_su(const std::string& target);
    std::vector<Media*> search_ot(const std::string& target);
  protected:
  private:
    std::vector<Media*> media;
    std::vector<Media*> query;
};

#endif