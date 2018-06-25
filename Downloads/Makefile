RoadTrip_driver:  RoadTrip_driver.o trip.o Car.o Participant.o Song.o Playlist.o Event.o Calendar.o
	g++ -g -Wall -std=c++11 -o RoadTrip_driver trip.o RoadTrip_driver.o Car.o Participant.o Song.o Playlist.o Event.o Calendar.o

trip.o: trip.cpp trip.h Car.h Participant.h
	g++ -Wall -std=c++11 -c trip.cpp

Participant.o: Participant.cpp Participant.h
	g++ -Wall -std=c++11 -c Participant.cpp

Car.o: Car.cpp Car.h Participant.h
	g++ -Wall -std=c++11 -c Car.cpp

Playlist.o: Playlist.cpp Playlist.h Song.h
	g++ -Wall -std=c++11 -c Playlist.cpp

Song.o: Song.cpp Song.h
	g++ -Wall -std=c++11 -c Song.cpp

Calendar.o: Calendar.cpp Calendar.h Event.h
	g++ -Wall -std=c++11 -c Calendar.cpp

Event.o: Event.cpp Event.h
	g++ -Wall -std=c++11 -c Event.cpp

RoadTrip_driver.o:  RoadTrip_driver.cpp trip.h Car.h Participant.h Song.h Playlist.h Event.h Calendar.h
	g++ -g -Wall -std=c++11 -c RoadTrip_driver.cpp trip.h Car.h Participant.h Song.h Playlist.h Event.h Calendar.h



