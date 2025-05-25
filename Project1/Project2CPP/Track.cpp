//
// Created by RPC on 25/05/2025.
//
#include <string>
#include<iostream>

#include "Track.h"
Track::Track( std::string id , double battery , double consumption):Vehicles(id , battery , "Track"), consumption(consumption){};
void Track::start() {
    active = true;
}
void Track::stop(){
    active =false;
}
bool Track::drive(double distance){
    if (!active){
        return false;
    }
    if (battery>consumption*distance){
        return true;
    }
    return false;

}
void Track::recharge(double amount){
    battery+=amount ;

}
std::string Track::getMetrics() const{
    return "[Track: "+id + " | Battery: " +std::to_string(battery)+"% | Type: " +type +" ]";

}
std::ostream& operator<<(std::ostream& os , const Track& track){
    os << track.getMetrics();
    return os;
}

