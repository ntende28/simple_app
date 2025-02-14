
main: main.o student.o
	g++ main.o student.o -o main


main.o: main.cpp
	g++ -c main.cpp


student.o: src/student.cpp include/student.h
	g++ -c src/student.cpp 

datastore.o: src/datastore.cpp include/datastore.cpp
	g++ -c datastore.cpp

clean:
	rm *.o *.exe