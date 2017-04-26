#ifndef _PENNER_QUINT
#define _PENNER_QUINT
#include "ofxBaseEasing.h"
class ofxEasingQuint: public ofxBaseEasing {

	public:

		float easeIn(float t,float b , float c, float d) const;
		float easeOut(float t,float b , float c, float d) const;
		float easeInOut(float t,float b , float c, float d) const;
};

#endif
