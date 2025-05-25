//
// Created by RPC on 25/05/2025.
//
#include <vector>
#include<string>
#include <memory>
#include "Vehicles.h"
#include "Station.h"
#include <functional>

#ifndef VEHICLE_FEETMANAGER_H
#define VEHICLE_FEETMANAGER_H


class FeetManager {
public:
    std::vector<std::shared_ptr<Vehicles>> vehicles;
    std::vector<std::shared_ptr<Station>> stations;
    void addVehicle(std::shared_ptr<Vehicles>);
    void addStation(std::shared_ptr<Station>);
    std::vector<std::shared_ptr<Vehicles>> filterVehicles(std::function<bool(std::shared_ptr<Vehicles>&)> condition) ;
    std::string getMetrics()const;
    void assignToStation(std::shared_ptr<Vehicles> vehicle , std::shared_ptr<Station> station );



    std::vector<std::shared_ptr<Vehicles>> filterVehicles(std::function<bool(const Vehicles&)> predicate);
};


#endif //VEHICLE_FEETMANAGER_H
