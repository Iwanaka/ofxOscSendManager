#include "ofxOscParent.h"

using namespace ofxOscFamily;
//--------------------------------------------------------------
ofxOscBaby ofxOscFamily::newChild(string host, int port)
{
	ofxOscBaby baby = make_shared<ofxOscSender>();
	baby->setup(host, port);
	return baby;
}

//--------------------------------------------------------------
messageCore ofxOscFamily::newCore(string message, long delayMillSecound) {
	messageCore m;
	m.message = message;
	m.delayMillSecound = delayMillSecound;
	return m;
}

//--------------------------------------------------------------
ofxOscParent::ofxOscParent()
{}

//--------------------------------------------------------------
ofxOscParent::~ofxOscParent()
{}

//--------------------------------------------------------------
void ofxOscParent::AddRoute(string address, const ofxOscBaby &baby) {

	child c;
	c.address = address;
	c.baby = baby;
	
	AddRoute(c);

}

//--------------------------------------------------------------
void ofxOscParent::AddRoute(const child &_child) {
	
	childlen.push_back(_child);

}

//--------------------------------------------------------------
void ofxOscParent::sendMsg(const string &msg) {

	vector<string> args = ofSplitString(msg, " ");
	if (args.size() == 0) return;

	string address = args[0];
	string arg = "";


	for (int i = 0; i < childlen.size(); i++)
	{
		if (ofIsStringInString(address, childlen[i].address)) {

			ofxOscMessage m;
			m.setAddress(address);

			for (int k = 1; k < args.size(); k++) {

				m.addStringArg(args[k]);
				arg += args[k] + " ";

			}

			childlen[i].baby->sendMessage(m, false);

			std::string log = "[" + childlen[i].baby->getHost() + ":" +
				ofToString(childlen[i].baby->getPort()) + "] " +
				address + " " + arg;
			
			if(household != nullptr) household->push_back(log);

		}
	}

}


//--------------------------------------------------------------
void ofxOscParent::checkHouseHold(const ofxOscHousehold &household)
{

	this->household = household;

}