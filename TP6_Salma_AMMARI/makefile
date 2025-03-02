# Définition du compilateur
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11

# Noms des exécutables
EXECS = exo1 exo2 exo3 exo4 exo5 

# Règle par défaut
all: $(EXECS)

# Compilation de chaque exercice
exo1: 1-exercice.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

exo2: 2-exercice.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

exo3: 3-exercice.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

exo4: 4-exercice.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

exo5: 5-exercice.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@



# Nettoyage des exécutables
clean:
	rm -f $(EXECS)
