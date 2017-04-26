#ifndef _PENNER_BOUNCE
#define _PENNER_BOUNCE

#include "ofxBaseEasing.h"
class ofxEasingBounce: public ofxBaseEasing {

	public:

		float easeIn(float t,float b , float c, float d) const;
		float easeOut(float t,float b , float c, float d) const;
		float easeInOut(float t,float b , float c, float d) const;
};

#endif
