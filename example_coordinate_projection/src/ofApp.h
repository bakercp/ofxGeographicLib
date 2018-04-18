//
// Copyright (c) 2018 Nick Fox-Gieg <http://fox-gieg.com>
//
// SPDX-License-Identifier:    MIT
//


#pragma once


#include "ofMain.h"
#include "ofxGeographicLib.h"


class ofApp: public ofBaseApp
{
public:
    void setup() override;
    void draw() override;

    std::vector<double> home_point = { 43.32, 73.21, 0.0 };
    std::vector<double> offset = { 0.03, -0.01, 0.0 };
    double scale = 1000.0;

};
