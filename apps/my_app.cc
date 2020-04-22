// Copyright (c) 2020 [Your Name]. All rights reserved.

#include "my_app.h"

#include <cinder/app/App.h>
#include <rph/NotificationManager.h>


namespace myapp {

using cinder::app::KeyEvent;

MyApp::MyApp() { }

void MyApp::setup() {
  rph::NotificationManager::getInstance()->add("Hello, World!", 10);
}

void MyApp::update() { }

void MyApp::draw() {
  cinder::gl::clear();
  rph::NotificationManager::getInstance()->draw();
}

void MyApp::keyDown(KeyEvent event) { }

}  // namespace myapp
