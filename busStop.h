#ifndef BUSSTOP_H
#define BUSSTOP_H


#include "linkedList.h" 
#include <string>


class busStop{
public: 
    busStop(const int stopId, const std::string& name); 
    int getId() const;
    std::string getName() const;

private:
    int id;
    std::string name;
};
#endif