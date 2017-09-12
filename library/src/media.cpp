// File: media.cpp
// Author: Kevin Lien

#include "media.h"

Media::Media(std::string cn, std::string title, std::string subj, std::string notes) : 
              call_number(cn), title(title), subject(subj), notes(notes) {}

Media::~Media() {}

bool Media::search_cn(const std::string& target) const {
  if (kmp(target, call_number)) {
    return true;
  }
  return false;
}

bool Media::search_ti(const std::string& target) const {
  if (kmp(target, title)) {
    return true;
  }
  return false;
}

bool Media::search_su(const std::string& target) const {
  if (kmp(target, subject)) {
    return true;
  }
  return false;
}

bool Media::kmp(const std::string& target, const std::string& haystack) const {
  const unsigned int target_size = target.size();
  const unsigned int haystack_size = haystack.size();
  int* prefix_table = kmp_prefix(target);
  unsigned int i = 0; // keeps track of number of characters matched

  for (unsigned int j = 0; j < haystack_size; ++j) {
    while (i > 0 && target[i] != haystack[j]) {
      i = prefix_table[i-1]; // skips repeated substring matches
    }
    if (target[i] == haystack[j]) {
      ++i; // increment when characters match
    }
    if (i == target_size) { // match found
      delete [] prefix_table;
      return true;
    }
  }
  delete [] prefix_table;
  return false;
}

int* Media::kmp_prefix(const std::string& target) const {
  const unsigned int pattern_size = target.size();
  int* prefix = new int[pattern_size];
  prefix[0] = 0;

  int i = 0; // keeps track of current longest prefix
  for (unsigned int j = 1; j < pattern_size; ++j) {
    while(i > 0 && target[i] != target[j]) {
      i = prefix[i-1]; // grab previous prefix value since no match
    }
    if (target[i] == target[j]) {
      ++i; // increment longest prefix when characters match
    }
    prefix[j] = i; 
  }
  return prefix;
}