#include "utils.h"

void print_status(std::string status) {
    std::cout << "STATUS: " + status + "\n";
}

std::string f_to_string(float fval) {
    std::stringstream ss (std::stringstream::in | std::stringstream::out);
    ss << fval;
    return ss.str();
}

std::string jpopen(std::string cmd, int printval) {
    FILE *pf;
    char data[512];
    pf = popen(cmd.c_str(),"r"); 
    if(!pf) {
      fprintf(stderr, "Could not open pipe for output.\n");
      return "";
    }
    fgets(data, 512 , pf);
    if (pclose(pf) != 0)
        fprintf(stderr," Error: Failed to close command stream \n");
    std::string strdata = data;
    if(printval == 1) {
        std::cout << "\""+strdata+"\"\n";
    } else if (printval == 2) {
        std::cout << "\""+cmd+"\": \""+strdata+"\"\n";
    }
    return strdata;
}