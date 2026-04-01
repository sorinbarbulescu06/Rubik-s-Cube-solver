build:
	gcc -Wall src/main.c src/func.c src/Moves.c -o solver.exe

run:
	./solver.exe

clean:
	rm -f solver.exe