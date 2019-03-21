#pragma once
#include "ofxOscParent.h"


using namespace ofxOscFamily; 
class ofxOscSendManager
{
public:
	ofxOscSendManager();
	~ofxOscSendManager();

	void addDelayMsg(string msg, uint64_t delayMillSecound);
	void addDelayMsg(const messageCore& core);
	void sendMsg(string msg);
	void update();
	void clearWaitArgs();

	ofxOscParent parent;

private:

	typedef struct {

		uint64_t m = 0;
		bool isSend = false;
		messageCore core;

	} msg;
	vector<msg> messages;

};
