CXX=g++
CCFLAGS=-Wall -ansi -pedantic -O3
LDFLAGS=

Smashem: Smashem.o Particle.o
	$(CXX) $(CFLAGS) Smashem.o Particle.o -o Smashem $(LDFLAGS)

%.o: %.cc
	$(CXX) $(CFLAGS) $< -c -o $@

%: %.cc Makefile
	$(CXX) $(CFLAGS) $< -o $@ $(LDFLAGS)

clean: 
	rm *.o 
