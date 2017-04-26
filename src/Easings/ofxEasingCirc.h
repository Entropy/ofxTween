#ifndef _PENNER_CIRC
#define _PENNER_CIRC

#include <math.h>
#include "ofxBaseEasing.h"
class ofxEasingCirc: public ofxBaseEasing {

	public:

		float easeIn(float t,float b , float c, float d) const;
		float easeOut(float t,float b , float c, float d) const;
		float easeInOut(float t,float b , float c, float d) const;
};

#endif
