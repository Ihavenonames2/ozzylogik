TARGET = server

SRC = main.cpp

CXX = g++

CXXFLAGS = -std=c++11

BOOST_ROOT ?= /Users/admin/boost/boost_1_82_0

INCLUDE_DIRS = $(BOOST_ROOT)/include
LIB_DIRS = $(BOOST_ROOT)/lib

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET) $(LIBS)

clean:
	rm -f $(TARGET)

