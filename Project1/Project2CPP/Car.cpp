//
// Created by RPC on 25/05/2025.
//
#include<iostream>
#include "Car.h"
#include "Vehicles.h"
Car::Car(std::string id ,double battery , double consumption ):Vehicles(id , battery,"Car") , consumption(consumption){};
void Car::start(){
    active=true;

}

void Car::stop(){
    active = false;

}
bool Car::drive(double distance){
    if (!active){
        return false;
    }
    if (battery>consumption*distance){
        return true;
    }
    return false;

}
void Car::recharge(double amount){
    battery+=amount ;

}
std::string Car::getMetrics() const{
    return "[Car: "+id + " | Battery: " +std::to_string(battery)+"% | Type: " +type +" ]";

}
std::ostream& operator<<(std::ostream& os , const Car& car){
    os << car.getMetrics();
    return os;
}