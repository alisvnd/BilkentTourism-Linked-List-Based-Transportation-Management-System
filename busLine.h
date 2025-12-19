#ifndef BUSLINE_H
#define BUSLINE_H

#include "bus.h"
#include "busStop.h"
#include "linkedList.h" 
#include <string>

class busLine{
public: 
    busLine(const int lineId, const std::string& lineName); 
    
    int getId() const;
    std::string getLineName() const;
    bool addStop(const busStop& stop);
    bool addBus(const bus& busObj);
    bool removeBus(int id);
    bool removeStop(int id);
    bool hasStop(int id) const;
    void printStops() const;
    void printBuses() const;
    void printAssignedBuses() const;
    const linkedList<bus>& getBuses() const;

private:
    int id;
    std::string lineName;
    linkedList<busStop> stops; 
    linkedList<bus> buses;
};

#endif