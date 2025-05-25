//
// Created by RPC on 25/05/2025.
//
#include <string>
#include<iostream>
#include <vector>
#include <memory>
#include "Vehicles.h"
#ifndef VEHICLE_STATION_H
#define VEHICLE_STATION_H


class Station {
public:
    std::string name;
    std::vector<std::shared_ptr<Vehicles>> queue;
    void addVehicle(std::shared_ptr<Vehicles> vehicle);
    void process(double amount);
    std::string getMetrics() const;
    friend std::ostream& operator<<(std::ostream& , const Station& station);



};


#endif //VEHICLE_STATION_H
