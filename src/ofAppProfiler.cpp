//
//  ofAppProfiler.cpp
//  CCV_M06_1_1
//
//  Created by Julien on 01/12/2015.
//
//

#include "ofAppProfiler.h"




//--------------------------------------------------------------
ofAppProfilerNode::ofAppProfilerNode(string name, ofAppProfilerNode* pParent,int level)
{
	m_name = name;
	mp_parent = pParent;
	m_duration = 0.0f;
	m_level = level;
	m_str = "";
	for (int i=0;i<level;i++){
		m_tab+= " ";
	}
}

//--------------------------------------------------------------
ofAppProfilerNode::~ofAppProfilerNode()
{
	vector<ofAppProfilerNode*>::iterator it = m_children.begin();
	for ( ; it != m_children.end(); ++it)
	{
		delete *it;
	}
	m_children.clear();
}


//--------------------------------------------------------------
void ofAppProfilerNode::begin()
{
	m_time = ofGetElapsedTimeMillis();
}

//--------------------------------------------------------------
void ofAppProfilerNode::end()
{
	m_duration = float(ofGetElapsedTimeMillis() - m_time);
}

//--------------------------------------------------------------
ofAppProfilerNode* ofAppProfilerNode::getNode(string name)
{
	if (name == m_name)
		return this;
 
	vector<ofAppProfilerNode*>::iterator it = m_children.begin();
	for ( ; it != m_children.end(); ++it)
	{
		ofAppProfilerNode* pChildNode = *it;
		if (pChildNode->getNode(name))
			return pChildNode;
	}
	return 0;
}

//--------------------------------------------------------------
void ofAppProfilerNode::add(ofAppProfilerNode* pNode)
{
	m_children.push_back(pNode);
}


//--------------------------------------------------------------
const char* ofAppProfilerNode::toString()
{
	m_str = m_tab + m_name + (mp_parent ? " ["+ofToString(m_duration)+" ms]\n" : "\n");
	vector<ofAppProfilerNode*>::iterator it = m_children.begin();
	for ( ; it != m_children.end(); ++it)
	{
		m_str += (*it)->toString();
	}

	return m_str.c_str();
}

//--------------------------------------------------------------
ofAppProfiler* ofAppProfiler::smp_instance = 0;
int ofAppProfiler::sm_level = 0;

//--------------------------------------------------------------
ofAppProfiler::ofAppProfiler()
{
	mp_rootNode 	= 0;
	mp_activeNode	= 0;
}

//--------------------------------------------------------------
ofAppProfiler::~ofAppProfiler()
{
	delete mp_rootNode;
}

//--------------------------------------------------------------
ofAppProfiler*	ofAppProfiler::instance	()
{
	if (smp_instance == 0)
		smp_instance = new ofAppProfiler();
	return smp_instance;
}

//--------------------------------------------------------------
void ofAppProfiler::destroy()
{
	delete smp_instance;
}

//--------------------------------------------------------------
void ofAppProfiler::setup()
{
	mp_rootNode = new ofAppProfilerNode("app", 0);
	mp_activeNode = mp_rootNode;
	sm_level = 1;
}

//--------------------------------------------------------------
void ofAppProfiler::draw()
{
	if (mp_rootNode)
	{
		ofDrawBitmapString(mp_rootNode->toString(), 5, 15);
	}
}

//--------------------------------------------------------------
ofAppProfilerNode* ofAppProfiler::getNode(string name)
{
	if (mp_rootNode)
		return mp_rootNode->getNode(name);
	return 0;
}

//--------------------------------------------------------------
void ofAppProfiler::begin(string name)
{
	ofAppProfilerNode* pNode = mp_activeNode->getNode(name);
	if (pNode == 0)
	{
		pNode = new ofAppProfilerNode(name, mp_activeNode, sm_level);
		mp_activeNode->add(pNode);
	}
	sm_level++;
	
	mp_activeNode = pNode;
	mp_activeNode->begin();
}

//--------------------------------------------------------------
void ofAppProfiler::end()
{
	if (mp_activeNode)
	{
		sm_level--;
		mp_activeNode->end();
		mp_activeNode = mp_activeNode->mp_parent;
	}
}


