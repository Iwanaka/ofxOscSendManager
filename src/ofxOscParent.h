#pragma once
#include "ofxOsc.h"

using namespace std;
namespace ofxOscFamily {

	typedef shared_ptr<ofxOscSender> ofxOscBaby;
	typedef shared_ptr<vector<string>> ofxOscHousehold;
	typedef struct
	{
		string message;
		long delayMillSecound;
	} messageCore;

	typedef struct
	{
		string address;
		ofxOscBaby baby;
	} child;

	ofxOscBaby newChild(string host, int port);
	messageCore newCore(string message, long delayMillSecound);

	class ofxOscParent
	{
	public:

		ofxOscParent();
		~ofxOscParent();
		
		void AddRoute(string address, const ofxOscBaby &baby);
		void AddRoute(const child &_child);

		void sendMsg(const string &msg);

		void checkHouseHold(const ofxOscHousehold &household);

	private:

		vector<child> childlen;
		ofxOscHousehold household;

	};
}