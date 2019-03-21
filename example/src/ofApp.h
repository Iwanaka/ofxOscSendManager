#pragma once

#include "ofMain.h"
#include "ofxOscSendManager.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyReleased(int key);
		
		ofxOscSendManager osc;
		ofxOscReceiver receiver;

};
