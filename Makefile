all: ./objects/main.o ./objects/candidato.o ./objects/partido.o ./objects/eleicao.o
	g++ -o main ./objects/main.o ./objects/candidato.o ./objects/partido.o ./objects/eleicao.o

./objects/main.o: main.cpp ./headers/candidato.h ./headers/partido.h ./headers/eleicao.h
	g++ -c -o ./objects/main.o main.cpp

./objects/candidato.o: ./src/candidato.cpp ./headers/candidato.h
	g++ -c -o ./objects/candidato.o ./src/candidato.cpp

./objects/partido.o: ./src/partido.cpp ./headers/partido.h
	g++ -c -o ./objects/partido.o ./src/partido.cpp

./objects/eleicao.o: ./src/eleicao.cpp ./headers/eleicao.h
	g++ -c -o ./objects/eleicao.o ./src/eleicao.cpp

clean:
	rm -f main ./objects/*