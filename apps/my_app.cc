// Copyright (c) 2020 [Alekhya Vakkalagadda]. All rights reserved.

#include "my_app.h"

#include <cinder/app/App.h>
#include <rph/NotificationManager.h>

#include <mylibrary/battleship.h>


namespace myapp {

mylibrary::Battleship engine;

using cinder::app::KeyEvent;
    using cinder::Rectf;

MyApp::MyApp() { }

void MyApp::setup() {
  key_counter = 0;
  engine.InitializeGrid();
  engine.InitializeShipGrid();
  rph::NotificationManager::getInstance()->add("Hello, World!", 5);
}

void MyApp::update() { }

void MyApp::draw() {
  cinder::gl::clear();
  rph::NotificationManager::getInstance()->draw();

  DrawTiles();

/*  cinder::gl::color(0, 1, 0);
    cinder::gl::drawSolidRect(Rectf(500,500,650,650));

    if (tile_ == 97) {
      //TODO keep this info in a data structure so the tile color will stay the same (a class or array)
      cinder::gl::color(0.2, 0.3, 0);
      cinder::gl::drawSolidRect(Rectf(500,500,650,650));
    }*/
}

void MyApp::keyDown(KeyEvent event) {
  std::string tile_str;

  if (key_counter == 0) {
    tile_x_char = event.getChar();
    x_coord_ = (int) tile_x_char - 96;;
    if (x_coord_ >=1 && x_coord_ <= 4) {
      key_counter++;
    } else {
      rph::NotificationManager::getInstance()->add("not a valid letter key", 5);
    }
  } else if (key_counter == 1) {
    tile_y_char = event.getChar();
    y_coord_ = (int) tile_y_char - 48;
    if (y_coord_ >=1 && y_coord_ <= 4) {
      tile_str.push_back(tile_x_char);
      tile_str.push_back(tile_y_char);
      engine.SetGridItem(x_coord_, y_coord_);
      rph::NotificationManager::getInstance()->add("Keys " + tile_str + " was pressed", 5);
      key_counter = 0;
    } else {
      rph::NotificationManager::getInstance()->add("not a valid number key", 5);
    }
  }
}

void MyApp::DrawTiles() {
  int tile_size = 70;
  //to provide space between each tile
  int space = 5;
  int x1, y1, x2, y2;

  //TODO make numbers constant
  for (int x = 1; x < 5; x++) {
    for (int y = 1; y < 5; y++) {
      x1 = x * tile_size + space;
      y1 = y * tile_size + space;
      x2 = x1 + tile_size - space;
      y2 = y1 + tile_size - space;
      if (engine.GetGridItem(x, y) == mylibrary::TileState::kHit) {
        // TODO this isn't working
        cinder::gl::color(0, 0, 1);
        cinder::gl::drawSolidRect(Rectf(x1, y1, x2, y2));
      } else if (engine.GetGridItem(x, y) == mylibrary::TileState::kMiss) {
        cinder::gl::color(1, 0, 0);
        cinder::gl::drawSolidRect(Rectf(x1, y1, x2, y2));
      } else {
        cinder::gl::color(0, 1, 0);
        cinder::gl::drawSolidRect(Rectf(x1, y1, x2, y2));
      }
    }
  }
}


}  // namespace myapp
