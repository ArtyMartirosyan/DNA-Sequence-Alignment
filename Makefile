CC = g++
CFLAGS = -std=c++11 -c -g -Og -Wall -Werror -pedantic -O2
OBJ = ED.o main.o
DEPS = ED.cpp ED.h main.cpp
LIBS = -lsfml-system
EXE = ED

all: $(OBJ)
	$(CC) $(OBJ) -o $(EXE) $(LIBS)

%.o: %.cpp %.h
	$(CC) $(CFLAGS)  -c $< -o $@

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm $(OBJ) $(EXE)