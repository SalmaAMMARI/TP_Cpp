//
// Created by RPC on 25/05/2025.
//
#include <vector>
#include <string>
#include <memory>
#include <functional>
#include "Station.h"
#include <algorithm>

#include "FeetManager.h"
void FeetManager::addVehicle(std::shared_ptr<Vehicles> vehicle){
    vehicles.push_back(vehicle);



}
void FeetManager::addStation(std::shared_ptr<Station> station){
    stations.push_back(station);

}
void FeetManager::assignToStation(std::shared_ptr<Vehicles> vehicle , std::shared_ptr<Station> station ){
    auto it =  std::find(stations.begin() , stations.end(), station);
    if (it!=stations.end()){
        station->addVehicle(vehicle);



    }

}

std::vector<std::shared_ptr<Vehicles>> FeetManager::filterVehicles(std::function<bool(std::shared_ptr<Vehicles>&)> condition) {
    std::vector<std::shared_ptr<Vehicles>> result ;
    std::copy_if(vehicles.begin() , vehicles.end(), std::back_inserter(result) , condition);
return result;
};
std::string FeetManager::getMetrics() const{
    std::string flotte ="";
    for (auto& it: vehicles){
        flotte+=it->getMetrics()    +"\n";

    }
    return flotte;

}
std::vector<std::shared_ptr<Vehicles>> FeetManager::filterVehicles(std::function<bool(const Vehicles&)> predicate){
    std::vector<std::shared_ptr<Vehicles>> result ;
    for (auto& it : vehicles){
        if (predicate(*it)){
            result.push_back(it);
        }
    }
    return result ;

};