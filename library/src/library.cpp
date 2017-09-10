// File: library.cpp
// Author: Kevin Lien

#include <fstream>

#include "library.h"

Library::Library() {
  std::ifstream inFile;

  inFile.open("book.txt");
  if (!inFile) {
    std::cerr << "Error. Unable to open book.txt." << std::endl;
  }
  else {
    std::string cn;
    std::string title;
    std::string subj;
    std::string auth;
    std::string desc;
    std::string pub;
    std::string city;
    std::string year;
    std::string series;
    std::string notes;

    // while(!getline(inFile, cn, '|').eof()) {
    while(getline(inFile, cn, '|')) {
      getline(inFile, title, '|');
      getline(inFile, subj, '|');
      getline(inFile, auth, '|');
      getline(inFile, desc, '|');
      getline(inFile, pub, '|');
      getline(inFile, city, '|');
      getline(inFile, year, '|');
      getline(inFile, series, '|');
      getline(inFile, notes, '\n');
      this->media.push_back(new Book(cn, title, subj, auth, desc, pub, city, year, series, notes));
    }
  }
  inFile.close();
  inFile.open("periodic.txt");
  if (!inFile) {
    std::cerr << "Error. Unable to open periodic.txt." << std::endl;
  }
  else {
    std::string cn;
    std::string title;
    std::string subj;
    std::string auth;
    std::string desc;
    std::string pub;
    std::string pub_his;
    std::string series;
    std::string notes;
    std::string rel_ti;
    std::string other_ti;
    std::string gov_num;

    while(getline(inFile, cn, '|')) {
      getline(inFile, title, '|');
      getline(inFile, subj, '|');
      getline(inFile, auth, '|');
      getline(inFile, desc, '|');
      getline(inFile, pub, '|');
      getline(inFile, pub_his, '|');
      getline(inFile, series, '|');
      getline(inFile, notes, '|');
      getline(inFile, rel_ti, '|');
      getline(inFile, other_ti, '|');
      getline(inFile, gov_num, '\n');
      this->media.push_back(new Periodic(cn, title, subj, auth, desc, pub, pub_his, 
                                      series, notes, rel_ti, other_ti, gov_num));
    }
  }
  inFile.close();

  inFile.open("film.txt");
  if (!inFile) {
    std::cerr << "Error. Unable to open film.txt." << std::endl;
  }
  else {
    std::string cn;
    std::string title;
    std::string subj;
    std::string dir;
    std::string notes;
    std::string year;

    while(getline(inFile, cn, '|')) {
      getline(inFile, title, '|');
      getline(inFile, subj, '|');
      getline(inFile, dir, '|');
      getline(inFile, notes, '|');
      getline(inFile, year, '\n');
      this->media.push_back(new Film(cn, title, subj, dir, notes, year));
    }
  }
  inFile.close();

  inFile.open("video.txt");
  if (!inFile) {
    std::cerr << "Error. Unable to open video.txt." << std::endl;
  }
  else {
    std::string cn;
    std::string title;
    std::string subj;
    std::string desc;
    std::string dist;
    std::string notes;
    std::string series;
    std::string label;

    while(getline(inFile, cn, '|')) {
      getline(inFile, title, '|');
      getline(inFile, subj, '|');
      getline(inFile, desc, '|');
      getline(inFile, dist, '|');
      getline(inFile, notes, '|');
      getline(inFile, series, '|');
      getline(inFile, label, '\n');
      this->media.push_back(new Video(cn, title, subj, desc, dist, notes, series, label));
    }
  }
  inFile.close();

  for (const Media* m_obj : media) {
    m_obj->getName();
  }
}

Library::~Library() {
  for (const Media* media_obj : media) {
    delete media_obj;
  }
}