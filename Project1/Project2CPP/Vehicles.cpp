

#include "Vehicles.h"
Vehicles::Vehicles(std::string id , double battery , std::string type):id(id) , battery(battery) , type(type){};
double Vehicles::getBattery() const {
    return battery ;

}
void Vehicles::recharge(double amount){
    battery+=amount;
}
std::string Vehicles::getId() const {
    return id ;
}
std::string Vehicles::getType() const{
    return type;
}
void Vehicles::start(){
    if (!active){
        active=true;
    }

}
void Vehicles::stop(){
    if (active){
        active = false;
    }
}

std::string Vehicles::getMetrics() const{
    return "[ " +type +" : "+id +" | Battery: "+ std::to_string(battery)+" | Type: "+ type + " ]";
}
