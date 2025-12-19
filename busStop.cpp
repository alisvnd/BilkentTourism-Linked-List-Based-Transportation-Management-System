#include "busStop.h"
#include <string> 

busStop::busStop(const int stopId, const std::string& name) 
    : id(stopId), name(name) 
{}

int busStop::getId() const 
{
    return id;
}

std::string busStop::getName() const 
{
    return name;
}