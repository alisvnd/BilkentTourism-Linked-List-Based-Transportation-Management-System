#include "BilkentTourism.h"
#include <iostream>
#include <string>

using namespace std;


BilkentTourism::BilkentTourism(): lines(), stops(), buses() {
}

BilkentTourism::~BilkentTourism() {
}


void BilkentTourism::addBusLine( const int lineId, const string lineName ) {
    if (lines.contains(lineId)){
        cout<<"Cannot add line. There is already a bus line with ID " << lineId << "." <<endl;
    }
    else{
    busLine newLine(lineId, lineName);
    lines.addSorted(newLine);
    cout<<"Added bus line "<< lineId << "." <<endl;
    }
}

void BilkentTourism::removeBusLine( const int lineId ) {
    busLine* linePtr = lines.getById(lineId);

    if (linePtr == nullptr) {
        cout << "Cannot remove bus line. There is no bus line with ID " << lineId << "." << endl;
    }
    else {
        typename linkedList<bus>::Node const* currentBusNode = linePtr->getBuses().getHead();
        while(currentBusNode) {
            buses.remove(currentBusNode->data.getId());
            currentBusNode = currentBusNode->next;
        }
        lines.remove(lineId);
        cout << "Removed bus line " << lineId << "." << endl;
    }
}

void BilkentTourism::printBusLines() const {
    if(lines.getSize() == 0){
        cout<< "There are no bus lines to show."<<endl;
    }
    else{
        cout << "Bus lines in the system:" << endl;
        typename linkedList<busLine>::Node const* current = lines.getHead();
        while(current){
            cout << "Line " << current->data.getId() << " : " << current->data.getLineName() << endl;
            current = current->next;
        }
    }
}



void BilkentTourism::addStop( const int stopId, const string stopName ) {
    if(stops.contains(stopId)){
        cout << "Cannot add stop. BilkentTourism already contains stop " << stopId << "." << endl;
    }
    else{
        busStop newStop(stopId, stopName);
        cout << "Added stop " << stopId << "."<< endl;
        stops.addSorted(newStop);
    }
}

void BilkentTourism::removeStop( const int stopId ) {
    if(stops.contains(stopId)){
        typename linkedList<busLine>::Node const* current = lines.getHead();
        while (current) {
            if (current->data.hasStop(stopId)) {
                cout << "Cannot remove stop " << stopId << ". The stop is currently in use." << endl;
                return;
            }
            current = current->next;
        }
        stops.remove(stopId);
        cout << "Removed stop " << stopId << "." << endl;
    }
    else{
        cout << "Cannot remove stop " << stopId << ". There is no bus stop with ID " << stopId << "." << endl;
    }
}

void BilkentTourism::addStopToLine( const int stopId, const int lineId ) {
    if (!stops.contains(stopId)) {
        cout << "Cannot add stop. There is no stop with ID " << stopId << "." << endl;
        return;
    }
    if (!lines.contains(lineId)) {
        cout << "Cannot add stop. There is no line with ID " << lineId << "." << endl;
        return;
    }
    busLine* linePtr = lines.getById(lineId);
    busStop* stopPtr = stops.getById(stopId);
    if (linePtr->hasStop(stopId)) {
        cout << "Cannot add stop. Line " << lineId << " already contains stop " << stopId << "." << endl;
        return;
    }

    linePtr->addStop(*stopPtr);
    cout << "Added stop " << stopId << " to line " << lineId << " (" << linePtr->getLineName() << ")." << endl;
}

void BilkentTourism::removeStopFromLine( const int stopId, const int lineId ) {
    busLine* linePtr = lines.getById(lineId);
    if (!linePtr) {
        cout << "Cannot remove stop. There is no line with ID " << lineId << "." << endl;
        return;
    }
    if (linePtr->removeStop(stopId)) {
        cout << "Removed stop " << stopId << " from line " << lineId << "." << endl;
    } else {
        cout << "Cannot remove stop. Line " << lineId << " does not have stop " << stopId << "." << endl;
    }
}

void BilkentTourism::printStops( const int lineId ) const {
    const busLine* linePtr = lines.getById(lineId);

    if (!linePtr) {
        cout << "Cannot print stops. There is no line with ID " << lineId << "." << endl;
        return;
    }
    
    linePtr->printStops();
}



void BilkentTourism::assignBus( const int busId, const string driverName, const int lineId) {
    busLine* linePtr = lines.getById(lineId);

    if (!linePtr) {
        cout << "Cannot assign bus. There is no line with ID " << lineId << "." << endl;
        return;
    }
    if (buses.contains(busId)) {
        cout << "Cannot assign bus. Bus " << busId << " is already assigned to a line." << endl;
        return;
    }
    bus newBus(busId, driverName, linePtr);
    buses.addSorted(newBus);
    linePtr->addBus(newBus);
    cout << "Bus " << busId << " with driver " << driverName << " is assigned to line " << lineId << " (" << linePtr->getLineName() << ")." << endl;
}

void BilkentTourism::unassignBus( const int busId ) {
    bus* busPtr = buses.getById(busId); 
    if (!busPtr) {
        cout << "Cannot unassign bus. There is no bus with ID " << busId << "." << endl;
        return;
    }
    busLine* linePtr = busPtr->getLine();
    if (linePtr) {
        linePtr->removeBus(busId);
    }
    buses.remove(busId);
    cout << "Bus " << busId << " is unassigned from line " << linePtr->getId() << " (" << linePtr->getLineName() << ")." << endl;
}

void BilkentTourism::printBussesInLine( const int lineId ) const {
    const busLine* linePtr = lines.getById(lineId);
    if (!linePtr) {
        cout << "Cannot print busses. There is no line with ID " << lineId << "." << endl;
        return;
    }
    linePtr->printBuses();
}

void BilkentTourism::printBussesPassingStop( const int stopId ) const {
    const busStop* stopPtr = stops.getById(stopId);

    if (!stopPtr) {
        cout << "Cannot print buses. There is no stop with ID " << stopId << "." << endl;
        return;
    }
    
    int linesPassingCount = 0;
    
    typename linkedList<busLine>::Node const* current = lines.getHead();
    bool headerPrinted = false; 

    while (current) {
        if (current->data.hasStop(stopId)) {
            linesPassingCount++;
            if (!headerPrinted) {
                cout << "Buses and their assigned lines passing the stop " << stopId << " (" << stopPtr->getName() << "):" << endl;
                headerPrinted = true;
            }
            cout << "Line " << current->data.getId() << " (" << current->data.getLineName() << ") : ";
            current->data.printAssignedBuses();
        }
        current = current->next;
    }

    if (linesPassingCount == 0 && headerPrinted == false) {
        cout << "Cannot print buses. No lines pass through the stop." << endl;
    }
}