CXX=g++
CCFLAGS=-Wall -ansi -pedantic -O3
LDFLAGS=

main: CelestialObject.o
	$(CXX) $(CFLAGS) main.o CelestialObject.o -o SimulateOrbit $(LDFLAGS)

%.o: %.cc
	$(CXX) $(CFLAGS) $< -c -o $@

%: %.cc Makefile
	$(CXX) $(CFLAGS) $< -o $@ $(LDFLAGS)

clean: 
	rm *.o 
