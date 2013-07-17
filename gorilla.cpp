#include "config.h"
#include "utils.h"

using namespace std;

int main(int argc, char* argv[]) {
	int aflag = 0;
	int c;
	while ((c = getopt (argc, argv, "a:")) != -1) {
		switch(c) {	
		case 'a':
			aflag = 1;
			break;
		default:
			break;
		}
	}
	Config CONFIG;
	//this is hardcoded, BAD BAD BAD
	string emu_cmd = "./" + CONFIG.get_emuloc() + "/emulator @" 
						  + CONFIG.get_emuname() + " -scale " 
						  + f_to_string(CONFIG.get_emuscale()) + " &"; 
	system(emu_cmd.c_str());
	string agent_cmd = "adb wait-for-device install " + CONFIG.get_agentloc() 
						  + "/agent.apk &";
	jpopen(agent_cmd.c_str(), true);
	string intent_cmd= "adb shell am start -n com.mwr.droidhg.agent/.MainActivity";
	jpopen(intent_cmd.c_str(), false);
	jpopen("adb forward tcp:31415 tcp:31415", false);
	jpopen("adb shell ps | grep com.mwr.droidhg.agent | awk '{print $9}'", true);
	return 0;
}