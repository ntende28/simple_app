
main: main.o student.o
	g++ main.o student.o -o main


main.o: main.cpp
	g++ -c main.cpp


student.o: src/student.cpp src/student.h
	g++ -c src/student.cpp 

clean:
	rm *.o *.exe