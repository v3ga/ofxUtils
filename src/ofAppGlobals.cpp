//
//  ofAppGlobals.cpp
//  CCV_M06_1_PMR
//
//  Created by Julien on 09/12/2015.
//
//

#include "ofAppGlobals.h"


ofAppGlobals* ofAppGlobals::smp_instance = 0;

//--------------------------------------------------------------
ofAppGlobals::ofAppGlobals()
{
}

//--------------------------------------------------------------
ofAppGlobals* ofAppGlobals::instance()
{
	if (smp_instance == 0)
		smp_instance = new ofAppGlobals();
	return smp_instance; 
}

//--------------------------------------------------------------
void ofAppGlobals::destroy()
{
	delete smp_instance;
}


//--------------------------------------------------------------
bool ofAppGlobals::getBool(string name)
{
	m_bIt = m_booleans.find(name);
	if (m_bIt!=m_booleans.end())
		return m_bIt->second;
	return false;
}

//--------------------------------------------------------------
float ofAppGlobals::getFloat(string name)
{
	m_fIt = m_floats.find(name);
	if (m_fIt!=m_floats.end())
		return m_fIt->second;
	return 0.0f;
}

//--------------------------------------------------------------
int	ofAppGlobals::getInt(string name)
{
	m_iIt = m_ints.find(name);
	if (m_iIt!=m_ints.end())
		return m_iIt->second;
	return 0;
}

//--------------------------------------------------------------
string ofAppGlobals::getString(string name)
{
	m_sIt = m_strings.find(name);
	if (m_sIt!=m_strings.end())
		return m_sIt->second;
	return "";
}

//--------------------------------------------------------------
void* ofAppGlobals::get(string name)
{
	m_oIt = m_objects.find(name);
	if (m_oIt!=m_objects.end())
		return m_oIt->second;
	return 0;
}


//--------------------------------------------------------------
void ofAppGlobals::set(string name, bool value)
{
	m_booleans[name] = value;
}

//--------------------------------------------------------------
void ofAppGlobals::set(string name, float value)
{
	m_floats[name] = value;
}

//--------------------------------------------------------------
void ofAppGlobals::set(string name, int value)
{
	m_ints[name] = value;
}

//--------------------------------------------------------------
void ofAppGlobals::set(string name, string value)
{
	m_strings[name] = value;
}

//--------------------------------------------------------------
void ofAppGlobals::set(string name, void* pObject)
{
	m_objects[name] = pObject;
}

