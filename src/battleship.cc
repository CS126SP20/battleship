// Copyright (c) 2020 [Alekhya Vakkalagadda]. All rights reserved.

#include <mylibrary/battleship.h>

#include <iostream>
#include <string>
#include <chrono>

namespace mylibrary {

Battleship::Battleship()
: ship_grid_arr_(),
  ship_a_{Ship("shipA", 3)},
  ship_b_{Ship("shipB", 2)},
  ship_c_{Ship("shipC", 3)}

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

  if (battle_grid_[row][col] == TileState::kHit) {
      return;
  }

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

void Battleship::PlaceShip() {
  std::string ship_name;
  int size_ship;

  ship_name = ship_a_.GetName();
  size_ship = ship_a_.GetSize();
  PlaceVShip(ship_name, size_ship);

  ship_name = ship_b_.GetName();
  size_ship = ship_b_.GetSize();
  PlaceVShip(ship_name, size_ship);

  ship_name = ship_c_.GetName();
  size_ship = ship_c_.GetSize();
  PlaceHShip(ship_name, size_ship);
}

void Battleship::PlaceHShip(const std::string& ship_name, int size_ship) {
  std::srand(time(0));
  for (int i = 0; i < 20; i++) {
    int rand_x, rand_y, x1, y1, x2, y2;
    rand_x = (rand() % (size_ship - 1)) + 1;
    rand_y = (rand() % 6) + 1;
    x1 = rand_x - 1;
    y1 = rand_y - 1;
    x2 = rand_x + size_ship;
    y2 = rand_y + 1;

    std::cout << " x " << rand_x << " y " << rand_y << "\n";

    bool does_have_ship = HasShip(x1, y1, x2, y2);
    if (!does_have_ship) {
      for (int x = rand_x; x < (rand_x + size_ship); x++) {
        std::cout << "assigned x " << x << " y " << rand_y << "\n";
        ship_grid_arr_[x][rand_y].has_ship_ = true;
        ship_grid_arr_[x][rand_y].ship_name_ = ship_name;
        std::cout<< "ship " << ship_name << "\n";
      }
      //so it doesn't keep on looking for a place to put the ship
      break;
    }
  }
}

void Battleship::PlaceVShip(const std::string& ship_name, int size_ship) {
  std::srand(time(0));
  for (int i = 0; i < 20; i++) {
    int rand_x, rand_y, x1, y1, x2, y2;
    rand_x = (rand() % 6) + 1;
    rand_y = (rand() % (size_ship - 1)) + 1;
    x1 = rand_x - 1;
    y1 = rand_y - 1;
    x2 = rand_x + 1;
    y2 = rand_y + size_ship;

    std::cout << " x " << rand_x << " y " << rand_y << "\n";

    bool does_have_ship = HasShip(x1, y1, x2, y2);
    if (!does_have_ship) {
      for (int y = rand_y; y < (rand_y + size_ship); y++) {
        std::cout << "assigned x " << rand_x << " y " << y << "\n";
        ship_grid_arr_[rand_x][y].has_ship_ = true;
        ship_grid_arr_[rand_x][y].ship_name_ = ship_name;
        std::cout<< "ship " << ship_name << "\n";
      }
      //so it doesn't keep on looking for a place to put the ship
      break;
    }
  }
}

bool Battleship::HasShip(int x1, int y1, int x2, int y2) {
  for (int x = x1; x <= x2; x++) {
    for (int y = y1; y <= y2; y++) {
      if (ship_grid_arr_[x][y].has_ship_) {
        return true;
      }
    }
  }
  return false;
}

bool Battleship::GetHasShip(int row, int col) {
  return ship_grid_arr_[row][col].has_ship_;
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
  /*
  ship_grid_arr_[2][2].has_ship_ = true;
  ship_grid_arr_[2][2].ship_name_ = ship_a_.GetName();
  //ship_grid_arr_[2][1].ship_obj_ = ship_a_;

  ship_grid_arr_[3][2].has_ship_ = true;
  ship_grid_arr_[3][2].ship_name_ = ship_a_.GetName();
  //ship_grid_arr_[3][1].ship_obj_ = ship_a_;

  ship_grid_arr_[4][2].has_ship_ = true;
  ship_grid_arr_[4][2].ship_name_ = ship_a_.GetName();
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
  ship_grid_arr_[6][6].ship_name_ = ship_c_.GetName();*/

}






}  // namespace mylibrary
