SOURCE_S = main.cpp
CC = g++
CFLAGS = -Wall -Wextra -pedantic
RM = /bin/rm -rf

all: first go
first: 
	g++ -c $(SOURCE_S)
go: main.o
	g++ main.o -o pro -lsfml-system -lsfml-graphics -lsfml-window -lsfml-audio
clean:  
	$(RM) *.o pro

