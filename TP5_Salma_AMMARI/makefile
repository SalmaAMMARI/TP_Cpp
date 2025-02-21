# Définition du compilateur
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11

# Noms des exécutables
EXECS = exo1 exo2 exo3 exo4 exo5 exo6

# Règle par défaut
all: $(EXECS)

# Compilation de chaque exercice
exo1: exo1.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

exo2: exo2.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

exo3: exo3.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

exo4: exo4.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

exo5: exo5.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

exo6: exo6.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

# Nettoyage des exécutables
clean:
	rm -f $(EXECS)
