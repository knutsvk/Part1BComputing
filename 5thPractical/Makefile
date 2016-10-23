CXX=g++
CCFLAGS=-Wall -ansi -pedantic -O3
LDFLAGS=

GivenICs: GivenICs.o CelestialObject.o
	$(CXX) $(CFLAGS) GivenICs.o CelestialObject.o -o GivenICs $(LDFLAGS)

OneYear: OneYear.o CelestialObject.o
	$(CXX) $(CFLAGS) OneYear.o CelestialObject.o -o OneYear $(LDFLAGS)

%.o: %.cc
	$(CXX) $(CFLAGS) $< -c -o $@

%: %.cc Makefile
	$(CXX) $(CFLAGS) $< -o $@ $(LDFLAGS)

clean: 
	rm *.o 
