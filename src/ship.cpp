// Copyright (c) 2020 [Alekhya Vakkalagadda]. All rights reserved.

#include <mylibrary/ship.h>

#include <string>

namespace mylibrary {

Ship::Ship() : size_{0}, name_{"" }, counter_{0} {}

Ship::Ship(std::string name, int size) : size_{size}, name_{name}, counter_{size} {}

void Ship::SetSize(int size) {
  size_ = size;
}

int Ship::GetSize() {
  return size_;
}

void Ship::SetCounter(int counter) {
  counter_ = counter;
}

int Ship::GetCounter() {
  return counter_;
}

void Ship::SetName(std::string name) {
  name_ = name;
}

std::string Ship::GetName() {
  return name_;
}

}  // namespace mylibrary
