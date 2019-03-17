
SOURCE_S = main.cpp charge.cpp
CC = g++
CFLAGS = -Wall -Wextra -pedantic
RM = /bin/rm -rf

all: first go
first: 
	g++ -c $(SOURCE_S)
go: main.o charge.o
	g++ main.o charge.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
clean:	
	$(RM) *.o sfml-app
