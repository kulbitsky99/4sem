SOURCE_S = project.cpp main.cpp
CC = g++
CFLAGS = -Wall -Wextra -pedantic
RM = /bin/rm -rf

all: first go
first: 
	g++ -c $(SOURCE_S)
go: project.o
	g++ project.o main.o -o pro -lsfml-graphics -lsfml-window -lsfml-system
clean:  
	$(RM) *.o pro

