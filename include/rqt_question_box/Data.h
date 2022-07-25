#ifndef _DATA_H_
#define _DATA_H_

#include <iostream>

struct Request
{
    std::string question = "";
    std::string response = "";
    bool result = false; // true when completed
    int type; //0 bool, 1 string, 2 int   
    int id;
};

#endif //_DATA_H_