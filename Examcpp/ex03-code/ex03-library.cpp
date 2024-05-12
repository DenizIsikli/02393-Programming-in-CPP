#include <iostream>
#include <algorithm>
#include "ex03-library.h"
using namespace std;

// Do not modify
string ParkingArea::categoryToString(Category c)
{
    switch (c)
    {
    case CAR:
        return "car";
    case MOTORBIKE:
        return "motorbike";
    case TRUCK:
        return "truck";
    default:
        return "";
    }
}

// Do not modify
ParkingArea::ParkingArea() {
    this->parkingSpaces["LYNGBY01"] = CAR;
    this->parkingOccupancy["LYNGBY01"] = {"AB123XY", "Alice", CAR};
    this->parkingSpaces["LYNGBY02"] = CAR;
    this->parkingOccupancy["LYNGBY02"] = {"CD987WQ", "Bob", CAR};
    this->parkingSpaces["LYNGBY03"] = CAR;
    this->parkingOccupancy["LYNGBY03"] = {"EF456SA", "Claire", MOTORBIKE};
    this->parkingSpaces["LYNGBY04"] = CAR;
    this->parkingSpaces["LYNGBY05"] = TRUCK;
    this->parkingOccupancy["LYNGBY05"] = {"GH102MN", "Daisy", TRUCK};
    this->parkingSpaces["LYNGBY06"] = MOTORBIKE;
}

// Task 3(a).  Implement this method
void ParkingArea::park(string parkingSpaceID, string plate, string owner, Category category) {
    if (parkingSpaces.find(parkingSpaceID) == parkingSpaces.end()) {
        return;
    }

    if (parkingOccupancy.find(parkingSpaceID) != parkingOccupancy.end()) {
        return;
    }

    parkingOccupancy[parkingSpaceID] = { plate, owner, category };
}

// Task 3(b).  Implement this method
void ParkingArea::leave(string plate) {
    for (auto it = parkingOccupancy.begin(); it != parkingOccupancy.end(); ++it) {
        if (it->second.plate == plate) {
            parkingOccupancy.erase(it);
            return;
        }
    }
}

// Task 3(c).  Implement this method
void ParkingArea::findMisplacedVehicles() {
    for (const auto &cars : parkingSpaces) {
        if (parkingOccupancy.find(cars.first) != parkingOccupancy.end()) {
            auto &vehicle = parkingOccupancy[cars.first];

            if (vehicle.category != cars.second) {
                cout << vehicle.plate << endl;
            }
        }
    } 
}

// Task 3(d).  Implement this method
void ParkingArea::findVehicles(vector<string> plates) {  
    for (const string &plate : plates) {
        for (const auto &cars : parkingOccupancy) {
            if (cars.second.plate == plate) {
                cout << cars.first << endl;
            }
        }
    }
}

// Do not modify
void ParkingArea::display() {
    for (auto it = this->parkingSpaces.begin(); it != this->parkingSpaces.end(); it++) {
        cout << "Parking '" << it->first << "' ";
        cout << "is for a " << categoryToString(it->second) << " and ";
        if (this->parkingOccupancy.find(it->first) == this->parkingOccupancy.end()) {
            cout << "is empty" << endl;
        } else {
            cout << "contains a " << categoryToString(this->parkingOccupancy[it->first].category);
            cout << " with license plate " << this->parkingOccupancy[it->first].plate;
            cout << " belonging to " << this->parkingOccupancy[it->first].owner << endl;
        }
    }
}
