
#include "Server.h"

Server::Server(std::string id, double cpu, double memory)
    : Resource(id, cpu, memory), available_cpu_(cpu), available_memory_(memory) {}

bool Server::allocate(double cpu, double memory) {
    if (available_cpu_ >= cpu && available_memory_ > memory) {
        available_cpu_ -= cpu;
        available_memory_ -= memory;
        return true;
    }
    else {
        return false;
    }
}

void Server::start() {
    active_ = true;
}

void Server::stop() {
    active_ = false;
}

std::string Server::getMetrics() const {
    return "[Server: " + id_ + ": " + std::to_string(cpu_) + " CPU, " +
       std::to_string(memory_) + " Memory, Available: " +
       std::to_string(available_cpu_) + " CPU, " +
       std::to_string(available_memory_) + " Memory]";
}

std::ostream& operator<<(std::ostream& os, const Server& s) {
    os << s.getMetrics() << std::endl;
    return os;
}

// Bonus method (needed for my implementation)

bool Server::if_allocate(double cpu, double memory) const {
    if (available_cpu_ >= cpu && available_memory_ > memory) {
        return true;
    }
    else {
        return false;
    }
}
