// File: video.h
// Author: Kevin Lien

#ifndef VIDEO_H
#define VIDEO_H

#include "media.h"

class Video : public Media {
  public:
    Video(const std::string& cn,
          const std::string& title,
          const std::string& subj,
          const std::string& desc,
          const std::string& dist,
          const std::string& notes,
          const std::string& series,
          const std::string& label);
    bool search_ot(const std::string& target) const;
  protected:
  private:
    std::string description;
    std::string distributor;
    std::string series;
    std::string label;
};

#endif