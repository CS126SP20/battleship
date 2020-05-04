// Copyright (c) 2020 [Alekhya Vakkalagadda]. All rights reserved.
#ifndef FINALPROJECT_MYLIBRARY_EXAMPLE_H_
#define FINALPROJECT_MYLIBRARY_EXAMPLE_H_

#include <mylibrary/tilestate.h>
#include "ship.h"

#include <string>

namespace mylibrary {

const int kGridSize = 7;

struct Ship_Grid {
  std::string ship_name_;
  Ship ship_obj_;
  bool has_ship_;
};

class Battleship {
 private:
  TileState battle_grid_[kGridSize][kGridSize]{};
  Ship ship_a_, ship_b_, ship_c_;

  Ship_Grid ship_grid_arr_[kGridSize][kGridSize]{};
 public:
  Battleship();
  void InitializeGrid();
  void InitializeShipGrid();
  void SetGridItem(int row, int col);
  TileState GetGridItem(int row, int col);
  bool GetShipGridItem(int row, int col);
  void SetSinkTiles();
  };




}  // namespace mylibrary


#endif // FINALPROJECT_MYLIBRARY_EXAMPLE_H_
