TARGET := TestSchedulerDemo

SRC := ../
INC := ../
LIB := -lpthread -std=c++11 -rdynamic

CXX = g++
CPPFLAGS = -g -O2 -Wall -std=c++11
CPPFLAGS += $(addprefix -I,$(INC))

FILETYPE = cc
OBJS := $(SRC)*.$(FILETYPE)

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CXX) $(CPPFLAGS) -o $(TARGET) $(OBJS) TestScheduler.cc $(LIB)

clean:
	-rm -f $(SRC)*.o $(TARGET)
