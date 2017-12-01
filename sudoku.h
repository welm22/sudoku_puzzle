#ifndef _SUDOKU_H
#define _SUDOKU_H

#include <stdio.h>

//checks if the number works in the column
int check_column(int number, int j, int sudoku_puzzle[9][9]);

//checks if the number works in the row
int check_row(int number, int i, int sudoku_puzzle[9][9]);

//checks if the number works in the 3by3 box
int check_box(int number, int i, int j, int sudoku_puzzle[9][9]);

//checks if the number can go in the given cell
int check_puzzle(int number, int i, int j, int sudoku_puzzle[9][9]);

//prints out the puzzle
void output_puzzle(int sudoku_puzzle[9][9]);

//solves the puzzle
int try_numbers(int sudoku_puzzle[9][9]);

#endif
