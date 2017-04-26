#ifndef _PENNER_BACK
#define _PENNER_BACK

#include "ofxBaseEasing.h"

class ofxEasingBack: public ofxBaseEasing {

	public:

		float easeIn(float t,float b , float c, float d) const;
		float easeOut(float t,float b , float c, float d) const;
		float easeInOut(float t,float b , float c, float d) const;

};

#endif
