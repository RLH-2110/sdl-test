gcc = gcc -ansi -pedantic -Wall
sld2_link = -I./SDL2/include -L./SDL2/lib -lSDL2

all:
	$(gcc) main.c $(sld2_link) -o main.exe 

PHONY: clear clean run

run: all
	./main.exe

clear: clean
clean:
	rm main.o