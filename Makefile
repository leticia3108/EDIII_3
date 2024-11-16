# Compilador usado
CC = gcc

all: ./build/main.o ./build/funcoes_fornecidas.o ./build/ex_total.o ./build/common.o
	$(CC) ./build/main.o ./build/funcoes_fornecidas.o ./build/ex_total.o ./build/common.o -o ./bin/executavel

./build/funcoes_fornecidas.o: ./include/funcoes_fornecidas.h ./include/funcoes_fornecidas.c
	$(CC) -c ./include/funcoes_fornecidas.c -o ./build/funcoes_fornecidas.o

./build/main.o: ./src/main.c ./src/header.h
	$(CC) -c ./src/main.c -o ./build/main.o

./build/ex_total.o: ./build/ex1.o ./build/ex2.o ./build/ex3.o ./build/ex4.o ./build/ex5.o ./build/ex6.o
	$(CC) -r ./build/ex1.o ./build/ex2.o ./build/ex3.o ./build/ex4.o ./build/ex5.o ./build/ex6.o -o ./build/ex_total.o

./build/ex1.o: ./src/ex1.c ./src/header.h
	$(CC) -c ./src/ex1.c -o ./build/ex1.o

./build/ex2.o: ./src/ex2.c ./src/header.h
	$(CC) -c ./src/ex2.c -o ./build/ex2.o

./build/ex3.o: ./src/ex3.c ./src/header.h
	$(CC) -c ./src/ex3.c -o ./build/ex3.o

./build/ex4.o: ./src/ex4.c ./src/header.h
	$(CC) -c ./src/ex4.c -o ./build/ex4.o

./build/ex5.o: ./src/ex5.c ./src/header.h
	$(CC) -c ./src/ex5.c -o ./build/ex5.o

./build/ex6.o: ./src/ex6.c ./src/header.h
	$(CC) -c ./src/ex6.c -o ./build/ex6.o

./build/common.o: ./src/common.c ./src/header.h
	$(CC) -c ./src/common.c -o ./build/common.o

clean:
	rm  ./build/* ./bin/*

run: 
	./bin/executavel