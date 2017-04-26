#ifndef _PENNER_EXPO
#define _PENNER_EXPO

#include <math.h>
#include "ofxBaseEasing.h"
class ofxEasingExpo: public ofxBaseEasing {

	public:

		float easeIn(float t,float b , float c, float d) const;
		float easeOut(float t,float b , float c, float d) const;
		float easeInOut(float t,float b , float c, float d) const;
};

#endif
