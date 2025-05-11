
#include "KubernetesCluster.h"
#include "CloudExceptions.h"

void KubernetesCluster::addNode(std::shared_ptr<Server> node) {
    nodes_.push_back(node);
}

bool KubernetesCluster::removePod(const std::string &name) {
    for (auto itr = pods_.begin(); itr != pods_.end(); ++itr) {
        if ((*itr)->getName() == name) {
            pods_.erase(itr);
            return true;
        }
    }
    return false;
}

void KubernetesCluster::deployPod(std::unique_ptr<Pod> pod) {
    try{
        double memory = pod->totalMemory();
        double cpu = pod->totalCpu();
        for (auto& serv : nodes_) {
            if (serv->allocate(cpu, memory)) {
                pod->deploy();
                std::cout << "Déploiement du Pod " << *pod;
                std::cout << "sur le noeud " << std::endl << *serv << std::endl;
                pods_.push_back(std::move(pod));
                return;
            }
        }
    }
    catch (const AllocationException& e) {
        std::cerr << "Allocation failed: " << e.what() << std::endl;
    }
    catch (const FileException& e) {
        std::cerr << "File error: " << e.what() << std::endl;
    }
}

std::vector<std::shared_ptr<Server> > KubernetesCluster::getFilteredServers(const std::function<bool(const Server &)> &filter) const {
    std::vector<std::shared_ptr<Server>> filteredServers;
    for (const auto& node : nodes_) {
        if (filter(*node)) {
            filteredServers.push_back(node);
            std::cout << node->getMetrics() << std::endl;
        }
    }
    return filteredServers;
}


Pod *KubernetesCluster::getPod(const std::string &name) {
    for (auto itr = pods_.begin(); itr != pods_.end(); ++itr) {
        if ((*itr)->getName() == name) {
            return itr->get();
        }
    }
    return nullptr;
}

const std::vector<std::unique_ptr<Pod> > &KubernetesCluster::getPods() const {
    return pods_;
}


std::string KubernetesCluster::getMetrics() const {
    std::string metrics = "Kubernetes Cluster Metrics:\n";
    for (const auto& node : nodes_) {
        metrics += node->getMetrics() + "\n";
    }
    for (const auto& pod : pods_) {
        metrics += pod->getMetrics() + "\n";
    }
    return metrics;
}

std::ostream& operator<<(std::ostream& os, const KubernetesCluster& c) {
    os << c.getMetrics();
    return os;
}



