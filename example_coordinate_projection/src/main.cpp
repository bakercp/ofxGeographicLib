//
// Copyright (c) 2018 Nick Fox-Gieg <http://fox-gieg.com>
//
// SPDX-License-Identifier:    MIT
//


#include "ofApp.h"


int main()
{
    ofSetupOpenGL(250, 50, OF_WINDOW);
    return ofRunApp(std::make_shared<ofApp>());
}

