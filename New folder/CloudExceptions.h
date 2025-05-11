
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

// Exception pour les erreurs d'allocation de ressources
class AllocationException : public CloudException {
public:
    explicit AllocationException(const std::string& message)
        : CloudException("Allocation Error: " + message) {}
};

// Exception pour les erreurs liées aux fichiers
class FileException : public CloudException {
public:
    explicit FileException(const std::string& message)
        : CloudException("File Error: " + message) {}
};

#endif //CLOUDEXCEPTIONS_H
