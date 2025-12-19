#ifndef BUS_H
#define BUS_H

class busLine;

#include "busStop.h"
#include <string>
class bus{
public: 
    bus(const int busId, const std::string& driverName, busLine* line);
    int getId() const;
    busLine* getLine() const;  
    std::string getdriverName() const;

private:
    busLine* line;
    int id;
    std::string driverName;
};
#endif