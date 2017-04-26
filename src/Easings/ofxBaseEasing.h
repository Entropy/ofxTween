#ifndef BASEEASING_H_
#define BASEEASING_H_

class ofxEasingArgs{
public:
	float t;
	float b;
	float c;
	float d;

	float res;
};


class ofxBaseEasing{
public:
    
		void easeIn(ofxEasingArgs & args);
		void easeOut(ofxEasingArgs & args);
		void easeInOut(ofxEasingArgs & args);

		virtual float easeIn(float t,float b , float c, float d) const=0;
		virtual float easeOut(float t,float b , float c, float d) const=0;
		virtual float easeInOut(float t,float b , float c, float d) const=0;
};

#endif /* BASEEASING_H_ */
