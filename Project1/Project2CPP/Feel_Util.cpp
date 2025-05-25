//
// Created by RPC on 25/05/2025.
//

#include "Feel_Util.h"
#include "FeetManager.h"

#include <fstream>
#include <stdexcept>
void forEachVehicle(const FeetManager& manager, const std::function<void(const Vehicles&)>& func){
    for (auto& it: manager.vehicles){
        func(*it);
    }
};
void saveFleetMetrics(const FeetManager& manager, const std::string& filename){
std::ofstream outFile(filename);
if (!outFile.is_open()){
    throw FileException(filename);
}
try{
    outFile<<manager.getMetrics();
    outFile.close();
}catch(const std::exception& e){
    throw FileException("write erro for the file"+filename+"-"+e.what());
}
};
