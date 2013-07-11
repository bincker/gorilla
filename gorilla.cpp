/*
	gorilla.cpp
	Joshua Rispoli
	7/9/2013
	SUCCESS Lab

	Fuzzes the Android platform using the Monkey framework as well as the Mercury framework.
	This allows us to fuzz IPC and UI events at the same time to look for bugs and vulnerabilities.
*/

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

int main(int argc, char* argv[])
{
	// cmd line arg parsing
	int aflag = 0;
	int c;
	while ((c = getopt (argc, argv, "a:")) != -1)
	{
		switch(c) {	
		case 'a':
			aflag = 1;
			cout << "ADSFASDF";
			break;
		default:
			break;
			
		}
	}

	string AGENTLOC = "../sdk/mercury-2.2.2";	// Location of agent.apk file
	string EMULOC = "../sdk/sdk/tools";		// Location of emulator
	string emu_cmd =   "./" + EMULOC + "/emulator @Nexus &";
	system(emu_cmd.c_str());
	string agent_cmd = "adb wait-for-device install " + AGENTLOC + "/agent.apk &";
	system(agent_cmd.c_str());
	string 
	//while(adb shows agent is uninstalled) wait, add timeout

	// emulator64-arm		top
	// commands used to kill emu process ^^^	

	
	return 0;

}

