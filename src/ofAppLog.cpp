//
//  ofAppLog.cpp
//  A_P_P_A_R_E_L
//
//  Created by Julien on 15/07/2014.
//
//

#include "ofAppLog.h"

//--------------------------------------------------------------
ofAppLog* ofAppLog::smp_instance = 0;

//--------------------------------------------------------------
/*ofAppLog::ofAppLog()
{
	m_disabled = false;
}
*/
//--------------------------------------------------------------
void ofAppLog::destroy()
{
	delete smp_instance;
}

//--------------------------------------------------------------
void ofAppLog::begin(string s)
{
	if (m_disabled) return;

	println(s);
	println("{");
	m_level++;
}

//--------------------------------------------------------------
void ofAppLog::end()
{
	if (m_disabled) return;

	m_level--;
	println("}");
}

//--------------------------------------------------------------
void ofAppLog::println(ofLogLevel level, const string & message)
{
	if (m_disabled) return;

	ofLog(level) << message;
}

//--------------------------------------------------------------
void ofAppLog::println(const string & message)
{
	if (m_disabled) return;

	ofLog() << space(m_level) << message;
}




//--------------------------------------------------------------
ofAppLog* ofAppLog::getInstance()
{
	if(smp_instance==0)
	{
		smp_instance = new ofAppLog();
		smp_instance->m_disabled = false;
	}
	return smp_instance;
}

//--------------------------------------------------------------
string ofAppLog::space(int nb)
{
	string s;
	for (int i=0;i<nb*2;i++) s+=" ";
	return s;
}


