
#include "Container.h"
#include <string>
#include <iomanip>

Container::Container(std::string id, std::string image, double cpu, double memory)
    : Resource(id, cpu, memory), image_(image) {}

void Container::start() {
    active_ = true;
}

void Container::stop() {
    active_ = false;
}

std::string Container::getMetrics() const {
    // Utiliser std::ostringstream, std::setw, std::left pour aligner les colonnes.
    std::ostringstream oss;
    oss << "[Container: " << std::setw(10) << std::left << id_
        << " | Image: " << std::setw(15) << std::left << image_
        << " | CPU: " << std::setw(5) << std::left << cpu_
        << " | Memory: " << std::setw(7) << std::left << memory_
        << "]";
    return oss.str();
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

