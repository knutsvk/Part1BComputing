CXX=g++
CCFLAGS=-Wall -ansi -pedantic -O3
LDFLAGS=

all: SolarSystem

SolarSystem: SolarSystem.o CelestialObject.o
	$(CXX) $(CFLAGS) SolarSystem.o CelestialObject.o -o SolarSystem $(LDFLAGS)

%.o: %.cc
	$(CXX) $(CFLAGS) $< -c -o $@

%: %.cc Makefile
	$(CXX) $(CFLAGS) $< -o $@ $(LDFLAGS)

clean: 
	rm *.o 
