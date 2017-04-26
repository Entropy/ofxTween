/*
 * Easing.cpp
 *
 *  Created on: 17-sep-2008
 *      Author: arturo castro
 */

#include "ofxBaseEasing.h"

void ofxBaseEasing::easeIn(ofxEasingArgs & args){
	args.res=easeIn(args.t,args.b,args.c,args.d);
}

void ofxBaseEasing::easeOut(ofxEasingArgs & args){
	args.res=easeOut(args.t,args.b,args.c,args.d);
}

void ofxBaseEasing::easeInOut(ofxEasingArgs & args){
	args.res=easeInOut(args.t,args.b,args.c,args.d);
}
