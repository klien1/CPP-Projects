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
    const std::vector<const Media*>& search_cn(const std::string& target);
    const std::vector<const Media*>& search_ti(const std::string& target);
    const std::vector<const Media*>& search_su(const std::string& target);
    const std::vector<const Media*>& search_ot(const std::string& target);
    
  private:
    std::vector<const Media*> media;
    std::vector<const Media*> query;

    void initialize_book();
    void initialize_periodic();
    void initialize_film();
    void initialize_video();
};

#endif