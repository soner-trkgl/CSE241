output: main.o source.o
	g++ -o output main.o source.o
main.o: main.cpp
	g++ -c main.cpp
source.o: source.cpp
	g++ -c source.cpp
clean:
	rm *.o output
