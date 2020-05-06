// Copyright (c) 2020 CS126SP20. All rights reserved.

#ifndef FINALPROJECT_APPS_MYAPP_H_
#define FINALPROJECT_APPS_MYAPP_H_

#include <cinder/app/App.h>
#include <cinder/gl/gl.h>
#include <mylibrary/battleship.h>
#include <mylibrary/tilestate.h>
#include <vector>

namespace myapp {

const int kGridSize = 7;
const int kTileSize = 80;

class MyApp : public cinder::app::App {
 private:
  char tile_x_char_, tile_y_char_;
  int key_counter_;
  int x_coord_;
  int y_coord_;
  cinder::gl::Texture2dRef mTex;
  bool is_game_over_;
  bool printed_game_over_;
  bool reveal_key;
  size_t game_time_;
  std::string game_time_str_;
  std::chrono::time_point<std::chrono::system_clock> start_time_;
  std::chrono::time_point<std::chrono::system_clock> end_time_;
 public:
  MyApp();
  void setup() override;
  void update() override;
  void draw() override;
  void keyDown(cinder::app::KeyEvent) override;
  void DrawTiles();
  static void DrawLabels();
  void GameOver();
  };

}  // namespace myapp

#endif  // FINALPROJECT_APPS_MYAPP_H_
