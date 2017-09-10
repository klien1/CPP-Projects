// File: video.cpp
// Author: Kevin Lien

#include "video.h"

Video::Video(std::string cn,
              std::string title,
              std::string subj,
              std::string desc,
              std::string dist,
              std::string notes,
              std::string series,
              std::string label) : 
                Media(cn, title, subj, notes),
                description(desc),
                distributor(dist),
                series(series),
                label(label) {}
void Video::getName() const {
  std::cout << "I am a Video. CN: " << call_number << std::endl;
}