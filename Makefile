CC = g++
CFLAGS = -O2 -Wall -std=c++11
SRC = disk.cpp disk.h main.cpp system.cpp system.h 
EXEC = program
OBJ = $(SRC:.cpp=.o) #converts .cpp to .o

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXEC)
	@echo "Build complete"

clean:
	rm -f $(EXEC)
	find . -name "*.o" - type f -delete
	@echo "Clean complete"
	
