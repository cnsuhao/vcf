#ifndef PARTICLERESOURCEMANAGER_H
#define PARTICLERESOURCEMANAGER_H

#include "XMLParticleResourceHandler.h"

#include <map>

class ParticleResourceManager{
public:
	static ParticleResource *loadResource(const std::string &name){
		std::map<std::string,ParticleResource*>::iterator it=getMap().find(name);
		if(it==getMap().end()){
			FileInputStream *in=0;
			try{
				in=new VCF::FileInputStream(name);
			}
			catch(std::exception &e){
				e; // Get rid of warning
			}

			if(in){
				XMLParticleResourceHandler handler;

				ParticleResource *r=handler.loadResource(in);
				delete in;
				if(r){
					getMap()[name]=r;
					return r;
				}
			}
		}
		else{
			return it->second;
		}

		return 0;
	}

	static void reset(){
		getMap().clear();
	}

	static std::map<std::string,ParticleResource*> &getMap(){
		static std::map<std::string,ParticleResource*> m;
		return m;
	}
};

#endif

/**
*CVS Log info
*$Log$
*Revision 1.1.2.1  2004/11/01 14:38:59  pallindo
*Initial checkin of the particle editor example.  Just shows off a more complex opengl application using the VCF.
*
*/