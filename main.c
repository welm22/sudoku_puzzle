#include "sudoku.h"


int main() {

	int sudoku_puzzle[9][9];
	int i,j,input;
	printf("enter the sudoku puzzle from left to right, top to bottom, enter 0s for blank spaces\n");
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			printf("what is row %d column %d\n",i+1,j+1);
			scanf("%d",&input);
			sudoku_puzzle[i][j]=input;
		}
	}
	printf("the puzzle you you entered was:\n");
	output_puzzle(sudoku_puzzle);//print out sudoku puzzle
  	try_numbers(sudoku_puzzle);//find the solution
 	printf("your solved puzzle is:\n");
	output_puzzle(sudoku_puzzle);//print out the solution
  
  return 0;
}
