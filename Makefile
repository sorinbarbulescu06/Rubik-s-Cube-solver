all: clean build run

build:
	@gcc -Wall src/main.c src/func.c src/Moves.c src/step1.c src/step2.c src/step3.c -o solver.exe

run:
	@./solver.exe

clean:
	@rm -f solver.exe