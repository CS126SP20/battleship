// Copyright (c) 2020 [Alekhya Vakkalagadda]. All rights reserved.

#include <cinder/app/App.h>
#include <cinder/app/RendererGl.h>
#include <gflags/gflags.h>
#include <vector>

#include "my_app.h"


using cinder::app::App;
using cinder::app::RendererGl;
using std::string;
using std::vector;


namespace myapp {

const int kSamples = 8;
const int kWidth = 800;
const int kHeight = 800;

void ParseArgs(vector<string>* args) {
  gflags::SetUsageMessage(
      "Play a game of Battleship. Pass --helpshort for options.");
  int argc = static_cast<int>(args->size());

  vector<char*> argvs;
  for (string& str : *args) {
    argvs.push_back(&str[0]);
  }

  char** argv = argvs.data();
  gflags::ParseCommandLineFlags(&argc, &argv, true);
}


void SetUp(App::Settings* settings) {
  vector<string> args = settings->getCommandLineArgs();
  ParseArgs(&args);

  settings->setWindowSize(kWidth, kHeight);
  settings->setTitle("My CS 126 Application");
}

}  // namespace myapp


// This is a macro that runs the application.
CINDER_APP(myapp::MyApp,
           RendererGl(RendererGl::Options().msaa(myapp::kSamples)),
           myapp::SetUp)
