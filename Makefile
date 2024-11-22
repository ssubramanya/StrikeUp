# Define variables
PROTO_SRC = Proto/Trades.proto# Path to your .proto file
PROTO_GEN_DIR = Proto# Directory where generated files are placed
PROTO_CC = $(PROTO_GEN_DIR)/Trades.pb.cc
PROTO_H = $(PROTO_GEN_DIR)/Trades.pb.h

LIB_PATH = -L/home/subramanya/Downloads/protobuf-3.11.2/src/.libs

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -I/usr/include -I$(PROTO_GEN_DIR) -lserved -lboost_system -lpthread # Include the Protobuf header directory

# Protobuf compiler
PROTOC = protoc
PROTOC_FLAGS = --cpp_out=$(PROTO_GEN_DIR)

# Default target
all: main

# Rule to generate .pb.cc and .pb.h
$(PROTO_CC) $(PROTO_H): $(PROTO_SRC)
	@mkdir -p $(PROTO_GEN_DIR)  # Ensure the directory exists
	$(PROTOC) $(PROTOC_FLAGS) $<

# Define your project source files
SRCS = main.cpp orderBook.cpp $(PROTO_CC)
OBJS = $(SRCS:.cpp=.o)
TARGET = strikeup

# Build the executable
main: $(OBJS)
	$(CXX) $(OBJS) -g -o $(TARGET) $(LIB_PATH) $(CXXFLAGS) -lprotobuf

# Rule to clean up
clean:
	rm -f $(OBJS) main

# Rule for compiling .cpp files into .o files
%.o: %.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

