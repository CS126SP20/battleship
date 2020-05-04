// Copyright (c) 2020 [Alekhya Vakkalagadda]. All rights reserved.

#ifndef FINALPROJECT_SHIPGRID_H
#define FINALPROJECT_SHIPGRID_H

#include <mylibrary/tilestate.h>
#include "ship.h"

#include <string>

namespace mylibrary {

class Ship_Grid_Class {
 private:
  std::string ship_name_;
  Ship ship_obj_;
  bool has_ship_;
 public:
  Ship_Grid_Class();
};




}  // namespace mylibrary

#endif  // FINALPROJECT_SHIPGRID_H
