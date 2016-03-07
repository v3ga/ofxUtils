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
// char utilities
//--------------------------------------------------------------
static inline bool s_isEOF(char c)
{	return c==0;
}
static inline bool s_isEOL(char c)
{	return (c=='\n' || c=='\r');
}
static inline bool s_isSPC(char c)
{	return (c==' ' || c=='\t');
}
static inline bool s_isComment(char c)
{	return c=='/';
}
static inline bool s_isNumeric(char c)
{	return (c>='0' && c<='9');
}
static inline bool s_isDecimalNumber(char c)
{	return (c>='0' && c<='9')||(c=='-'||c=='.');
}

static inline bool s_isNumericExtended(char c)
{	return s_isNumeric(c) || (c=='-' || c=='+' || c=='.' || c=='e' || c=='E');
}
static inline bool s_isAlphaNum(char c)
{	return ( c=='_' || s_isNumeric(c) || (c>='A'&&c<='Z') || (c>='a'&&c<='z') );
}
static inline bool s_isAlpha(char c)
{	return (c>='A'&&c<='Z') || (c>='a'&&c<='z');
}

static inline bool s_isASCII(char c)
{	return (c>=' ');
}
static inline bool s_isMeta(char c)
{
	return (c=='#');
}
static inline bool s_isHex(char c)
{	return (c>='0' && c<='9') || (c>='A' && c<='F') || (c>='a' && c<='f');

}
#define s_UTF8_isEOL(codePoint) (codePoint==0xE280A8 || codePoint=='\n')


//--------------------------------------------------------------
class ofxUtils
{
	public:
		static void 	computeNormals			( ofMesh & mesh, bool bNormalize );
		static float	getPixelsSizeForCm		( float cm, ofVec2f screenDim, ofVec2f screenRes=ofVec2f(1920,1080));
		static float	getPixelsSizeForMm		( float mm, ofVec2f screenDim, ofVec2f screenRes=ofVec2f(1920,1080));
		static float 	getPixelsSizeforPt		( float pt, ofVec2f screenDim, ofVec2f screenRes=ofVec2f(1920,1080));
};
