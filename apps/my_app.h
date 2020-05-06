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
const int kTurnsToWin = 15;

class MyApp : public cinder::app::App {
 private:
  //keys pressed by user
  char tile_x_char_, tile_y_char_;

  //counter for a ship
  int key_counter_;

  //x and y coords that the user entered
  int x_coord_, y_coord_;

  //number of turns user takes
  int num_turns_;

  //ship images
  cinder::gl::Texture2dRef ship_img;

  //is the game over
  bool is_game_over_;

  //if the user won
  bool won_game_;

  //the printed game over screen
  bool printed_game_over_;

  //key to reveal and hide ships
  bool reveal_key;

  //time taken to play
  size_t game_time_;

  //time take to play in string
  std::string game_time_str_;

  //start time when starting the game
  std::chrono::time_point<std::chrono::system_clock> start_time_;

  //end time when finishing the game
  std::chrono::time_point<std::chrono::system_clock> end_time_;
 public:
  /**
   * Default Constructor
   */
  MyApp();

  void setup() override;
  void update() override;
  void draw() override;
  void keyDown(cinder::app::KeyEvent) override;

  /**
   * Draws the tiles on the GUI
   */
  void DrawTiles();

  /**
   * Draws the x and y coordinates on the GUI
   */
  static void DrawLabels();

  /**
   * Checks to see if the game is over
   */
  void GameOver();
  };

}  // namespace myapp

#endif  // FINALPROJECT_APPS_MYAPP_H_
