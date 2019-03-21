#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	ofBackground(0);

	//set key address and destination
	osc.parent.AddRoute("/A", ofxOscFamily::newChild("127.0.0.1", 10000));
	osc.parent.AddRoute("/B", ofxOscFamily::newChild("127.0.0.1", 10000));
	osc.parent.AddRoute("/C", ofxOscFamily::newChild("127.0.0.1", 10000));
	osc.parent.AddRoute("/hoge", ofxOscFamily::newChild("127.0.0.1", 10000));


	receiver.setup(10000);

}

//--------------------------------------------------------------
void ofApp::update(){
	
	osc.update();

	while (receiver.hasWaitingMessages()) {

		ofxOscMessage m;
		if (!receiver.getNextMessage(m)) return;

		size_t t = m.getNumArgs();
		string address = m.getAddress();

		cout << "from : " << m.getRemoteIp() << endl;
		cout << address << endl;
		for (int i = 0; i < t; i++) {
			cout << m.getArgAsString(i) << endl;
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){

	ofSetColor(255);
	ofDrawBitmapString("please see console", 20, 20);

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

	if (key == 'a') osc.addDelayMsg(ofxOscFamily::newCore("/A Hello A", 1000));
	if (key == 'b') osc.addDelayMsg("/B Hello B", 2000);
	
	if (key == 'c') {
		ofxOscFamily::messageCore m;
		m.delayMillSecound = 3000;
		m.message = "/C Hello C";
		osc.addDelayMsg(m);
	}

	if (key == ' ') osc.sendMsg("/hoge hogehoge hogehogehoge hogehogehogehoge");

}