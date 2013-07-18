#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <cstring>

#ifndef CONFIG_H
#define CONFIG_H

class Config {
	private:
		std::string AGENT_LOC;
		std::string EMU_LOC;
		std::string EMU_NAME;
		float EMU_SCALE;
		int EMU_TIMEOUT;
		std::vector<std::string> split_line(std::string);
		int set_config_var(std::string, std::string);
		int parse_config();
		void default_config();
		void print_config();
	public:
		Config();
		std::string get_agentloc()	{ return AGENT_LOC; }
		std::string get_emuloc()	{ return EMU_LOC; 	}
		std::string get_emuname()	{ return EMU_NAME; 	}
		float get_emuscale()	{ return EMU_SCALE;		}
		float get_emutimeout()	{ return EMU_TIMEOUT; 	}
};

#endif