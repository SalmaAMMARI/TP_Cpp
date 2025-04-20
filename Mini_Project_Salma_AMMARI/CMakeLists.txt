cmake_minimum_required(VERSION 3.29)
project(Projet1_Qadda_Salim)

set(CMAKE_CXX_STANDARD 20)

add_executable(Projet1_Qadda_Salim main.cpp
        Resource.cpp
        Resource.h
        Container.cpp
        Container.h
        Pod.cpp
        Pod.h
        Server.cpp
        Server.h
        KubernetesCluster.cpp
        KubernetesCluster.h
        Cloud_Util.cpp
        Cloud_Util.h
)
