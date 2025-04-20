
#ifndef CONTAINER_H
#define CONTAINER_H

#include <string>
#include "Resource.h"

class Container : Resource {
private:
    std::string image_;
public:
    Container(std::string id, std::string image, double cpu, double memory);
    void start() override;
    void stop() override;
    std::string getMetrics() const override;
    friend std::ostream& operator<<(std::ostream& os, const Container& c);

    // Added getter for the id, cpu and memory
    std::string getId() const;
    double getCpu() const;
    double getMemory() const ;
};



#endif //CONTAINER_H
