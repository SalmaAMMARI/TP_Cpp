//
// Created by RPC on 25/05/2025.

#include<vector>
#include<iostream>
#include<memory>
#include <string>

#include "Station.h"
void Station::addVehicle(std::shared_ptr<Vehicles> vehicle) {
    queue.push_back(vehicle);

}
void Station::process(double amount){
    for (auto& it: queue){
        (*it).recharge(amount);
    }
}
std::string  Station::getMetrics()const {
    std::string metrics="";
    for (auto& it:queue){
        metrics+=it->getMetrics()+"\n";

    }
    return metrics;

}
std::ostream& operator<<(std::ostream& os , const Station& station){
    os<<station.getMetrics();
    return os;
}