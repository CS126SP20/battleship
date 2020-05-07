// Copyright (c) 2020 [Alekhya Vakkalagadda]. All rights reserved.

#include "my_app.h"
#include <cinder/app/App.h>
#include <rph/NotificationManager.h>
#include <cinder/Vector.h>
#include <cinder/gl/gl.h>
#include <cinder/gl/draw.h>
#include <cinder/Font.h>
#include <cinder/Text.h>

using cinder::TextBox;
using cinder::Color;
using cinder::ColorA;
using cinder::Rectf;
using std::chrono::system_clock;
using std::chrono::duration_cast;
using std::chrono::seconds;

#if defined(CINDER_COCOA_TOUCH)
const char kNormalFont[] = "Arial";
const char kBoldFont[] = "Arial-BoldMT";
const char kDifferentFont[] = "AmericanTypewriter";
#elif defined(CINDER_LINUX)
const char kNormalFont[] = "Arial Unicode MS";
const char kBoldFont[] = "Arial Unicode MS";
const char kDifferentFont[] = "Purisa";
#else
const char kNormalFont[] = "Arial";
const char kBoldFont[] = "Arial Bold";
const char kDifferentFont[] = "Papyrus";
#endif

namespace myapp {

mylibrary::Battleship engine;

using cinder::app::KeyEvent;
using cinder::Rectf;

MyApp::MyApp()
  : tile_x_char_{'0'},
    tile_y_char_ {'0'},
    key_counter_ {0},
    x_coord_{0},
    y_coord_{0},
    won_game_{true},
    num_turns_{0},
    is_game_over_{false},
    printed_game_over_{false},
    reveal_key{false},
    game_time_str_{""} {}

void MyApp::setup() {
  auto img1 = loadImage( loadAsset( "ship_image.jpg" ) );
  ship_img = cinder::gl::Texture2d::create(img1);

  auto img2 = loadImage( loadAsset( "boom.png" ) );
  ship_hit = cinder::gl::Texture2d::create(img2);

  auto img3 = loadImage( loadAsset( "sink-ship.jpg" ) );
  ship_sink = cinder::gl::Texture2d::create(img3);

  key_counter_ = 0;
  engine.InitializeGrid();
  engine.InitializeShipGrid();
  engine.PlaceShip();
  reveal_key = false;
  is_game_over_ = false;
  printed_game_over_ = false;
  const cinder::vec2 loc1 = {375, 325};
  rph::NotificationManager::getInstance()->add("Welcome to Battleship!",
      2);
  start_time_ = system_clock::now();
}

void MyApp::update() {
  //calculates total time
  if (is_game_over_) {
    const auto my_game_time = end_time_ - start_time_;
    const auto total_time = duration_cast<seconds>(my_game_time);
    game_time_ = static_cast<size_t>(total_time.count());
    game_time_str_ = std::to_string(game_time_);
    return;
  }
  GameOver();
}

void MyApp::draw() {
  std::string text;
  std::string text_turns;

  //if the game is over
  if (is_game_over_) {
    if (!printed_game_over_) {
      cinder::gl::clear(Color(0, 0, 0));
    }
    if (!won_game_) {
      text = " You Lost! \n Total Time Taken: ";
    } else {
      text = " You Won! \n Total Time Taken: ";
    }

    //show the ships at the end of the game by redrawing the tiles and labels
    reveal_key = true;
    DrawTiles();
    DrawLabels();
    text_turns = std::to_string(num_turns_);
    const Color color1 = {0, 1, 1};
    const std::string text1 = text + game_time_str_
                              + " sec \n Number of Turns: " + text_turns;
    const cinder::vec2 loc1 = {450, 600};
    cinder::gl::drawStringCentered(text1, loc1, color1,
                                   cinder::Font(kNormalFont, 40));
     return;
  }

  cinder::gl::clear();
  //draws notifications, labels, and tiles
  rph::NotificationManager::getInstance()->draw();
  DrawLabels();
  DrawTiles();
}

void MyApp::keyDown(KeyEvent event) {
  std::string tile_str;

  //checks to see if the key was a reveal/hide key
  if (event.getCode() == KeyEvent::KEY_UP) {
    reveal_key = true;
    rph::NotificationManager::
    getInstance()->add("Now revealing the ships", 2);
  } else if (event.getCode() == KeyEvent::KEY_DOWN) {
    reveal_key = false;
    rph::NotificationManager::
    getInstance()->add("Now hiding the ships", 2);
  } else if (key_counter_ == 0) {   //keeps track of number of keys pressed
    tile_x_char_ = event.getChar();
    x_coord_ = (int) tile_x_char_ - 96;
    if (x_coord_ >= 1 && x_coord_ <= (kGridSize - 1)) {
      //gets the first key
      key_counter_++;
    } else {
      //checks if a valid key is pressed
      rph::NotificationManager::
      getInstance()->add("not a valid letter key", 2);
    }
  } else if (key_counter_ == 1) {
    //gets the second key
    tile_y_char_ = event.getChar();
    y_coord_ = (int) tile_y_char_ - 48;
    if (y_coord_ >=1 && y_coord_ <= (kGridSize - 1)) {
      //num of turns user is taking
      num_turns_++;
      tile_str.push_back(tile_x_char_);
      tile_str.push_back(tile_y_char_);
      engine.SetGridItem(x_coord_, y_coord_);
      rph::NotificationManager::
      getInstance()->add("Keys " + tile_str + " was pressed", 2);
      key_counter_ = 0;

      //checks to see how many turns the user is taking
      if (num_turns_ > kTurnsToWin) {
        won_game_ = false;
        return;
      }

    } else {
      //checks if a valid key is pressed
      rph::NotificationManager::
      getInstance()->add("not a valid number key", 2);
    }
  }
}

void MyApp::DrawLabels() {
  int x, y;
  const Color color1 = {1, 0, 1};

  x = 120;
  y = 45;
  //draws x coordinates
  for (int i = 0; i < (kGridSize - 1); i++) {
    int ascii_val = 65 + i;
    char ascii_char = (char) (ascii_val);
    std::string text(1, ascii_char);
    if (i == 0) {
      const cinder::vec2 loc1 = {x, y};
      cinder::gl::drawStringCentered(text, loc1, color1,
                                     cinder::Font(kNormalFont, 30));
    } else {
      const cinder::vec2 loc1 = {x += (kTileSize), y};
      cinder::gl::drawStringCentered(text, loc1, color1,
                                     cinder::Font(kNormalFont, 30));
    }
  }

  x = 45;
  y = 115;
  //draws y coordinates
  for (int j = 0; j < (kGridSize - 1); j++) {
    std::string text = std::to_string(j + 1);
    if (j == 0) {
      const cinder::vec2 loc1 = {x, y};
      cinder::gl::drawStringCentered(text, loc1, color1,
                                     cinder::Font(kNormalFont, 30));
    } else {
      const cinder::vec2 loc1 = {x, y += (kTileSize)};
      cinder::gl::drawStringCentered(text, loc1, color1,
                                     cinder::Font(kNormalFont, 30));
    }
  }

}

void MyApp::DrawTiles() {
  //to provide space between each tile
  int space = kGridSize;
  int x1, y1, x2, y2;

  for (int x = 1; x < kGridSize; x++) {
    for (int y = 1; y < kGridSize; y++) {
      x1 = x * kTileSize + space;
      y1 = y * kTileSize + space;
      x2 = x1 + kTileSize - space;
      y2 = y1 + kTileSize - space;

      //checks to see the tile state of the tile
      if (engine.GetGridItem(x, y) == mylibrary::TileState::kHit) {
        cinder::gl::color(1, 1, 1);
        cinder::gl::draw(ship_hit, Rectf(x1, y1, x2, y2));
      } else if (engine.GetGridItem(x, y) == mylibrary::TileState::kMiss) {
        cinder::gl::color(0, 0, 1);
        cinder::gl::drawSolidRect(Rectf(x1, y1, x2, y2));
      } else if (engine.GetGridItem(x, y) == mylibrary::TileState::kSink) {
        cinder::gl::color(1, 1, 1);
        cinder::gl::draw(ship_sink, Rectf(x1, y1, x2, y2));
      } else if (engine.GetHasShip(x, y) && reveal_key) {   //reveals ships
        cinder::gl::color(1, 1, 1);
        cinder::gl::draw(ship_img, Rectf(x1, y1, x2, y2));
      } else {
        //tiles at empty state in the beginning
        cinder::gl::color(1, 0, 1);
        cinder::gl::drawSolidRect(Rectf(x1, y1, x2, y2));
      }
    }
  }
}

void MyApp::GameOver() {
  if (printed_game_over_) return;

  if (!won_game_) {
    is_game_over_ = true;
    end_time_ = system_clock::now();
    return;
  }

  for (int row = 1; row < kGridSize; row++) {
    for (int col = 1; col < kGridSize; col++) {
      if (engine.GetHasShip(row, col)) {
        if (!(engine.GetGridItem(row, col) == mylibrary::TileState::kSink)) {
          is_game_over_ = false;
          return;
        }
      }
    }
  }
  is_game_over_ = true;
  end_time_ = system_clock::now();
}

}  // namespace myapp
