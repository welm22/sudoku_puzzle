
game: main.c sudoku.c
	g++ -g -c sudoku.c -o sudoku.o
	g++ -g -c main.c -o main.o
	g++ -g main.o sudoku.o -o game

clean:
	rm *.o game

