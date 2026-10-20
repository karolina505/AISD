CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11 -pedantic
TARGET = main.out

.PHONY: all clean

all: $(TARGET)

$(TARGET): main.cpp sort.hpp
	$(CXX) $(CXXFLAGS) main.cpp -o $(TARGET)

clean:
	$(RM) $(TARGET) *.o core