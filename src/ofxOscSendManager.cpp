#include "ofxOscSendManager.h"

//--------------------------------------------------------------
ofxOscSendManager::ofxOscSendManager()
{}

//--------------------------------------------------------------
ofxOscSendManager::~ofxOscSendManager()
{}

//--------------------------------------------------------------
void ofxOscSendManager::addDelayMsg(string msg,uint64_t delayMillSecound) {

	messageCore m;
	m.message = msg;
	m.delayMillSecound = delayMillSecound;

	addDelayMsg(m);

}

//--------------------------------------------------------------
void ofxOscSendManager::addDelayMsg(const messageCore& core) {

	msg m;
	m.core = core;
	m.isSend = false;
	m.m = ofGetElapsedTimeMillis();

	messages.push_back(m);

}

//--------------------------------------------------------------
void ofxOscSendManager::sendMsg(string msg) {

	parent.sendMsg(msg);

}

//--------------------------------------------------------------
void ofxOscSendManager::update() {

	uint64_t t = ofGetElapsedTimeMillis();

	for (int i = 0; i < messages.size(); i++) {

		float diff = t - messages[i].m;

		if (messages[i].isSend) continue;
		if (diff <= messages[i].core.delayMillSecound) continue;

		parent.sendMsg(messages[i].core.message);

		messages[i].isSend = true;
	}

}

//--------------------------------------------------------------
void ofxOscSendManager::clearWaitArgs() {

	messages.clear();

}