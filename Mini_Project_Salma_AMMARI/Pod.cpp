
#include "Pod.h"
#include <string>

Pod::Pod(std::string name, std::unordered_map<std::string, std::string> labels)
    : name_(name), labels_(labels) {}

void Pod::addContainer(std::unique_ptr<Container> container) {
    containers_.push_back(std::move(container));
}

bool Pod::removeContainer(const std::string &id) {
    for (auto it = containers_.begin(); it != containers_.end(); ++it) {
        if ((*it)->getId() == id) {
            containers_.erase(it);
            return true;
        }
    }
    return false;
}


void Pod::deploy() {
    for (auto& c : containers_) {
        c->start();
    }
}

std::string Pod::getMetrics() const {
    std::string metrics = "[Pod: " + name_ + "]\n" ;
    for (const auto& container : containers_) {
        metrics += container->getMetrics() + "\n";
    }
    return metrics;
}

std::ostream& operator<<(std::ostream& os, const Pod& p) {
    os << p.getMetrics();
    return os;
}

const std::vector<std::unique_ptr<Container> >& Pod::getContainers() const {
    return containers_;
}

// Bonus methods (needed for my implementations)

double Pod::totalMemory() const {
    double total = 0;
    for (const auto& container : containers_) {
        total += container->getMemory();
    }
    return total;
}

double Pod::totalCpu() const {
    double total = 0;
    for (const auto& container : containers_) {
        total += container->getCpu();
    }
    return total;
}

std::string Pod::getName() const {
    return name_;
}
