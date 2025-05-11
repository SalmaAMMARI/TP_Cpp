
#ifndef CLOUDEXCEPTIONS_H
#define CLOUDEXCEPTIONS_H

#include <stdexcept>
#include <string>

// Classe de base pour les exceptions liées au cloud
class CloudException : public std::runtime_error {
public:
    explicit CloudException(const std::string& message)
        : std::runtime_error(message) {}
};


class AllocationException : public CloudException {
public:
    explicit AllocationException(const std::string& message)
        : CloudException("Allocation Error: " + message) {}
};

class FileException : public CloudException {
public:
    explicit FileException(const std::string& message)
        : CloudException("File Error: " + message) {}
};

#endif //CLOUDEXCEPTIONS_H
