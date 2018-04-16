#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofBackground(39);
	ofSetWindowTitle("Insta");

	ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	for (int y = 0; y <= ofGetHeight(); y += 10) {

		ofColor line_color;
		line_color.setHsb(ofMap(y, 0, ofGetHeight(), 0, 255), 192, 192);
		ofSetColor(line_color);

		ofPoint prev_point = ofPoint(-1, y);
		float noise_value = 0;
		for (int x = 0; x < ofGetWidth(); x += 1) {

			float range = ofMap(ofPoint(ofGetWidth() / 2, y).distance(ofPoint(x, y)), 0, ofGetWidth() * 0.35, 100, 0);
			if (range < 0) {

				range = 0;
			}
			noise_value = ofMap(ofNoise(x * 0.005 - ofGetFrameNum() * 0.01, y * 0.01), 0, 1, -range, range);
			ofPoint point(x, y + noise_value);

			ofDrawLine(prev_point, point);
			prev_point = point;
		}
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}