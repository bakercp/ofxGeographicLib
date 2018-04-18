//
// Copyright (c) 2014 Christopher Baker <https://christopherbaker.net>
//
// SPDX-License-Identifier:    MIT
//


#include "ofApp.h"


void ofApp::setup()
{
    try
    {
        // Miscellaneous conversions
        GeographicLib::GeoCoords c(33.3, 44.4);
        std::cout << c.MGRSRepresentation(-3) << std::endl;
        c.Reset("18TWN0050");
        std::cout << c.DMSRepresentation() << std::endl;
        std::cout << c.Latitude() << " " << c.Longitude() << std::endl;
        c.Reset("1d38'W 55d30'N");
        std::cout << c.GeoRepresentation() << std::endl;
        std::cout << c.UTMUPSRepresentation() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

}


void ofApp::draw()
{
    ofBackgroundGradient(ofColor::white, ofColor::black);
    ofDrawBitmapStringHighlight("See console for output.", ofPoint(30, 30));
}
