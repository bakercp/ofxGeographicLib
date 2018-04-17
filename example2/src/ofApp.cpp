#include "ofApp.h"

void ofApp::setup() {
    GeographicLib::Geocentric earth(GeographicLib::Constants::WGS84_a(), GeographicLib::Constants::WGS84_f());
    GeographicLib::LocalCartesian proj(home_point[0], home_point[1], home_point[2], earth);
    
    double lat, lon, alt;
    proj.Reverse(offset[0] * scale, offset[1] * scale, offset[2] * scale, lat, lon, alt);

    double x, y, z;
    proj.Forward(lat, lon, alt, x, y, z);
    x /= scale;
    y /= scale;
    z /= scale;

    std::cout << "~ ~ ~ cpp ~ ~ ~" << "\n";
    std::cout << "LLA home point: " << home_point[0] << " " << home_point[1] << " " << home_point[2] << "\n";
    std::cout << "+ XYZ offset: " << offset[0] << " " << offset[1] << " " << offset[2] << "\n";
    std::cout << " . . . . . . . ." << "\n";
    std::cout << "As LLA: " << lat << " " << lon << " " << alt << "\n";
    std::cout << "Back to XYZ: " << x << " " << y << " " << z << "\n";
    std::cout << "~ ~ ~ ~ ~ ~ ~ ~" << "\n";
}

void ofApp::draw() {
    ofBackgroundGradient(ofColor::white, ofColor::black);
    ofDrawBitmapStringHighlight("See console for output.", ofPoint(30, 30));
}





