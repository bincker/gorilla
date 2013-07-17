#include <iostream>
#include <fstream>

#ifndef CONFIG_H
#define CONFIG_H

class Config {
	private:
		std::string AGENT_LOC;
		std::string EMU_LOC;
		std::string EMU_NAME;
		float EMU_SCALE;
		bool EMU_GLOBAL;
		int EMU_TIMEOUT;
	public:
		Config();
		std::string get_agentloc()	{ return AGENT_LOC; }
		std::string get_emuloc()	{ return EMU_LOC; 	}
		std::string get_emuname()	{ return EMU_NAME; 	}
		float get_emuscale()	{ return EMU_SCALE;		}
		bool get_emuglobal()	{ return EMU_GLOBAL;	}
		int get_emutimeout()	{ return EMU_TIMEOUT; 	}
};

#endif