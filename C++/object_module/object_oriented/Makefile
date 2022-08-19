TARGET := orientedDemo

#SRC := ./
#INC := ./
LIB := -lpthread

CXX = g++
CPPFLAGS = -g -O2 -Wall -std=c++11 -I./

all :
	$(CXX) $(CPPFLAGS) -o $(TARGET) Thread.cc Thread_test.cc $(LIB)

clean:
	-rm -f $(TARGET)
