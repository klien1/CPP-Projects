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
  std::cout << std::setw(25) << std::left << "Call number: " << call_number << std::endl;
  std::cout << std::setw(25) << std::left << "Title: " << title << std::endl;
  std::cout << std::setw(25) << std::left << "Subject: " << subject << std::endl;
  std::cout << std::setw(25) << std::left << "Description: " << description << std::endl;
  std::cout << std::setw(25) << std::left << "Distributor: " << distributor << std::endl;
  std::cout << std::setw(25) << std::left << "Notes: " << notes << std::endl;
  std::cout << std::setw(25) << std::left << "Series: " << series << std::endl;
  std::cout << std::setw(25) << std::left << "Label: " << label << std::endl << std::endl;
}