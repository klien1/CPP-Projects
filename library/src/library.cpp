// File: library.cpp
// Author: Kevin Lien

#include <fstream>

#include "library.h"

Library::Library() {
  initialize_book();
  initialize_periodic();
  initialize_film();
  initialize_video();
}

Library::~Library() {
  for (const Media* media_obj : media) {
    delete media_obj;
  }
  query.clear();
}

const std::vector<const Media*>& Library::search_cn(const std::string& target) {
  query.clear();
  for (const Media* media_obj : media) {
    if (media_obj->search_cn(target)) {
      query.push_back(media_obj);
    }
  }
  return query;
}

const std::vector<const Media*>& Library::search_ti(const std::string& target) {
  query.clear();
  for (const Media* media_obj : media) {
    if (media_obj->search_ti(target)) {
      query.push_back(media_obj);
    }
  }
  return query;
}

const std::vector<const Media*>& Library::search_su(const std::string& target) {
  query.clear();
  for (const Media* media_obj : media) {
    if (media_obj->search_su(target)) {
      query.push_back(media_obj);
    }
  }
  return query;
}

const std::vector<const Media*>& Library::search_ot(const std::string& target) {
  query.clear();
  for (const Media* media_obj : media) {
    if (media_obj->search_ot(target)) {
      query.push_back(media_obj);
    }
  }
  return query;
}

void Library::initialize_book() {
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
}

void Library::initialize_periodic() {
  std::ifstream inFile;

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
}

void Library::initialize_film() {
  std::ifstream inFile;

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
}

void Library::initialize_video() {
  std::ifstream inFile;

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
}