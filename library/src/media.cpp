#include "media.h"

Media::Media(std::string cn, std::string title, std::string subj) : 
              call_number(cn), title(title), subject(subj) {
  std::cout << "media constructor\n";
}

Media::~Media() {
  // std::cout << "media destructor\n";
}
// failed because media didn't have a virtual class
// int Media::get_num() {
//   return 100;
// }

void Media::getName() const {
  std::cout << "I am a Media.\n";
}