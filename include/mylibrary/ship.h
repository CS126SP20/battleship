//
// Created by Alekhya on 5/2/2020.
//

#ifndef FINALPROJECT_SHIP_H
#define FINALPROJECT_SHIP_H

#include <string>

namespace mylibrary {
class Ship {
 private:
  int size_;
  int counter_;
  std::string name_;
 public:
    Ship();
    Ship(std::string name, int size);
    void SetCounter(int counter);
    int GetCounter();
    void SetSize(int size);
    int GetSize();
    void SetName(std::string name);
    std::string GetName();
};

} //namespace mylibrary

#endif  // FINALPROJECT_SHIP_H
