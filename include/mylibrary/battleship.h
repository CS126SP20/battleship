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

  // 2d array to hold the tile state
  TileState battle_grid_[kGridSize][kGridSize]{};

  //holds struct information
  Ship_Grid ship_grid_arr_[kGridSize][kGridSize]{};

  //ships to be randomly placed
  Ship ship_a_, ship_b_, ship_c_;


 public:
  /**
   * Default constructor
   */
  Battleship();

  /**
   * Initializes battle_grid array to an empty state
   */
  void InitializeGrid();

  /**
   * Initializes ship_grid array to false
   */
  void InitializeShipGrid();

  /**
   * Sets the tile in the battle_grid array to a certain tile state
   * @param row - x-coord
   * @param col - y-coord
   */
  void SetGridItem(int row, int col);

  /**
   * Gets the tile's tile state
   * @param row - x-coord
   * @param col - y-coord
   * @return TileState
   */
  TileState GetGridItem(int row, int col);

  /**
   * Sets a tile to have a ship
   * @param row - x-coord
   * @param col - y-coord
   */
  void SetHasShip(int row, int col);

  /**
   * Checks to see if there is a ship on a tile
   * @param row - x-coord
   * @param col - y-coord
   * @return
   */
  bool GetHasShip(int row, int col);

  /**
   * Sets the tiles with the ships to be in a sink state
   */
  void SetSinkTiles();

  /**
   * Places the ship horizontally
   * @param ship_name - name
   * @param size_ship - size
   */
  void PlaceHShip(const std::string& ship_name, int size_ship);

  /**
   * Places the ship vertically
   * @param ship_name - name
   * @param size_ship - size
   */
  void PlaceVShip(const std::string& ship_name, int size_ship);

  /**
   * Places ready-made ship objects
   */
  void PlaceShip();

  /**
   * Checks to see if there are ships around the potentially placed ship
   * @param rand_x1 - random x-coord1
   * @param rand_y1 - random y-coord1
   * @param rand_x2 - random x-coord2
   * @param rand_y2 - random y-coord2
   * @return
   */
  bool HasShip(int rand_x1, int rand_y1, int rand_x2, int rand_y2);
  };




}  // namespace mylibrary


#endif // FINALPROJECT_MYLIBRARY_EXAMPLE_H_
