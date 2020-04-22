// Copyright (c) 2020 [Your Name]. All rights reserved.

#include "my_app.h"

#include <cinder/app/App.h>
#include <rph/NotificationManager.h>


namespace myapp {

using cinder::app::KeyEvent;
    using cinder::Rectf;


MyApp::MyApp() { }

void MyApp::setup() {
  rph::NotificationManager::getInstance()->add("Hello, World!", 5);
}

void MyApp::update() { }

void MyApp::draw() {
  cinder::gl::clear();
  rph::NotificationManager::getInstance()->draw();

    cinder::gl::color(0, 1, 0);
    cinder::gl::drawSolidRect(Rectf(500,500,650,650));

    DrawTiles();

    if (tile_ == 97) {
      //TODO keep this info in a data structure so the tile color will stay the same (a class or array)
      cinder::gl::color(0.2, 0.3, 0);
      cinder::gl::drawSolidRect(Rectf(500,500,650,650));
    }
}

void MyApp::keyDown(KeyEvent event) {
  //TODO create global var that has getCode and use it in draw function to update color
  tile_ = event.getCode();
  switch (event.getCode()) {
    case KeyEvent::KEY_a: {
      rph::NotificationManager::getInstance()->add("Key 'A' was pressed", 5);
      break;
    }
  }
}

void MyApp::DrawTiles() {
  int tile_size = 40;
  //to provide space between each tile
  int space = 5;
  int x1, y1, x2, y2;

  for (int x = 1; x < 5; x++) {
    for (int y = 1; y < 5; y++) {
      x1 = x * tile_size + space;
      y1 = y * tile_size + space;
      x2 = x1 + tile_size - space;
      y2 = y1 + tile_size - space;
      cinder::gl::color(0, 1, 0);
      cinder::gl::drawSolidRect(Rectf(x1, y1, x2, y2));
    }
  }
}


}  // namespace myapp
