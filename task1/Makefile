TARGET = task1

SRC = main.cpp

CXX = g++

CXXFLAGS = -std=c++20 -Wall

QT_LIBS = $(shell pkg-config --libs --cflags Qt6Core Qt6Widgets Qt6Sql)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET) $(QT_LIBS)

clean:
	rm -f $(TARGET)
