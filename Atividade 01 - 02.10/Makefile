# ligação
main: main.o MakeImage.o
	g++ main.o MakeImage.o -o executavel -lMagick++

# compilação
main.o: main.cc MakeImage.h
	g++ -c main.cc -o main.o

# compilação
MakeImage.o: MakeImage.cc MakeImage.h
	g++ -c MakeImage.cc -o MakeImage.o

clean:
	rm -f executavel *.o