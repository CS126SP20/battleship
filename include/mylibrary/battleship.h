// Copyright (c) 2020 [Alekhya Vakkalagadda]. All rights reserved.
#ifndef FINALPROJECT_MYLIBRARY_EXAMPLE_H_
#define FINALPROJECT_MYLIBRARY_EXAMPLE_H_

#include <mylibrary/tilestate.h>
#include "ship.h"

#include <string>

namespace mylibrary {

const int kGridSize = 6;

class Battleship {
 private:
  TileState battle_grid_[kGridSize][kGridSize]{};
  Ship ship_a_, ship_b_;
  struct Ship_Grid {
    Ship ship_obj_;
    bool has_ship_;
  };
  Ship_Grid ship_grid_arr_[kGridSize][kGridSize]{};
  //bool ship_grid2_[kGridSize][kGridSize]{};
 public:
  void InitializeGrid();
  void InitializeShipGrid2();
  void InitializeShipGrid();
  void SetGridItem(int row, int col);
  TileState GetGridItem(int row, int col);
};




}  // namespace mylibrary


#endif // FINALPROJECT_MYLIBRARY_EXAMPLE_H_
