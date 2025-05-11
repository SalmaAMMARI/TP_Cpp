#ifndef SERVER_H
#define SERVER_H
#include "Resource.h"


class Server : Resource {
private:
    double available_cpu_;
    double available_memory_;
public:
    Server(std::string id, double cpu, double memory);
    bool isActive() const;
    bool allocate(double cpu, double memory);
    void start() override;
    void stop() override;
    std::string getMetrics() const override;
    friend std::ostream& operator<<(std::ostream& os, const Server& s);

    // Bonus method (needed for my implementation
    bool if_allocate(double cpu, double memory) const; // same as allocate but it just checks
};



#endif //SERVER_H
