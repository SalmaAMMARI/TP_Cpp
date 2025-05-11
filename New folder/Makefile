# Compiler
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

# Source files
SRCS = main.cpp \
       Cloud_Util.cpp \
       Container.cpp \
       KubernetesCluster.cpp \
       Pod.cpp \
       Resource.cpp \
       Server.cpp \

# Object files (replace .cpp with .o)
OBJS = $(SRCS:.cpp=.o)

# Header dependencies (optional but good to list)
DEPS = Cloud_Util.h \
       Container.h \
       KubernetesCluster.h \
       Pod.h \
       Resource.h \
       Server.h \
       CloudExceptions.h \
       MetricLogger.h \

# Output executable
TARGET = main

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
