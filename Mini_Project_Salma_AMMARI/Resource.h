#include <iostream>

#ifndef RESOURCE_H
#define RESOURCE_H



class Resource {
protected:
    std::string id_;
    double cpu_;
    double memory_;
    bool active_;
public:
    Resource(std::string id, double cpu, double memory);
    virtual void start() = 0;
    virtual void stop() = 0;
    virtual std::string getMetrics() const = 0;
    virtual ~Resource() = default;
};



#endif //RESOURCE_H
