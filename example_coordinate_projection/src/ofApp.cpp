//
// Copyright (c) 2018 Nick Fox-Gieg <http://fox-gieg.com>
//
// SPDX-License-Identifier:    MIT
//


#include "ofApp.h"


void ofApp::setup()
{
    GeographicLib::Geocentric earth(GeographicLib::Constants::WGS84_a(),
                                    GeographicLib::Constants::WGS84_f());
    
    GeographicLib::LocalCartesian proj(home_point[0],
                                       home_point[1],
                                       home_point[2],
                                       earth);
    
    // Get the reverse-projected latitutde, longitude and altitude.
    double lat, lon, alt;
    
    proj.Reverse(offset[0] * scale,
                 offset[1] * scale,
                 offset[2] * scale,
                 lat,
                 lon,
                 alt);

    glm::dvec3 p;
    proj.Forward(lat, lon, alt, p.x, p.y, p.z);
    p /= scale;
    
    std::cout << "~ ~ ~ cpp ~ ~ ~" << std::endl;
    std::cout << "LLA home point: " << home_point[0] << " " << home_point[1] << " " << home_point[2] << std::endl;
    std::cout << "+ XYZ offset: " << offset[0] << " " << offset[1] << " " << offset[2] << std::endl;
    std::cout << " . . . . . . . ." << std::endl;
    std::cout << "As LLA: " << lat << " " << lon << " " << alt << std::endl;
    std::cout << "Back to XYZ: " << ofToString(p) << std::endl;
    std::cout << "~ ~ ~ ~ ~ ~ ~ ~" << std::endl;
}


void ofApp::draw()
{
    ofBackgroundGradient(ofColor::white, ofColor::black);
    ofDrawBitmapStringHighlight("See console for output.", ofPoint(30, 30));
}





