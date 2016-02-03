//
//  ofxUtils.h
//  CCV_M06_1
//
//  Created by Julien on 10/11/2015.
//
//

#pragma once

#include "ofAppLog.h"
#include "ofAppProfiler.h"

//--------------------------------------------------------------
inline float float_min(float x,float y)
{	if(x<y) return x;
	return y;
}
//--------------------------------------------------------------
inline float float_relax(float value,float target,float dt,float T=0.5f)
{
	value += (target-value)*float_min(1.0f, dt/T);
	return value;
}

//--------------------------------------------------------------
class ofxUtils
{
	public:
		static void 	computeNormals			( ofMesh & mesh, bool bNormalize );
		static float	getPixelsSizeForCm		( float cm, ofVec2f screenDim, ofVec2f screenRes=ofVec2f(1920,1080));
		static float	getPixelsSizeForMm		( float mm, ofVec2f screenDim, ofVec2f screenRes=ofVec2f(1920,1080));
		static float 	getPixelsSizeforPt		( float pt, ofVec2f screenDim, ofVec2f screenRes=ofVec2f(1920,1080));
};
