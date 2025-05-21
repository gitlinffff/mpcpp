# ---- Variables ----
CXX = g++
CXXFLAGS = -std=c++11 -Wall
TARGET = main
OBJS = main.o virtual_temperature.o

# ---- Build Rule ----
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# ---- Compile Rules ----
# declare: main.o needs built if either main.cpp or virtual_temperature.hpp changes.
main.o: main.cpp virtual_temperature.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

virtual_temperature.o: virtual_temperature.cpp virtual_temperature.hpp
	$(CXX) $(CXXFLAGS) -c virtual_temperature.cpp

# ---- Clean Rule ----
clean:
	rm -f $(OBJS) $(TARGET)
