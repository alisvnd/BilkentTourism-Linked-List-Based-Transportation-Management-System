#include "busLine.h"
#include "bus.h"
#include <string>
#include <iostream>

using namespace std;

busLine::busLine(const int lineId, const std::string& lineName)
    : id(lineId), lineName(lineName), stops(), buses() {}


int busLine::getId() const 
{
    return id;
}

std::string busLine::getLineName() const 
{
    return lineName;
}

bool busLine::addStop(const busStop& stop) 
{
    return stops.addSorted(stop);
}
bool busLine::removeStop(int id) 
{
    return stops.remove(id);
}

bool busLine::addBus(const bus& busObj) 
{
    return buses.addSorted(busObj);
}
bool busLine::removeBus(int id) 
{
    return buses.remove(id);
}
bool busLine::hasStop(int id) const{
    return stops.contains(id);
}
void busLine::printStops() const {
    if (stops.getSize() == 0) {
        cout << "Cannot print stops. There is no stop to show." << endl;
        return; 
    }

    typename linkedList<busStop>::Node const* current = stops.getHead();
    bool titleDone = false;
    while (current) {
        if(!titleDone){
            cout << "Stops in bus line " << id << " (" << lineName << ") :" << endl;
            titleDone = true;
        }
        cout << "Stop " << current->data.getId() << " : " << current->data.getName() << std::endl;
        current = current->next;
    }
}

void busLine::printBuses() const {
    if (buses.getSize() == 0) {
        cout << "There are no bus to show in line " << id << " (" << lineName << ")." << endl;
        return;
    }
    typename linkedList<bus>::Node const* current = buses.getHead();
    cout << "Busses and their drivers assigned to the line " << id << " (" << lineName << "):" << endl;
    while (current) {
        cout << "Bus " << current->data.getId() << " : " << current->data.getdriverName() << endl;
        current = current->next;
    }
}

void busLine::printAssignedBuses() const {
    typename linkedList<bus>::Node const* currentBusNode = buses.getHead();
    if (!currentBusNode) {
        cout << "None";
    } else {
        cout << "[";
        while (currentBusNode) {
            cout << currentBusNode->data.getId();
            if (currentBusNode->next) {
                cout << ",";
            }
            currentBusNode = currentBusNode->next;
        }
        cout << "]"; 
    }
    cout << endl; 
}
const linkedList<bus>& busLine::getBuses() const {
    return buses;
}