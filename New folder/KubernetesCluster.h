
#ifndef KUBERNETESCLUSTER_H
#define KUBERNETESCLUSTER_H

#include "Server.h"
#include "Pod.h"
#include <vector>
#include <memory>
#include <functional>

class KubernetesCluster {
private:
    std::vector<std::shared_ptr<Server>> nodes_;
    std::vector<std::unique_ptr<Pod>> pods_;
public:
    void addNode(std::shared_ptr<Server> node);
    bool removePod(const std::string& name);
    void deployPod(std::unique_ptr<Pod> pod);
    Pod* getPod(const std::string& name);
    const std::vector<std::unique_ptr<Pod>>& getPods() const;
    std::vector<std::shared_ptr<Server>> getFilteredServers(const std::function<bool(const Server&)>& filter) const;
    std::string getMetrics() const;
    friend std::ostream& operator<<(std::ostream& os, const KubernetesCluster& c);
};



#endif //KUBERNETESCLUSTER_H
