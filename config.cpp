#include "config.h"

Config::Config() {
	AGENT_LOC = "../sdk/mercury-2.2.2";	// Location of agent.apk file
	EMU_LOC = "../sdk/sdk/tools";		// Location of emulator
	EMU_NAME = "Nexus";					// Emulator AVD name
	EMU_SCALE = 0.5;					// Emulator -scale option
	EMU_GLOBAL = false;					// use ./ or not
	EMU_TIMEOUT = 10000;				// Timeout on starting emulator (necessary?)
};