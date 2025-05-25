TARGET = main
SOURCES = main.cpp Car.cpp Track.cpp FeetManager.cpp Station.cpp FleetExceptions.cpp Feel_Util.cpp MetricLogger.cpp

all:
	g++ -std=c++17 $(SOURCES) -o $(TARGET)

clean:
	rm -f $(TARGET)

run: all
	./$(TARGET)