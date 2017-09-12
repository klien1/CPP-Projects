// File: video.cpp
// Author: Kevin Lien

#include "video.h"

Video::Video(const std::string& cn,
              const std::string& title,
              const std::string& subj,
              const std::string& desc,
              const std::string& dist,
              const std::string& notes,
              const std::string& series,
              const std::string& label) : 
                Media(cn, title, subj, notes),
                description(desc),
                distributor(dist),
                series(series),
                label(label) {}

bool Video::search_ot(const std::string& target) const {
  if (kmp(target, description) || kmp(target, notes) || kmp(target, distributor)) {
    return true;
  }
  return false;
}
