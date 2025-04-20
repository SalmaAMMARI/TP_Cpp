
#include "Container.h"
#include <string>

Container::Container(std::string id, std::string image, double cpu, double memory)
    : Resource(id, cpu, memory), image_(image) {}

void Container::start() {
    active_ = true;
}

void Container::stop() {
    active_ = false;
}

std::string Container::getMetrics() const {
    return "[Container: " + id_ + ": " + std::to_string(cpu_) + ", " + std::to_string(memory_) + ", " + image_ + ']';
}

std::ostream& operator<<(std::ostream& os, const Container& c) {
    os << c.getMetrics() << '\n';
    return os;
}

std::string Container::getId() const {
    return id_;
}
double Container::getCpu() const {
    return cpu_;
}
double Container::getMemory() const {
    return memory_;
}

