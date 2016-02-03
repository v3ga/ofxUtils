//
//  ofAppGlobals.h
//  CCV_M06_1_PMR
//
//  Created by Julien on 09/12/2015.
//
//

#pragma once
#include "ofMain.h"
#define OFAPPGLOBALS 	ofAppGlobals::instance()
class ofAppGlobals
{
	protected:
		static ofAppGlobals*			smp_instance;

	public:
		ofAppGlobals			();
		static ofAppGlobals*	instance	();
		static void				destroy		();

				bool			getBool		(string name);
				float			getFloat	(string name);
				int				getInt		(string name);
				string			getString	(string name);
				void*			get			(string name);

				void			set			(string name, bool value);
				void			set			(string name, float value);
				void			set			(string name, int value);
				void			set			(string name, string value);
				void			set			(string name, void* pObject);
	
	private:
	
	
	
		map<string, bool>				m_booleans;
		map<string, float>				m_floats;
		map<string, int>				m_ints;
		map<string, string>				m_strings;
		map<string, void*>				m_objects;
 
		map<string, bool>::iterator		m_bIt;
		map<string, float>::iterator	m_fIt;
		map<string, int>::iterator		m_iIt;
		map<string, string>::iterator	m_sIt;
		map<string, void*>::iterator	m_oIt;
};