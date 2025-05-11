
#ifndef POD_H
#define POD_H

#include <iostream>
#include <memory>
#include "Container.h"
#include <unordered_map>
#include <vector>

class Pod {
private:
    std::string  name_;
    std::vector<std::unique_ptr<Container>> containers_;
    std::unordered_map<std::string, std::string> labels_;
public:
    Pod(std::string name, std::unordered_map<std::string, std::string> labels = {});
    void addContainer (std::unique_ptr<Container> container);
    bool removeContainer(const std::string& id);
    void deploy();
    std::string getMetrics() const;
    std::string getName() const;
    friend std::ostream& operator << (std::ostream& os, const Pod& p);
    const std::vector<std::unique_ptr<Container>>& getContainers() const;

    // Bonus methods (needed for my implementation)
    double totalMemory() const;
    double totalCpu() const;
};

#endif //POD_H
