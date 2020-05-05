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

MyApp::MyApp() { }

//TODO create a constructor
void MyApp::setup() {
  auto img = loadImage( loadAsset( "ship_image.jpg" ) );
  mTex = cinder::gl::Texture2d::create(img);

  key_counter_ = 0;
  engine.InitializeGrid();
  engine.InitializeShipGrid();
  engine.PlaceShip();
  is_game_over_ = false;
  printed_game_over_ = false;
  rph::NotificationManager::getInstance()->add("Hello, World!", 2);
}

void MyApp::update() {
  GameOver();
  if (is_game_over_) {
    std::cout<< "update --> game is over" << "\n";
    return;
  }
}

void MyApp::draw() {

  if (is_game_over_) {
    if (!printed_game_over_) cinder::gl::clear(Color(0, 0, 0));
    std::cout<< "draw --> game is over" << "\n";

    const Color color1 = {0, 1, 1};
    const std::string text = " Game Over! ";
    const cinder::vec2 loc1 = {375, 325};
    cinder::gl::drawStringCentered(text, loc1, color1, cinder::Font(kNormalFont, 75));

    return;
  }

  cinder::gl::clear();

  rph::NotificationManager::getInstance()->draw();

  DrawLabels();
  DrawTiles();
}

void MyApp::keyDown(KeyEvent event) {
  std::string tile_str;

  if (key_counter_ == 0) {
    tile_x_char_ = event.getChar();
    x_coord_ = (int) tile_x_char_ - 96;
    if (x_coord_ >= 1 && x_coord_ <= 6) {
      key_counter_++;
    } else {
      rph::NotificationManager::getInstance()->add("not a valid letter key", 2);
    }
  } else if (key_counter_ == 1) {
    tile_y_char_ = event.getChar();
    y_coord_ = (int) tile_y_char_ - 48;
    if (y_coord_ >=1 && y_coord_ <= 6) {
      tile_str.push_back(tile_x_char_);
      tile_str.push_back(tile_y_char_);
      engine.SetGridItem(x_coord_, y_coord_);
      rph::NotificationManager::getInstance()->add("Keys " + tile_str + " was pressed", 2);
      key_counter_ = 0;
    } else {
      rph::NotificationManager::getInstance()->add("not a valid number key", 2);
    }
  }
}

void MyApp::DrawTiles() {
  int tile_size = 80;
  //to provide space between each tile
  int space = 7;
  int x1, y1, x2, y2;
  //float cx, cy;

  //TODO make numbers constant
  for (int x = 1; x < 7; x++) {
    for (int y = 1; y < 7; y++) {
      x1 = x * tile_size + space;
      y1 = y * tile_size + space;
      x2 = x1 + tile_size - space;
      y2 = y1 + tile_size - space;
      //cx = (x1 + x2) / 2;
      //cy = (y1 + y2) / 2;
      if (engine.GetGridItem(x, y) == mylibrary::TileState::kHit) {
        cinder::gl::color(1, 0, 1);
        //const cinder::vec2 center = {cx, cy};
        //cinder::gl::drawStrokedCircle(center, 25.0, 4, -1);
        cinder::gl::drawStrokedRect(Rectf(x1, y1, x2, y2), 3);
      } else if (engine.GetGridItem(x, y) == mylibrary::TileState::kMiss) {
        cinder::gl::color(0, 0, 1);
        cinder::gl::drawSolidRect(Rectf(x1, y1, x2, y2));
      } else if (engine.GetGridItem(x, y) == mylibrary::TileState::kSink) {
        cinder::gl::color(1, 0, 1);
        cinder::gl::drawSolidRect(Rectf(x1, y1, x2, y2));
      } else if (engine.GetHasShip(x, y)) {
        cinder::gl::color(1, 1, 1);
        cinder::gl::draw(mTex, Rectf(x1, y1, x2, y2));
      } else {
        cinder::gl::color(0, 1, 0);
        cinder::gl::drawSolidRect(Rectf(x1, y1, x2, y2));
      }
    }
  }
}

void MyApp::GameOver() {
  if (printed_game_over_) return;
  for (int row = 1; row < 7; row++) {
    for (int col = 1; col < 7; col++) {
      if (engine.GetHasShip(row, col)) {
        if (!(engine.GetGridItem(row, col) == mylibrary::TileState::kSink)) {
          is_game_over_ = false;
          return;
        }
      }
    }
  }
  is_game_over_ = true;
}

void MyApp::DrawLabels() {
  // test printing labels
  int tile_size = 80;
  int x, y;
  x = 120;
  y = 45;
  const Color color1 = {0, 1, 0};

  for (int i = 0; i < 6; i++) {
    int ascii_val = 65 + i;
    char ascii_char = (char) (ascii_val);
    std::string text(1, ascii_char);
    //const std::string text1 = " A ";
    if (i == 0) {
      const cinder::vec2 loc1 = {x, y};
      cinder::gl::drawStringCentered(text, loc1, color1, cinder::Font(kNormalFont, 30));
    } else {
      const cinder::vec2 loc1 = {x += (tile_size), y};
      cinder::gl::drawStringCentered(text, loc1, color1, cinder::Font(kNormalFont, 30));
    }
  }

  x = 45;
  y = 115;

  for (int j = 0; j < 6; j++) {
    std::string text = std::to_string(j + 1);
    if (j == 0) {
      const cinder::vec2 loc1 = {x, y};
      cinder::gl::drawStringCentered(text, loc1, color1, cinder::Font(kNormalFont, 30));
    } else {
      const cinder::vec2 loc1 = {x, y += (tile_size)};
      cinder::gl::drawStringCentered(text, loc1, color1, cinder::Font(kNormalFont, 30));
    }
  }

}


}  // namespace myapp
