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
    cinder::gl::drawSolidRect(Rectf(10,10,50,50));

    cinder::gl::color(1, 0, 0);
    cinder::gl::drawSolidRect(Rectf(50,10,90,50));
}

void MyApp::keyDown(KeyEvent event) { }

}  // namespace myapp
