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
  tile_ = event.getCode();
  char tile_char = event.getChar();
  switch (event.getCode()) {
    case KeyEvent::KEY_a: {
      x_coord_ = 1;
      y_coord_ = 3;
      engine.SetGridItem(x_coord_, y_coord_, tile_char);
      rph::NotificationManager::getInstance()->add("Key 'A' was pressed", 5);
      break;
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
        //TODO this isn't working
        cinder::gl::color(0, 0, 1);
        cinder::gl::drawSolidRect(Rectf(x1, y1, x2, y2));
      } else {
        cinder::gl::color(0, 1, 0);
        cinder::gl::drawSolidRect(Rectf(x1, y1, x2, y2));
      }
    }
  }
}


}  // namespace myapp
