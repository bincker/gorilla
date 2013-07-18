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
	print_status("Starting Android emulator \""+CONFIG.get_emuname()+"\"");
	string emu_cmd = "./" + CONFIG.get_emuloc() + "/emulator @" 
						  + CONFIG.get_emuname() + " -scale " 
						  + f_to_string(CONFIG.get_emuscale()) + " &";
	system(emu_cmd.c_str());		  
	float emutimer = 0;
	while (system("ps aux | pgrep emulator64-arm") != 0 && emutimer < CONFIG.get_emutimeout()) {
		emutimer++;
		print_status("Waiting for emulator: (" + f_to_string(emutimer)
						  + "/" + f_to_string(CONFIG.get_emutimeout()) + ")");
	}
	print_status("Installing Mercury agent.apk");
	string agent_cmd = "adb wait-for-device install " + CONFIG.get_agentloc() 
						  + "/agent.apk &";
	jpopen(agent_cmd.c_str(), false);
	print_status("Starting Mercury Intent");
	string intent_cmd= "adb shell am start -n com.mwr.droidhg.agent/.MainActivity";
	jpopen(intent_cmd.c_str(), false);
	print_status("ADB forwarding");
	jpopen("adb forward tcp:31415 tcp:31415", false);
	jpopen("adb shell ps | grep com.mwr.droidhg.agent | awk '{print $9}'", false);
	return 0;
}