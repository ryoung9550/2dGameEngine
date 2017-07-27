#
# Creation rules for 2dGameEngine

CXX=g++
CXXFLAGS= -Wall -Wextra -O2 -std=c++1z
HEADER= -I/usr/local/include
LIBRARY= -L/usr/local/lib
TARGET= test/a.out

SRCS= $(wildcard src/*.cpp)
OBJS= $(patsubst src/%.cpp,obj/%.o,$(SRCS))

default: $(TARGET)

$(TARGET): obj/GeInit.o obj/GeObj.o obj/Window.o obj/Texture.o obj/DrawObj.o obj/test.o
	$(CXX) $(CXXFLAGS) $(HEADER) $(LIBRARY) -lSDL2 $^ -o $@

obj/GeInit.o: src/GeInit.cpp
	$(CXX) $(CXXFLAGS) $(HEADER) $(LIBRARY) -c $^ -o $@

obj/GeObj.o: src/GeObj.cpp
	$(CXX) $(CXXFLAGS) $(HEADER) $(LIBRARY) -c $^ -o $@

obj/Window.o: src/Window.cpp
	$(CXX) $(CXXFLAGS) $(HEADER) $(LIBRARY) -c $^ -o $@

obj/Texture.o: src/Texture.cpp
	$(CXX) $(CXXFLAGS) $(HEADER) $(LIBRARY) -c $^ -o $@

obj/DrawObj.o: src/DrawObj.cpp
	$(CXX) $(CXXFLAGS) $(HEADER) $(LIBRARY) -c $^ -o $@

obj/test.o: src/test.cpp
	$(CXX) $(CXXFLAGS) $(HEADER) $(LIBRARY) -c $^ -o $@

clean:
	rm obj/*.o
	
