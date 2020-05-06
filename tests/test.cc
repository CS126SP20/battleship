// Copyright (c) 2020 CS126SP20. All rights reserved.

#define CATCH_CONFIG_MAIN

#include <cinder/app/App.h>
#include <mylibrary/battleship.h>
#include <mylibrary/ship.h>

#include <catch2/catch.hpp>


// Ship Class
TEST_CASE("Ship Get Size", "[ship class]") {
  SECTION("Ship A") {
    mylibrary::Ship ship_a("ship A", 3);
    int ship_size_a = ship_a.GetSize();
    REQUIRE(3 == ship_size_a);
  }

  SECTION("Ship B") {
    mylibrary::Ship ship_b("ship B", 18);
    int ship_size_b = ship_b.GetSize();
    REQUIRE(18 == ship_size_b);
  }
}

TEST_CASE("Ship Get Name", "[ship class]") {
  SECTION("Ship A") {
    mylibrary::Ship ship_a("ship A", 3);
    std::string ship_size_a = ship_a.GetName();
    REQUIRE("ship A" == ship_size_a);
  }

  SECTION("Ship B") {
    mylibrary::Ship ship_b("ship B", 18);
    std::string ship_size_b = ship_b.GetName();
    REQUIRE("ship B" == ship_size_b);
  }
}

TEST_CASE("Ship Get Counter", "[ship class]") {
  SECTION("Ship A") {
    mylibrary::Ship ship_a("ship A", 3);
    int ship_size_a = ship_a.GetCounter();
    REQUIRE(3 == ship_size_a);
  }

  SECTION("Ship B") {
    mylibrary::Ship ship_b("ship B", 18);
    int ship_size_b = ship_b.GetCounter();
    REQUIRE(18 == ship_size_b);
  }
}

//Battleship Class
TEST_CASE("Set & Get Has Ship", "[battleship class]") {
  mylibrary::Battleship engine;
  engine.InitializeShipGrid();
  engine.SetHasShip(2, 3);
  bool has_ship = engine.GetHasShip(2, 3);
  REQUIRE(has_ship);
}