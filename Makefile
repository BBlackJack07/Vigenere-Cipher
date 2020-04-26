CC = g++
CXXFLAGS = -std=c++17 -Wall -O2 -march=native -c
LDFLAGS=
SOURCES=main.cpp vigenere.cpp
HEADERS=vigenere.hpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLES=vigenere

all: $(EXECUTABLES) $(SOURCES) $(HEADERS)

$(EXECUTABLES): $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@

.cpp.o:
	$(CC) $(CXXFLAGS) $< -o $@

clean:
	rm $(EXECUTABLES) $(OBJECTS)

