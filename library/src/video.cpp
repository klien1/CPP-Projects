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

void Video::print() const {
  std::cout << std::endl << "Video" << std::endl << "=====" << std::endl;
  std::cout << "Call Number: " << call_number << std::endl;
  std::cout << "Title: " << title << std::endl;
  std::cout << "Subject: " << subject << std::endl;
  std::cout << "Description: " << description << std::endl;
  std::cout << "Distributor: " << distributor << std::endl;
  std::cout << "Notes: " << notes << std::endl;
  std::cout << "Series: " << series << std::endl;
  std::cout << "Label: " << label << std::endl;
}