//
//  ofAppProfiler.h
//  CCV_M06_1_1
//
//  Created by Julien on 01/12/2015.
//
//

#pragma once
#include "ofMain.h"

#define OFAPPPROFILER	ofAppProfiler::instance()

class ofAppProfilerNode
{
	public:
		ofAppProfilerNode			(string name, ofAppProfilerNode* pParent, int level=0);
		~ofAppProfilerNode			();


		void						begin		();
		void						end			();
		ofAppProfilerNode*			getNode		(string name);
		void						add			(ofAppProfilerNode*);
 
		const char*					toString	();


		ofAppProfilerNode*			mp_parent;
		string						m_name;
		vector<ofAppProfilerNode*>	m_children;
 
		unsigned long long			m_time; // milliseconds
		float			 			m_duration,m_durationMean;
 
		int							m_level;
		string						m_str;
		string						m_tab;
 
		vector<float>				m_durationHistory;
 
		static char					smp_stringBuffer[100];

};


class ofAppProfiler
{
	public:
		ofAppProfiler						();
		~ofAppProfiler						();
 
 		void					setup		();
		void					draw		();

		void					begin		(string name);
		void					end			();
 
		ofAppProfilerNode*		getNode		(string name);
 
 
 		static	ofAppProfiler*	instance	();
		static 	void			destroy		();

	private:
		ofAppProfilerNode*		mp_rootNode;
		ofAppProfilerNode*		mp_activeNode;
 
 
		static ofAppProfiler*	smp_instance;
		static int				sm_level;
};
