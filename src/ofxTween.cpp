#include "ofxTween.h"

ofxTween::ofxTween(){
	duration = 0;
	completed = true;
	running = false;

	easing = NULL;
	id = -1;
	frameBased = false;
}

ofxTween::ofxTween(const ofxTween &other)
: id(other.id),
end_E(other.end_E),
from(other.from),
to(other.to),
change(other.change),
pTarget(other.pTarget),
elapsed(other.elapsed),
startTime(other.startTime),
delay(other.delay),
duration(other.duration),
running(other.running),
completed(other.completed),
type(other.type),
frameBased(other.frameBased) {
    if (other.easing) {
        easing = other.easing;
    }
    else {
        easing = NULL;
    }
}

ofxTween ofxTween::operator=(const ofxTween &other)
{
    id = other.id;
	end_E = other.end_E;
    from = other.from;
    to = other.to;
    change = other.change;
    pTarget = other.pTarget;
    elapsed = other.elapsed;
    startTime = other.startTime;
    delay = other.delay;
    duration = other.duration;
    running = other.running;
    completed = other.completed;
    type = other.type;
	frameBased = other.frameBased;
    if (other.easing) {
        easing = other.easing;
    }
    else {
        easing = NULL;
    }
    return *this;
}

ofxTween::ofxTween(int id,  ofxBaseEasing & easing, ofxEasingType type,  float from, float to, unsigned duration, unsigned delay) {
	setParameters(id, easing, type, from,to,duration,delay);
}

ofxTween::~ofxTween() {
}

void ofxTween::setParameters( ofxBaseEasing & easing, ofxEasingType type, float from, float to, unsigned duration, unsigned delay){
	setParameters(id, easing, type, from,to,duration,delay);
}

void ofxTween::setParameters(int _id,  ofxBaseEasing & _easing, ofxEasingType _type,  float _from, float _to, unsigned _duration, unsigned _delay){
	from.clear();
	to.clear();
	change.clear();
	pTarget.clear();

	id 		= _id;
	type 	= _type;
	easing 	= &_easing;


	addValue(_from,_to);
	if(frameBased){
		duration = _duration;
		delay = _delay;
	}else{
		duration = _duration*1000;
		delay = _delay*1000;
	}
	start();

	completed = false;
	running = true;

}

void ofxTween::addValue(float _from, float _to){
	from.push_back(_from);
	to.push_back(_to);
	change.push_back(_to-_from);
	pTarget.push_back(_from);
}

void ofxTween::start(){
	if(!frameBased){
	}else{
		elapsed=0;
	}
}

void ofxTween::setDuration(int _duration) {
	if(frameBased){
		duration = _duration;
	}else{
		duration = _duration*1000;
	}
}

int ofxTween::getDuration() {
	return duration;
}

float ofxTween::getTarget(unsigned pos) {
	if(pTarget.size()>pos)
		return pTarget[pos];
	else
		return 0;
}

bool ofxTween::isRunning() {
	return running;
}

bool ofxTween::isCompleted() {
	return completed;
}

float ofxTween::update() {
	if(!completed){

		if(frameBased){
			ofxEasingArgs args;
			elapsed++;
			args.t= elapsed;
			args.d= float(duration);
			for(unsigned i=0; i<from.size(); i++){
				args.b=from[i];
				args.c=change[i];

				pTarget[i] = args.res;
			}
			if(pTarget[0]==to[0])
				running=false;
			else
				running = true;
		}else{
		}
	}
	return getTarget(0);
}


void ofxTween::setFrameBasedAnimation(bool frameBased){
	this->frameBased = frameBased;
}

float ofxTween::map(float value, float inputMin, float inputMax, float outputMin, float outputMax, bool clamp, const ofxBaseEasing & easing)
{
	return ofxTween::map(value, inputMin, inputMax, outputMin, outputMax, clamp, easing, ofxTween::easeInOut);
}

float ofxTween::map(float value, float inputMin, float inputMax, float outputMin, float outputMax, bool clamp, const ofxBaseEasing & easing, ofxEasingType type)
{
	if(clamp){
		value = ofClamp(value, inputMin, inputMax);
	}
	float t = value - inputMin;
	float c = outputMax - outputMin;
	float d = inputMax - inputMin;
	float b = outputMin;
	float res;
	switch (type) {
		case ofxTween::easeIn:
		{
			res = easing.easeIn(t,b,c,d);
			break;
		}
		case ofxTween::easeOut:
		{
			res = easing.easeOut(t,b,c,d);
			break;
		}
		default:
			res = easing.easeInOut(t,b,c,d);
	}
	
	return res;
}

