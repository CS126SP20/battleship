// Copyright (c) 2020 [Alekhya Vakkalagadda]. All rights reserved.

#include <mylibrary/battleship.h>

#include <iostream>
#include <string>

namespace mylibrary {

void Battleship::InitializeGrid() {
  for (int row = 1; row < 7; row++) {
    for (int col = 1; col < 7; col++) {
      battle_grid_[row][col] = TileState::kEmpty;
    }
  }
}

void Battleship::SetGridItem(int row, int col) {
  int counter;

  if (ship_grid_arr_[row][col].has_ship_) {
    counter = ship_grid_arr_[row][col].ship_obj_.GetCounter();
    std::cout<< "counter " << counter << "\n";
    if (counter > 0) {
      battle_grid_[row][col] = TileState::kHit;
      ship_grid_arr_[row][col].ship_obj_.SetCounter(counter--);
      std::cout<< "updated counter " << counter << "\n";
    } else {
      SetSinkTiles();
    }
  } else {
    battle_grid_[row][col] = TileState::kMiss;
  }
}

void Battleship::SetSinkTiles() {
  for (int row = 1; row < 7; row++) {
    for (int col = 1; col < 7; col++) {
      if (ship_grid_arr_[row][col].ship_obj_.GetCounter() == 0) {
        battle_grid_[row][col] = TileState::kSink;
      }
    }
  }
}

TileState Battleship::GetGridItem(int row, int col) {
  return battle_grid_[row][col];
}

void Battleship::InitializeShipGrid() {
  ship_a_ = Ship("shipA", 3);
  ship_b_ = Ship("shipB", 2);

  for (int row = 1; row < 7; row++) {
    for (int col = 1; col < 7; col++) {
      ship_grid_arr_[row][col].has_ship_ = false;
    }
  }

  ship_grid_arr_[2][1].has_ship_ = true;
  ship_grid_arr_[2][1].ship_obj_ = ship_a_;

  ship_grid_arr_[3][1].has_ship_ = true;
  ship_grid_arr_[3][1].ship_obj_ = ship_a_;

  ship_grid_arr_[4][1].has_ship_ = true;
  ship_grid_arr_[4][1].ship_obj_ = ship_a_;

  std::string ship_name = ship_grid_arr_[2][1].ship_obj_.GetName();
  int ship_size = ship_grid_arr_[2][1].ship_obj_.GetSize();
  std::cout<< "ship name " << ship_name << " ship size " << ship_size << "\n";

  std::string ship_name1 = ship_grid_arr_[3][1].ship_obj_.GetName();
  int ship_size1 = ship_grid_arr_[3][1].ship_obj_.GetSize();
  std::cout<< "ship name " << ship_name1 << " ship size " << ship_size1 << "\n";

  std::string ship_name2 = ship_grid_arr_[4][1].ship_obj_.GetName();
  int ship_size2 = ship_grid_arr_[4][1].ship_obj_.GetSize();
  std::cout<< "ship name " << ship_name2 << " ship size " << ship_size2 << "\n";


  /*
  for (int row = 1; row < 7; row+=2) {
    for (int col = 1; col < 7; col+=2) {
      ship_grid_arr_[row][col].has_ship_ = true;
      ship_grid_arr_[row][col].ship_obj_.SetName("hi");
      ship_grid_arr_[row][col].ship_obj_.SetSize(2);
    }
  }

  for (int row = 2; row < 7; row+=2) {
    for (int col = 2; col < 7; col+=2) {
      ship_grid_arr_[row][col].has_ship_ = false;
      ship_grid_arr_[row][col].ship_obj_.SetName("hello");
      ship_grid_arr_[row][col].ship_obj_.SetSize(3);
    }
  }*/
}

/*
void Battleship::InitializeShipGrid2() {
  for (int row = 1; row < 5; row+=2) {
    for (int col = 1; col < 5; col+=2) {
      ship_grid2_[row][col] = true;
    }
  }

  for (int row = 2; row < 5; row+=2) {
    for (int col = 2; col < 5; col+=2) {
      ship_grid2_[row][col] = false;
    }
  }
}*/





}  // namespace mylibrary
