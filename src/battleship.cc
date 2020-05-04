// Copyright (c) 2020 [Alekhya Vakkalagadda]. All rights reserved.

#include <mylibrary/battleship.h>

#include <iostream>
#include <string>

namespace mylibrary {

Battleship::Battleship()
: ship_grid_arr_(),
  ship_a_{Ship("shipA", 3)},
  ship_b_{Ship("shipB", 2)},
  ship_c_{Ship("shipC", 4)}

{}

void Battleship::InitializeGrid() {
  for (int row = 1; row < 7; row++) {
    for (int col = 1; col < 7; col++) {
      battle_grid_[row][col] = TileState::kEmpty;
    }
  }
}

/*
void Battleship::SetGridItem(int row, int col) {
  int counter;

  if (ship_grid_arr_[row][col].has_ship_) {
    counter = ship_grid_arr_[row][col].ship_obj_.GetCounter();
    std::cout<< "counter " << counter << "\n";
    if (counter > 0) {
      battle_grid_[row][col] = TileState::kHit;
      counter--;
      ship_grid_arr_[row][col].ship_obj_.SetCounter(counter);
      std::cout<< "updated counter " << counter << "\n";
    } else {
      SetSinkTiles();
    }
  } else {
    battle_grid_[row][col] = TileState::kMiss;
  }
}*/


void Battleship::SetGridItem(int row, int col) {

  if (ship_grid_arr_[row][col].has_ship_) {
    int counter;
    std::string ship_name = ship_grid_arr_[row][col].ship_name_;
    std::cout << ship_name << "\n";

    if (ship_name == ship_a_.GetName()) {
      counter = ship_a_.GetCounter();
      std::cout<< "counter " << counter << "\n";
      if (counter > 0) {
        counter--;
        ship_a_.SetCounter(counter);
        battle_grid_[row][col] = TileState::kHit;
        std::cout<< "updated counter " << counter << "\n";
      }
    } else if (ship_name == ship_b_.GetName()) {
      counter = ship_b_.GetCounter();
      std::cout<< "counter " << counter << "\n";
      if (counter > 0) {
        counter--;
        ship_b_.SetCounter(counter);
        battle_grid_[row][col] = TileState::kHit;
        std::cout<< "updated counter " << counter << "\n";
      }
    } else if (ship_name == ship_c_.GetName()) {
      counter = ship_c_.GetCounter();
      std::cout<< "counter " << counter << "\n";
      if (counter > 0) {
        counter--;
        ship_c_.SetCounter(counter);
        battle_grid_[row][col] = TileState::kHit;
        std::cout<< "updated counter " << counter << "\n";
      }
    }
    SetSinkTiles();
  } else {
    battle_grid_[row][col] = TileState::kMiss;
  }
}

void Battleship::SetSinkTiles() {
  std::string ship_name;
  int ship_count;

  for (int row = 1; row < 7; row++) {
    for (int col = 1; col < 7; col++) {
      if (ship_grid_arr_[row][col].has_ship_) {
        ship_name = ship_grid_arr_[row][col].ship_name_;
        if (ship_name == ship_a_.GetName()) {
          ship_count = ship_a_.GetCounter();
        } else if (ship_name == ship_b_.GetName()) {
          ship_count = ship_b_.GetCounter();
        } else if (ship_name == ship_c_.GetName()) {
          ship_count = ship_c_.GetCounter();
        }
        if (ship_count == 0) {
          battle_grid_[row][col] = TileState::kSink;
        }
      }
    }
  }

}

TileState Battleship::GetGridItem(int row, int col) {
  return battle_grid_[row][col];
}

void Battleship::InitializeShipGrid() {
    for (int row = 1; row < 7; row++) {
    for (int col = 1; col < 7; col++) {
      ship_grid_arr_[row][col].has_ship_ = false;
    }
  }

  //SHIP A
  ship_grid_arr_[2][1].has_ship_ = true;
  ship_grid_arr_[2][1].ship_name_ = ship_a_.GetName();
  //ship_grid_arr_[2][1].ship_obj_ = ship_a_;

  ship_grid_arr_[3][1].has_ship_ = true;
  ship_grid_arr_[3][1].ship_name_ = ship_a_.GetName();
  //ship_grid_arr_[3][1].ship_obj_ = ship_a_;

  ship_grid_arr_[4][1].has_ship_ = true;
  ship_grid_arr_[4][1].ship_name_ = ship_a_.GetName();
  //ship_grid_arr_[4][1].ship_obj_ = ship_a_;

  //SHIP B
  ship_grid_arr_[5][3].has_ship_ = true;
  ship_grid_arr_[5][3].ship_name_ = ship_b_.GetName();
  //ship_grid_arr_[2][1].ship_obj_ = ship_b_;

  ship_grid_arr_[5][4].has_ship_ = true;
  ship_grid_arr_[5][4].ship_name_ = ship_b_.GetName();

  //SHIP C
  ship_grid_arr_[3][6].has_ship_ = true;
  ship_grid_arr_[3][6].ship_name_ = ship_c_.GetName();
  //ship_grid_arr_[2][1].ship_obj_ = ship_c_;

  ship_grid_arr_[4][6].has_ship_ = true;
  ship_grid_arr_[4][6].ship_name_ = ship_c_.GetName();

  ship_grid_arr_[5][6].has_ship_ = true;
  ship_grid_arr_[5][6].ship_name_ = ship_c_.GetName();

  ship_grid_arr_[6][6].has_ship_ = true;
  ship_grid_arr_[6][6].ship_name_ = ship_c_.GetName();

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






}  // namespace mylibrary
