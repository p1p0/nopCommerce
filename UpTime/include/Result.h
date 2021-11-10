#pragma once
#include <string>

#if !defined(_Result_H_) 
#define _Result_H_

typedef struct result
{
    std::string now;
    std::string type;
    unsigned int days;
    unsigned int hours;
    unsigned int minutes;
}Result;

#endif