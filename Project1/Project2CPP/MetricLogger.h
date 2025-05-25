//
// Created by RPC on 25/05/2025.
//
#include <iostream>
#include <fstream>
#include "FleetExceptions.h"
#ifndef VEHICLE_METRICLOGGER_H
#define VEHICLE_METRICLOGGER_H


template<typename T>
class MetricLogger {
public:
    static void logToStream(const T& obj, std::ostream& os, const std::string& label){
        os<<label<<obj.getMetrics()<<std::endl;

    };
    static void logToFile(const T& obj, const std::string& filename, const std::string& label){
        std::ofstream outFile(filename);
        if (!outFile.is_open()){
            throw FileException(filename);
        }
        outFile<<label << obj.getMetrics()<<std::endl;
        outFile.close();
    };
};

#endif //VEHICLE_METRICLOGGER_H
