#ifndef _PENNER_QUART
#define _PENNER_QUART
#include "ofxBaseEasing.h"
class ofxEasingQuart: public ofxBaseEasing {

	public:

		float easeIn(float t,float b , float c, float d) const;
		float easeOut(float t,float b , float c, float d) const;
		float easeInOut(float t,float b , float c, float d) const;
};

#endif
