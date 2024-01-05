# ligação
main: main.o MakeImage.o
	g++ main.o MakeImage.o -o executavel -lMagick++

# compilação
main.o: main.cc ../../Atividade\ 01\ -\ 02.10/MakeImage.h
	g++ -c main.cc -o main.o

# compilação
MakeImage.o: ../../Atividade\ 01\ -\ 02.10/MakeImage.cc ../../Atividade\ 01\ -\ 02.10/MakeImage.h
	g++ -c ../../Atividade\ 01\ -\ 02.10/MakeImage.cc -o MakeImage.o

clean:
	rm -f executavel *.o *.png *.ppm