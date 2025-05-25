//
// Created by RPC on 25/05/2025.
//
#include "Vehicles.h"
#include <string>
#include <iostream>
#ifndef VEHICLE_CAR_H
#define VEHICLE_CAR_H


class Car : public Vehicles {
private:
    double consumption ;
public:
    Car(std::string id , double Battery , double consumption);
    void start() override;
    void stop() override;
    std::string getId()const ;
    std::string getType() const;
    bool drive(double distance) override;
    void recharge(double amount) override;
    std::string  getMetrics() const override;
    friend std::ostream& operator<<(std::ostream& os , const Car& car);





};


#endif //VEHICLE_CAR_H
