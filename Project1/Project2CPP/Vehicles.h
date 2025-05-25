
#include <string>
using namespace std;
#ifndef VEHICLE_VEHICLES_H
#define VEHICLE_VEHICLES_H


class Vehicles {
protected:
    std::string id;
    double battery ;
    bool active;
    std::string type ;
public:
    Vehicles(std::string id , double battery , std::string type);
    double getBattery() const ;
    std::string getId() const;
    std::string getType() const ;
    virtual void start() =0 ;
    virtual void stop() =0;
    virtual bool drive(double distance )=0;
    virtual void recharge(double amount )=0;
  virtual std::string getMetrics() const=0;
    virtual  ~Vehicles()=default;



};


#endif
