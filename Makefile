all: main run

main: fraktalai-t.o 
	gcc fraktalai-t.o -lrt -lGL -lglut -o fraktalai-t.out
	
fractalai-t.o: fractalai-t.c
	gcc -c fraktalai-t.c -o fraktalai-t.o
	
clear: 
	rm *.o

run: 
	./fraktalai-t.out
	
ifs:	ifsc run-ifs
	
ifsc:	fraktalai-ifs.o 
	g++ fraktalai-ifs.o -lrt -lGL -lglut -o fraktalai-ifs.out
	
fractalai-ifs.o: fractalai-ifs.c
	g++ -c fraktalai-ifs.c -o fraktalai-ifs.o

run-ifs: 
	./fraktalai-ifs.out
