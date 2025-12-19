#include "bus.h"
#include <string>

bus::bus(const int busId, const std::string& driverName, busLine* line)
    : line(line), id(busId), driverName(driverName) {}

int bus::getId() const
{
    return id;
}

busLine* bus::getLine() const
{
    return line;
}

std::string bus::getdriverName() const
{
    return driverName;
}