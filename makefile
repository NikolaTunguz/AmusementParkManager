carnivalComplete: driver.o patron.o worldTour.o teacups.o magicCarpet.o ride.o money.o costCalculator.o
	g++ -o carnivalComplete driver.o patron.o worldTour.o teacups.o magicCarpet.o ride.o money.o costCalculator.o
driver.o: driver.cpp patron.h costCalculator.h
	g++ -c driver.cpp
worldTour.o: worldTour.cpp worldTour.h ride.h
	g++ -c worldTour.cpp
teacups.o: teacups.cpp teacups.h ride.h
	g++ -c teacups.cpp
magicCarpet.o: magicCarpet.cpp magicCarpet.h ride.h
	g++ -c magicCarpet.cpp
ride.o: ride.cpp ride.h
	g++ -c ride.cpp
patron.o: patron.h patron.cpp ride.h magicCarpet.h teacups.h worldTour.h
	g++ -c patron.cpp
costCalculator.o: costCalculator.cpp costCalculator.h money.h
	g++ -c costCalculator.cpp
money.o: money.cpp money.h
	g++ -c money.cpp
clean:
	rm *.o carnivalComplete