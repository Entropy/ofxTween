#ifndef _PENNER_QUAD
#define _PENNER_QUAD
#include "ofxBaseEasing.h"
class ofxEasingQuad: public ofxBaseEasing {

	public:

		float easeIn(float t,float b , float c, float d) const;
		float easeOut(float t,float b , float c, float d) const;
		float easeInOut(float t,float b , float c, float d) const;
};

#endif
