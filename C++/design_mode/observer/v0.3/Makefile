TARGET := baseDemo

#SRC := ./
#INC := ./
#LIB := -lpthread

CXX = g++
CPPFLAGS = -g -O2 -Wall -std=c++11 -I./

all :
	$(CXX) $(CPPFLAGS) -o $(TARGET) test_observer.cc

clean:
	-rm -f $(TARGET)