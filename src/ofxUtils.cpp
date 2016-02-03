//
//  ofxUtils.cpp
//  CCV_M06_1
//
//  Created by Julien on 10/11/2015.
//
//

#include "ofxUtils.h"


//--------------------------------------------------------------
void ofxUtils::computeNormals( ofMesh & mesh, bool bNormalize )
{
	if (mesh.getNormals().size()==0)
	{
	    for( int i=0; i < mesh.getVertices().size(); i++ ) mesh.addNormal(ofPoint(0,0,0));
	}
	
    for( int i=0; i < mesh.getIndices().size(); i+=3 ){
        const int ia = mesh.getIndices()[i];
        const int ib = mesh.getIndices()[i+1];
        const int ic = mesh.getIndices()[i+2];
        
        ofVec3f e1 = mesh.getVertices()[ia] - mesh.getVertices()[ib];
        ofVec3f e2 = mesh.getVertices()[ic] - mesh.getVertices()[ib];
        ofVec3f no = e2.cross( e1 );
        
        // depending on your clockwise / winding order, you might want to reverse the e2 / e1 above if your normals are flipped. 
        
        mesh.getNormals()[ia] += no;
        mesh.getNormals()[ib] += no;
        mesh.getNormals()[ic] += no;
    }
    
    if (bNormalize)
    for(int i=0; i < mesh.getNormals().size(); i++ ) {
        mesh.getNormals()[i].normalize();   
    }
}

//--------------------------------------------------------------
float ofxUtils::getPixelsSizeForCm(float cm, ofVec2f screenDim, ofVec2f screenRes)
{
	float nbPixPerCm = screenRes.x / screenDim.x;
	return cm * nbPixPerCm;
}

//--------------------------------------------------------------
float ofxUtils::getPixelsSizeForMm(float mm, ofVec2f screenDim, ofVec2f screenRes)
{
	return getPixelsSizeForCm(mm/10.0f, screenDim/10.0f, screenRes);
}

//--------------------------------------------------------------
float ofxUtils::getPixelsSizeforPt( float pt, ofVec2f screenDim, ofVec2f screenRes)
{
	float mm = pt * 0.352778;
	return getPixelsSizeForMm( mm,screenDim, screenRes );
}








