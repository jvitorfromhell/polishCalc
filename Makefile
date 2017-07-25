compilar:
	gcc -c calc.c
	gcc -c main.c
	gcc -c test.c
	gcc -o run main.o calc.o
	gcc -o validate test.o calc.o

testar:
	./run

avaliar:
	./validate < input.txt

limpar:
	rm *.o
	rm run
	rm validate