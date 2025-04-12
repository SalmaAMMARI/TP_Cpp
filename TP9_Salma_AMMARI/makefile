# Nom de l'exécutable
TARGET = main

# Compilateur et options
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

# Fichiers sources
SRCS = main.cpp Account.cpp Account_Util.cpp Savings_Account.cpp Trust_Account.cpp checking_Account.cpp

# Fichiers objets générés automatiquement à partir des sources
OBJS = $(SRCS:.cpp=.o)

# Règle par défaut
all: $(TARGET)

# Règle pour l'exécutable final
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Règle pour nettoyer les fichiers générés
clean:
	rm -f $(OBJS) $(TARGET)

# Règles implicites pour compiler les .cpp en .o (optionnel ici car Make le fait automatiquement)
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
