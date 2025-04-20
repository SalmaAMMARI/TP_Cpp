
#ifndef CLOUD_UTIL_H
#define CLOUD_UTIL_H

#include "KubernetesCluster.h"


void display(const KubernetesCluster& cluster);
void deployPods(KubernetesCluster& cluster, std::vector<std::unique_ptr<Pod>>& pods);


#endif //CLOUD_UTIL_H
