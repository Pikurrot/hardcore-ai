# Compiler
CC = g++

# Compiler flags
CFLAGS = -Wall -std=c++14

# Include paths
INCLUDES = -I./core -I./tests

# Source files
SRCS = $(wildcard core/*.cpp tests/*.cpp deep_learning/*.cpp)

# Object files directory
OBJDIR = obj

# Object files
OBJS = $(patsubst %.cpp,$(OBJDIR)/%.o,$(SRCS))

# Executable name
MAIN = main

all: dirs $(MAIN)

dirs:
	mkdir -p $(dir $(OBJS))

$(MAIN): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS)

$(OBJDIR)/%.o: %.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c $<  -o $@

clean:
	$(RM) -r $(OBJDIR) *~ $(MAIN)
