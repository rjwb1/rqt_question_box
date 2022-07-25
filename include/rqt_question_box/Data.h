#ifndef _DATA_H_
#define _DATA_H_

#include <iostream>

struct Request
{
    std::string question = "";
    std::string response = "";
    std::string type; //bool, string, int   
    bool result = false; // true when completed
    int id;
};

#endif //_DATA_H_