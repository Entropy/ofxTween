#ifndef _PENNER_SINE
#define _PENNER_SINE
#include "ofxBaseEasing.h"
#include <math.h>

#ifndef PI
#define PI  3.14159265
#endif

class ofxEasingSine: public ofxBaseEasing {

	public:

		float easeIn(float t,float b , float c, float d) const;
		float easeOut(float t,float b , float c, float d) const;
		float easeInOut(float t,float b , float c, float d) const;

};

#endif
