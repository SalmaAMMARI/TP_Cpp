#ifndef METRICLOGGER_H
#define METRICLOGGER_H

#include "KubernetesCluster.h"
#include <iostream>

template <typename T>

class MetricLogger {
public:
    void logToStream(T& object, std::ostream& os, std::string& name) const {
        os << "Metrics for " << name << ":\n";
        os << object.getMetrics() << std::endl;
    }
};


#endif //METRICLOGGER_H
