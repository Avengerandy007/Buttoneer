# Compiler
#CXX = x86_64-w64-mingw32-g++
CXX = clang++

# SDL2 Path (Windows dev libs)
SDL2Win_PATH = /usr/include/SDL2Win

ifeq ($(CXX),clang++)
# Linux deployment
CXXFLAGS = -Wall -g $(shell sdl2-config --cflags)
LDFLAGS  = $(shell sdl2-config --libs)
else
# Windows deployment
CXXFLAGS = -Wall -g -I$(SDL2Win_PATH)/include -static-libstdc++ -static-libgcc -DSDL_MAIN_HANDLED -O2 -DNDEBUG
LDFLAGS  = -L./lib -lSDL2main -lSDL2 -mconsole#-mwindows
endif

# Files
SRCS := $(wildcard src/*.cpp)
OBJS := $(SRCS:.cpp=.o)
TARGET = Breakout

# Build app
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS) $(LDFLAGS)

# Compile .cpp to .o
src/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean
clean:
	rm -f $(TARGET) $(OBJS)
