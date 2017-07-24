#
# Creation rules for 2dGameEngine

CXX=g++
CXXFLAGS= -Wall -Wextra -O2 -std=c++11
HEADER= -IC:/Libraries/include
LIBRARY= -LC:/Libraries/lib_x86
TARGET= test/a.out

SRCS= $(wildcard src/*.cpp)
OBJS= $(patsubst src/%.cpp,obj/%.o,$(SRCS))

default: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(HEADER) $(LIBRARY) -lSDL2 -lSDL2main $^ -o $@

obj/%.o: $(SRCS)
	$(CXX) $(CXXFLAGS) $(HEADER) -c $< -o $@

clean:
	rm *.out
	
