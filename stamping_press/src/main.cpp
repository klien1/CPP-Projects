// Author: Kevin Lien
// File: main.cpp

#include "stampstream.h"

int main() {
  stampstream s(30,10);
  s << "hi th#re planetoid humans" << endrow 
    << "  how's all the fish" << row(5) << "one more";
  s << row(4) << "   two more" << 3.1415;
  s << row(8) << "The quick brown fox jumped over the lazy dog's back.";
  s << row(3) << "the end";
  s << row(9) << "printing to last row" << endrow << "should go off screen";
  return 0;
}