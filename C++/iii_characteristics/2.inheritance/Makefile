TARGET := baseDemo

LIB := -lpthread

CXX = g++
CPPFLAGS = -g -O2 -Wall -std=c++11 -I./

all :
	$(CXX) $(CPPFLAGS) -o $(TARGET) test01.cc $(LIB)

clean:
	-rm -f $(TARGET)