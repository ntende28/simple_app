OS := $(shell uname)

ifeq ($(OS),Windows_NT)
	RM = del /f
else
	RM = rm -f
endif

main: main.o student.o datastore.o
	g++ main.o student.o datastore.o -o main


main.o: main.cpp
	g++ -c main.cpp


student.o: src/student.cpp include/student.h
	g++ -c src/student.cpp 

datastore.o: src/datastore.cpp include/datastore.cpp
	g++ -c src/datastore.cpp

clean:
	$(RM) *.o *.exe