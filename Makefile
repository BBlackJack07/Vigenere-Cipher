CC = g++
CXXFLAGS = -std=c++17 -Wall -O2 -march=native -c
LDFLAGS=
SOURCES=crypt.cpp decrypt.cpp vigenere.cpp
HEADERS=vigenere.hpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLES=crypt decrypt

all: $(EXECUTABLES) $(SOURCES) $(HEADERS)

$(EXECUTABLES): $(OBJECTS)
	$(CC) $(LDFLAGS) crypt.o   vigenere.o -o crypt
	$(CC) $(LDFLAGS) decrypt.o vigenere.o -o decrypt

.cpp.o:
	$(CC) $(CXXFLAGS) $< -o $@

clean:
	rm $(EXECUTABLES) $(OBJECTS)

