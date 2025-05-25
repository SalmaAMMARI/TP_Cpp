//
// Created by RPC on 25/05/2025.
//
#include <stdexcept>
#include <string>

#ifndef VEHICLE_FLEETEXCEPTIONS_H
#define VEHICLE_FLEETEXCEPTIONS_H


class FleetException :public std::runtime_error{
public:
    explicit FleetException(const std::string& message): std::runtime_error("Exception capturée:Fleet Error" + message){};



};
class BatteryException:public FleetException{
public:

    explicit BatteryException(const std::string& message):FleetException("Battery Error: "+message){

    }

};
class FileException:public FleetException{
public:
    explicit FileException(const std::string& message): FleetException("file can not be accessed"+message){}

};



#endif //VEHICLE_FLEETEXCEPTIONS_H
