#include "Cloud_Util.h"
#include <iostream>
#include <fstream>
#include "CloudExceptions.h"

void display(const KubernetesCluster &cluster) {
    std::cout << cluster << std::endl;
}

void deployPods(KubernetesCluster &cluster, std::vector<std::unique_ptr<Pod>> &pods) {
    for (auto &pod : pods) {
        std::cout << "-> Déploiement du Pod " << *pod;
        try {
            cluster.deployPod(std::move(pod));
        }
        catch(AllocationException& e) {
            std::cerr << "Allocation error: " << e.what();
        }
    }
    pods.clear();
}

void forEachContainer(const KubernetesCluster &cluster, const std::function<void(const Container &)> &func) {
    for (const auto &pod : cluster.getPods()) {
        for (const auto &container : pod->getContainers()) {
            func(*container);
        }
    }
}


void saveClusterMetrics(const KubernetesCluster &cluster, const std::string &filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << cluster.getMetrics();
        std::cout << "Métriques sauvegardées avec succès." << std::endl;
    }
    else {
        throw FileException("Error opening the file");
    }
}
