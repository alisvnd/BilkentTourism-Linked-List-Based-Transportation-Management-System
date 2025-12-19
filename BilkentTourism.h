#ifndef BILKENTTOURISM_H
#define BILKENTTOURISM_H

#include "bus.h"
#include "busLine.h"
#include "busStop.h"
#include "linkedList.h"
#include <iostream>

using namespace std;

class BilkentTourism{
private:
    linkedList<busLine> lines;
    linkedList<busStop> stops;
    linkedList<bus> buses; // bus assignda oluştur unassignda removela
public:
    BilkentTourism();
    ~BilkentTourism();

    void addBusLine( const int lineId, const string lineName );
    void removeBusLine( const int lineId );
    void printBusLines() const;

    void addStop( const int stopId, const string stopName );
    void removeStop( const int stopId );
    void addStopToLine( const int stopId, const int lineId );
    void removeStopFromLine( const int stopId, const int lineId );
    void printStops( const int lineId ) const;

    void assignBus( const int busId, const string driverName, const int lineId);
    void unassignBus( const int busId );
    void printBussesInLine( const int lineId ) const;
    void printBussesPassingStop( const int stopId ) const;

};

#endif