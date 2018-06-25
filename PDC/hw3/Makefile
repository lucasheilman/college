MvectorTest: MvectorTest.o Mvector.o Poly.o
	g++ -g -Wall -std=c++11 -o MvectorTest MvectorTest.o Mvector.o Poly.o

MvectorTest.o: MvectorTest.cpp Mvector.h Poly.h Poly.cpp
	g++ -g -Wall -std=c++11 -c MvectorTest.cpp Poly.cpp

Mvector.o: Mvector.cpp Mvector.h
	g++ -g -Wall -std=c++11 -c Mvector.cpp

Poly.o: Poly.cpp Poly.h
	g++ -g -Wall -std=c++11 -c Poly.cpp
