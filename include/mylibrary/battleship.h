// Copyright (c) 2020 [Alekhya Vakkalagadda]. All rights reserved.
#ifndef FINALPROJECT_MYLIBRARY_EXAMPLE_H_
#define FINALPROJECT_MYLIBRARY_EXAMPLE_H_

#include <string>
#include <mylibrary/tilestate.h>

namespace mylibrary {

const int kGridSize = 4;

class Battleship {
 private:
  TileState battle_grid_[kGridSize][kGridSize]{};
  bool ship_grid_[kGridSize][kGridSize]{};
 public:
  void InitializeGrid();
  void InitializeShipGrid();
  void SetGridItem(int row, int col);
  TileState GetGridItem(int row, int col);
};




}  // namespace mylibrary


#endif // FINALPROJECT_MYLIBRARY_EXAMPLE_H_
