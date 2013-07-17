#include "utils.h"

std::string f_to_string(float fval) {
    std::stringstream ss (std::stringstream::in | std::stringstream::out);
    ss << fval;
    return ss.str();
}

std::string jpopen(std::string cmd, bool print) {
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
    if(print) std::cout << strdata;
    return strdata;
}