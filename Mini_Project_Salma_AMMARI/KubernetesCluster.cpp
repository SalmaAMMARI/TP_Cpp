
#include "KubernetesCluster.h"

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
    double memory = pod->totalMemory();
    double cpu = pod->totalCpu();
    for (auto& serv : nodes_) {
        if (serv->allocate(cpu, memory)) {
            pod->deploy();
            pods_.push_back(std::move(pod));
            return;
        }
    }
}

bool KubernetesCluster::schedulePod(Pod &pod) {
    double memory = pod.totalMemory();
    double cpu = pod.totalCpu();
    for (auto& serv : nodes_) {
        if (serv->if_allocate(cpu, memory)) {
            return true;
        }
    }
    return false;
}

Pod *KubernetesCluster::getPod(const std::string &name) {
    for (auto itr = pods_.begin(); itr != pods_.end(); ++itr) {
        if ((*itr)->getName() == name) {
            return itr->get();
        }
    }
    return nullptr;
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



