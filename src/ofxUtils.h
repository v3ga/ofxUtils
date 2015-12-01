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


