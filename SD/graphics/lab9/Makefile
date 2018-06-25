ShapeDriver:  ShapeDriver.o Shape.o
	g++ -g -Wall -std=c++11 -o ShapeDriver Shape.o ShapeDriver.o $(LIBS)

ShapeDriver.o: ShapeDriver.cpp Shape.h
	g++ -g -Wall -std=c++11 -c ShapeDriver.cpp

Shape.o:  Shape.cpp Shape.h
	g++ -g -Wall -std=c++11 -c Shape.cpp

RectangleDriver:   RectangleDriver.o Rectangle.o Shape.o
	g++ -g -Wall -std=c++11 -o RectangleDriver Rectangle.o RectangleDriver.o Shape.o $(LIBS)

Rectangle.o: Rectangle.cpp Rectangle.h Shape.h
	g++ -g -Wall -std=c++11 -c Rectangle.cpp

RectangleDriver.o:  Rectangle.cpp Rectangle.h Shape.h
	g++ -g -Wall -std=c++11 -c RectangleDriver.cpp

CircleDriver:   CircleDriver.o Circle.o Shape.o
	g++ -g -Wall -std=c++11 -o CircleDriver Circle.o CircleDriver.o Shape.o $(LIBS)

Circle.o: Circle.cpp Circle.h Shape.h
	g++ -g -Wall -std=c++11 -c Circle.cpp

CircleDriver.o:  Circle.cpp Circle.h Shape.h
	g++ -g -Wall -std=c++11 -c CircleDriver.cpp

ShapeDriver1: ShapeDriver1.o Circle.o Rectangle.o Shape.o
	g++ -g -Wall -std=c++11 -o ShapeDriver1 Shape.o ShapeDriver1.o Circle.o Rectangle.o $(LIBS)

ShapeDriver2: ShapeDriver2.o Circle.o Rectangle.o Shape.o
	g++ -g -Wall -std=c++11 -o ShapeDriver2 Shape.o ShapeDriver2.o Circle.o Rectangle.o $(LIBS)

OPTS = -Wall -g -std=c++11
LIBS = -lGL -lglut -lm
ARCH := $(shell uname)
ifeq ($(ARCH), Linux)
else
 MACOSX_DEFINE = -DMACOSX -I/sw/include
 LIBS = -I/usr/common/include -I/usr/include/GL -L/System/Library/Frameworks/OpenGL.framework/Libraries -framework GLUT -framework OpenGL -lGL -lm -lobjc -lstdc++

endif

proto-draw: proto-draw.o Shape.o Rectangle.o Circle.o
	g++ $(OPTS) -o proto-draw proto-draw.o Shape.o Rectangle.o Circle.o $(LIBS)

proto-draw.o: proto-draw.cpp Shape.cpp Rectangle.cpp Circle.cpp
	g++ $(OPTS) $(MACOSX_DEFINE) -c proto-draw.cpp Shape.cpp Rectangle.cpp Circle.cpp

clean:
	rm -f *.o proto-draw
