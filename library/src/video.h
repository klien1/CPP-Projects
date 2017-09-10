// File: video.h
// Author: Kevin Lien

#ifndef VIDEO_H
#define VIDEO_H

#include "media.h"

class Video : public Media {
  public:
    Video(std::string cn,
          std::string title,
          std::string subj,
          std::string desc,
          std::string dist,
          std::string notes,
          std::string series,
          std::string label);
    void getName() const;
  protected:
  private:
    std::string description;
    std::string distributor;
    std::string series;
    std::string label;
};

#endif