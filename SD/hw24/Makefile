MenuItem_driver:  MenuItem_driver.o MenuItem.o
	g++ -g -Wall -std=c++11 -o MenuItem_driver MenuItem.o MenuItem_driver.o

MenuItem_driver.o:  MenuItem_driver.cpp MenuItem.h
	g++ -g -Wall -std=c++11 -c MenuItem_driver.cpp

MenuItem.o:  MenuItem.cpp MenuItem.h
	g++ -g -Wall -std=c++11 -c MenuItem.cpp

Menu_driver:  Menu_driver.o Menu.o MenuItem.o
	g++ -g -Wall -std=c++11 -o Menu_driver MenuItem.o Menu.o Menu_driver.o

Menu_driver.o:  Menu_driver.cpp Menu.h MenuItem.h
	g++ -g -Wall -std=c++11 -c Menu_driver.cpp

Menu.o:  Menu.cpp Menu.h MenuItem.h
	g++ -g -Wall -std=c++11 -c Menu.cpp
