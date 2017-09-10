// File: book.cpp

#include "book.h"
// #include <iostream>
// #include <string>

Book::Book(std::string cn,
          std::string title,
          std::string subj,
          std::string auth,
          std::string desc,
          std::string pub,
          std::string city,
          std::string year,
          std::string series,
          std::string notes) : 
            Media(cn, title, subj), 
            author(auth), 
            description(desc),
            publisher(pub),
            city(city),
            year(year),
            series(series),
            notes(notes) {
  // std::cout << "book constructor\n";
  // std::ifstream inFile;

  // inFile.open("book.txt");

  // if (!inFile) {
  //   std::cerr << "unable to open book.txt" << std::endl;
  // }

  // std::string text;

  // while(std::getline(inFile, text, '|')) {
  //   std::cout << text << std::endl;
  // }

  // inFile.close();

}

void Book::getName() const {
  std::cout << "I am a Book. My name is " << call_number << std::endl;
}