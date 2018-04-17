// =============================================================================
//
// Copyright (c) 2014-2016 Christopher Baker <http://christopherbaker.net>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
// =============================================================================


#include "ofApp.h"

void ofApp::setup() {
    std::cout << "~ ~ ~ cpp ~ ~ ~" << "\n";
    std::cout << "LLA home point: " << home_point[0] << " " << home_point[1] << " " << home_point[2] << "\n";
    std::cout << "+ XYZ offset: " << offset[0] << " " << offset[1] << " " << offset[2] << "\n";
    std::cout << "As LLA: ";
    xyzToLla(offset[0], offset[1], offset[2]);
    std::cout << "Back to XYZ: ";
    llaToXyz(home_point[0], home_point[1], home_point[2]);
    std::cout << "~ ~ ~ ~ ~ ~ ~ ~" << "\n";
}

void ofApp::draw() {
    ofBackgroundGradient(ofColor::white, ofColor::black);
    ofDrawBitmapStringHighlight("See console for output.", ofPoint(30, 30));
}

void ofApp::xyzToLla(double x, double y, double z) {
    GeographicLib::Geocentric earth(GeographicLib::Constants::WGS84_a(), GeographicLib::Constants::WGS84_f());
    GeographicLib::LocalCartesian proj(home_point[0], home_point[1], home_point[2], earth);
    double lat, lon, alt;
    proj.Reverse(x, y, z, lat, lon, alt);
    std::cout << lat << " " << lon << " " << alt << "\n";
}

void ofApp::llaToXyz(double lat, double lon, double alt) {
    GeographicLib::Geocentric earth(GeographicLib::Constants::WGS84_a(), GeographicLib::Constants::WGS84_f());
    GeographicLib::LocalCartesian proj(home_point[0], home_point[1], home_point[2], earth);
    double x, y, z;
    proj.Forward(lat, lon, alt, x, y, z);
    std::cout << x << " " << y << " " << z << "\n";
}



