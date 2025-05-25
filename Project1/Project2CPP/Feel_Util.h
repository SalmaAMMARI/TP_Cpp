//
// Created by RPC on 25/05/2025.
//
#include "FeetManager.h"
#include "FleetExceptions.h"
#include <string>
#include "Vehicles.h"


#ifndef VEHICLE_FEEL_UTIL_H
#define VEHICLE_FEEL_UTIL_H




    void saveFleetMetrics(const FeetManager& manager, const std::string& filename);

    void forEachVehicle(const FeetManager& manager, const std::function<void(const Vehicles&)>& func);





#endif //VEHICLE_FEEL_UTIL_H
