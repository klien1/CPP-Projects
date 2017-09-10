// File: media.cpp
// Author: Kevin Lien

#include "media.h"

Media::Media(std::string cn, std::string title, std::string subj, std::string notes) : 
              call_number(cn), title(title), subject(subj), notes(notes) {}

Media::~Media() {}

// failed because media didn't have a virtual class
// int Media::get_num() {
//   return 100;
// }

// void Media::getName() const {
//   std::cout << "I am a Media.\n";
// }