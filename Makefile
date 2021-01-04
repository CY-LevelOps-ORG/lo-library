# Makefile to build the library_db sample program

CXX=g++

all: library_db

library_db: main.o Database.o Book.o
	$(CXX) -o $@ $^

Database.o: Database.cpp Database.h
	$(CXX) -c Database.cpp 

Book.o: Book.cpp Book.h
	$(CXX) -c Book.cpp 

#Parser.o: Parser.cpp Parser.h
#	$(CXX) -c Parser.cpp

clean:
	rm -f *.o library_db
