#include "Server.h"
#include "CloudExceptions.h"
#include <iostream>
#include <iomanip>

Server::Server(std::string id, double cpu, double memory)
    : Resource(id, cpu, memory), available_cpu_(cpu), available_memory_(memory) {}

bool Server::allocate(double cpu, double memory) {
    try {
        if (!active_) {
            throw AllocationException("Serveur" + id_ + " est inactif");
        }
        if (cpu > available_cpu_ || memory > available_memory_) {
            throw AllocationException("Serveur " + id_ + " n'a pas assez de ressources");
        }
        available_cpu_ -= cpu;
        available_memory_ -= memory;
        return true;
    }
    catch(const AllocationException& e) {
        std::cerr << "Exception capturée : " << e.what() << std::endl;
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
    std::ostringstream oss;
    // example output: [Server: nodeX | Total: 12 CPU, 12048 MB | Free: 6 CPU, 8976 MB]
    oss << "[Server: " << std::setw(10) << std::left << id_
        << " | Total: " << std::setw(5) << std::left << cpu_
        << " CPU, " << std::setw(7) << std::left << memory_
        << " MB | Free: " << std::setw(5) << std::left << available_cpu_
        << " CPU, " << std::setw(7) << std::left << available_memory_
        << " MB]";
    return oss.str();
}

bool Server::isActive() const {
    return active_;
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