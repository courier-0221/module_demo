TARGET := sqliteDemo

INCLUDE := ./

COMMON_LIB := -lpthread -ldl -Wl

CXX = gcc
CPPFLAGS = -g -O2 -Wall -fPIC
CPPFLAGS += $(addprefix -I,$(INCLUDE))

FILETYPE = c
OBJS := $(MUDUOSRC)*.$(FILETYPE)


all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CXX) $(CPPFLAGS) -o $(TARGET) $(OBJS) $(COMMON_LIB)

clean:
	-rm -f $(TARGET)
	-rm -f sqlite3Test.db
