// Copyright (c) 2020 CS126SP20. All rights reserved.

#ifndef FINALPROJECT_APPS_MYAPP_H_
#define FINALPROJECT_APPS_MYAPP_H_

#include <cinder/app/App.h>
#include <mylibrary/battleship.h>
#include <mylibrary/tilestate.h>

namespace myapp {

class MyApp : public cinder::app::App {
 private:
  char tile_x_char, tile_y_char;
  int tile_;
  int key_counter;
  int x_coord_;
  int y_coord_;
  void DrawTiles();
 public:
  MyApp();
  void setup() override;
  void update() override;
  void draw() override;
  void keyDown(cinder::app::KeyEvent) override;
};

}  // namespace myapp

#endif  // FINALPROJECT_APPS_MYAPP_H_
