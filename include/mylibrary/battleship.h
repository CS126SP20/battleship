// Copyright (c) 2020 [Alekhya Vakkalagadda]. All rights reserved.
#ifndef FINALPROJECT_MYLIBRARY_EXAMPLE_H_
#define FINALPROJECT_MYLIBRARY_EXAMPLE_H_

#include <mylibrary/tilestate.h>
#include "ship.h"

#include <string>

namespace mylibrary {

const int kGridSize = 7;
const int kShipASize = 3;
const int kShipBSize = 2;
const int kShipCSize = 2;
const int kNumCheck = 20;

class Battleship {
 private:
  struct Ship_Grid {
    std::string ship_name_;
    bool has_ship_;
  };
  TileState battle_grid_[kGridSize][kGridSize]{};
  Ship ship_a_, ship_b_, ship_c_;

  Ship_Grid ship_grid_arr_[kGridSize][kGridSize]{};
 public:
  Battleship();
  void InitializeGrid();
  void InitializeShipGrid();
  void SetGridItem(int row, int col);
  TileState GetGridItem(int row, int col);
  void SetHasShip(int row, int col);
  bool GetHasShip(int row, int col);
  void SetShipName(int row, int col, std::string name);
  std::string GetShipName(int row, int col);
  void SetSinkTiles();
  void PlaceHShip(const std::string& ship_name, int size_ship);
  void PlaceVShip(const std::string& ship_name, int size_ship);
  void PlaceShip();
  bool HasShip(int rand_x1, int rand_y1, int rand_x2, int rand_y2);
  };




}  // namespace mylibrary


#endif // FINALPROJECT_MYLIBRARY_EXAMPLE_H_
