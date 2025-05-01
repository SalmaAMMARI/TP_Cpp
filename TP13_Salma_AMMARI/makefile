# Compiler options
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g

# Source files
SOURCES = 1_exercice.cpp 2_exercice.cpp 3_exercice.cpp 4_exercice.cpp  

# Object files
OBJECTS = $(SOURCES:.cpp=.o)

# Executable files
EXECUTABLES = $(SOURCES:.cpp=)

# Default target
all: $(EXECUTABLES)

# Rule to build each executable
%: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

# Clean up
clean:
	rm -f $(OBJECTS) $(EXECUTABLES)