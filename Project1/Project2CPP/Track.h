//
// Created by RPC on 25/05/2025.
//
#include "Vehicles.h"

#include <string>
#ifndef VEHICLE_TRACK_H
#define VEHICLE_TRACK_H


class Track : public Vehicles{
private:
    double consumption ;
public:
    Track( std::string id , double battery , double consumption );
    void start() override;
    void stop() override;
    bool drive(double distance) override;
    void recharge( double amount) override;
    std::string getMetrics() const ;
    friend std::ostream& operator<<(std::ostream& os , const Track& track );




};


#endif //VEHICLE_TRACK_H
