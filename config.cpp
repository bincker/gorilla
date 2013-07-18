#include "config.h"

std::vector<std::string> Config::split_line(std::string line) {
	std::vector<std::string> result;
	char curr_char = line[0];
	int i = 0;
	for(; i < line.length() && curr_char!= '=' ; i++) curr_char = line[i];
	if(curr_char == '=') {
		result.push_back(line.substr(0,i-1));
		result.push_back(line.substr(i,line.length()-i));
		return result;
	} else { 
		std::cout << "Config parse error.  No \"=\" token found\n";
		result.push_back(""); result.push_back(""); 
		return result;
	}
}
int Config::set_config_var(std::string var, std::string val) {
	if (!strcmp(var.c_str(), "AGENT_LOC")) {
		AGENT_LOC = val; return 1;
	} else if (!strcmp(var.c_str(), "EMU_LOC")) {
		EMU_LOC = val; return 1;
	} else if (!strcmp(var.c_str(), "EMU_NAME")) {
		EMU_NAME = val; return 1;
	} else if (!strcmp(var.c_str(), "EMU_SCALE")) {
		EMU_SCALE = atof(val.c_str()); return 1;
	} else if (!strcmp(var.c_str(), "EMU_TIMEOUT")) {
		EMU_TIMEOUT = atof(val.c_str()); return 1;
	}
	return 0;
}
int Config::parse_config() {
	std::ifstream config_file("config.txt");
	std::string line;
	if(config_file.is_open()) {
		while(config_file.good()) {
			getline(config_file, line);
			if(line.length()>0) { 
	    		std::vector<std::string> result = split_line(line);
	    		set_config_var(result[0], result[1]);
	    	}
		} config_file.close();
	} else {
		std::cout << "Failed to open config.txt.  Using default configuration";
		return 0;
	}
	return 1;
}
void Config::default_config() {
	AGENT_LOC = "../sdk/mercury-2.2.2";	// Location of agent.apk file
	EMU_LOC = "../sdk/sdk/tools";		// Location of emulator
	EMU_NAME = "Nexus";					// Emulator AVD name
	EMU_SCALE = 0.5;					// Emulator -scale option
	EMU_TIMEOUT = 200.0;				// Timeout on starting emulator (necessary?)
}
void Config::print_config() {
	std::cout << "AGENT_LOC:"+AGENT_LOC+"\n";
	std::cout << "EMU_LOC:"+EMU_LOC+"\n";
	std::cout << "EMU_NAME:"+EMU_NAME+"\n";
	std::cout << "EMU_SCALE:"<<EMU_SCALE<<"\n";
	std::cout << "EMU_TIMEOUT:"<<EMU_TIMEOUT<<"\n";
}
Config::Config() {
	default_config();
	parse_config();
	print_config();
}