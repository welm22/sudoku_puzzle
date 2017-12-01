#include "sudoku.h"

//INPUTS:	number- number to be placed in cell
//			i- row that number is located in
//			j- column that number is located in
//			sudoku_puzzle- array of the sudoku board
//SUMMARY:	checks if the number works in the column
//RETURN:	1 if the number given can go in the specific column
int check_column(int number,int j,int sudoku_puzzle[9][9])
{
	
	int row,value;
	int check=0;
	for(row=0;row<9;row++)//cycles through every row number and keeps column same
	{
		value=sudoku_puzzle[row][j];
		if(value==number)
		{
			check++;//checks if there are any repeats
		}
	}
	if(check==0)
	{
		return 0;
	}
	return 1;
}

//INPUTS:	number- number to be placed in cell
//			i- row that number is located in
//			j- column that number is located in
//			sudoku_puzzle- array of the sudoku board
//SUMMARY:	checks if the number works in the given row
//RETURN:	1 if the number given can go in the specific row
int check_row(int number,int i,int sudoku_puzzle[9][9])
{
	
	int column,value;
	int check=0;
	for(column=0;column<9;column++)//cycles through every column number and keeps row same
	{
		value=sudoku_puzzle[i][column];
		if(value==number)
		{
			check++;//checks if there are any repeats
		}
	}
	if(check==0)
	{
		return 0;
	}
	return 1;
}

//INPUTS:	number- number to be placed in cell
//			i- row that number is located in
//			j- column that number is located in
//			sudoku_puzzle- array of the sudoku board
//SUMMARY:	checks if the number works in the 3 by 3 box
//RETURN:	1 if the number given can go in the specific box
int check_box(int number,int i,int j,int sudoku_puzzle[9][9])
{
	
	int row,column,value;
	int check=0;
	//first 3x3 cell
  	if(i>=0&&i<=2&&j>=0&&j<=2)
	{
		for(row=0;row<=2;row++)
		{
			for(column=0;column<=2;column++)
			{
				value=sudoku_puzzle[row][column];
				if(value==number)
				{
					check++;
				}
			}
		}
	}
	//second 3x3 cell(the one to the right)
	if(i>=0&&i<=2&&j>=3&&j<=5)
	{
		for(row=0;row<=2;row++)
		{
			for(column=3;column<=5;column++)
			{
				value=sudoku_puzzle[row][column];
				if(value==number)
				{
					check++;
				}
			}
		}
	}
	//third 3x3 cell
	if(i>=0&&i<=2&&j>=6&&j<=8)
	{
		for(row=0;row<=2;row++)
		{
			for(column=6;column<=8;column++)
			{
				value=sudoku_puzzle[row][column];
				if(value==number)
				{
					check++;
				}
			}
		}
	}
	//fourth 3x3 cell
	if(i>=3&&i<=5&&j>=0&&j<=2)
	{
		for(row=3;row<=5;row++)
		{
			for(column=0;column<=2;column++)
			{
				value=sudoku_puzzle[row][column];
				if(value==number)
				{
					check++;
				}
			}
		}
	}
	//fifth 3x3 cell
	if(i>=3&&i<=5&&j>=3&&j<=5)
	{
		for(row=3;row<=5;row++)
		{
			for(column=3;column<=5;column++)
			{
				value=sudoku_puzzle[row][column];
				if(value==number)
				{
					check++;
				}
			}
		}
	}
	//sixth 3x3 cell
	if(i>=3&&i<=5&&j>=6&&j<=8)
	{
		for(row=3;row<=5;row++)
		{
			for(column=6;column<=8;column++)
			{
				value=sudoku_puzzle[row][column];
				if(value==number)
				{
					check++;
				}
			}
		}
	}
	//seventh 3x3 cell
	if(i>=6&&i<=8&&j>=0&&j<=2)
	{
		for(row=6;row<=8;row++)
		{
			for(column=0;column<=2;column++)
			{
				value=sudoku_puzzle[row][column];
				if(value==number)
				{
					check++;
				}
			}
		}
	}
	//eighth 3x3 cell
	if(i>=6&&i<=8&&j>=3&&j<=5)
	{
		for(row=6;row<=8;row++)
		{
			for(column=3;column<=5;column++)
			{
				value=sudoku_puzzle[row][column];
				if(value==number)
				{
					check++;
				}
			}
		}
	}
	//ninth 3x3 cell
	if(i>=6&&i<=8&&j>=6&&j<=8)
	{
		for(row=6;row<=8;row++)
		{
			for(column=6;column<=8;column++)
			{
				value=sudoku_puzzle[row][column];
				if(value==number)
				{
					check++;
				}
			}
		}
	}
	//see how many duplicates, if check=1, no duplicates because you also check
	//own cell, if more than 1 then there are duplicates
	if(check==1)
	{
		return 1;
	}

	return 0;
}

//INPUTS:	number- number to be placed in cell
//			i- row that number is located in
//			j- column that number is located in
//			sudoku_puzzle- array of the sudoku board
//SUMMARY:	checks if the given number can go in the specific cell
//RETURN:	1 if the number given can go in the specific box
int check_puzzle(int number,int i,int j,int sudoku_puzzle[9][9])
{
	
	if(check_column(number, j, sudoku_puzzle))
	{
		return 0;
	}
	
	if(check_row(number, i, sudoku_puzzle))
	{
		return 0;
	}
	if(check_box(number, i, j, sudoku_puzzle)) 
	{
		return 0;
	}
	return 1;
}

//INPUTS:	NONE
//SUMMARY:	prints out the puzzle
//RETURN:	NONE
void output_puzzle(int sudoku_puzzle[9][9])
{
	int i,j;
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			printf("%d ",sudoku_puzzle[i][j]);
		}
		printf("\n");
	}
}

//INPUTS:	sudoku_puzzle- array of the sudoku board
//SUMMARY:	solves the puzzle using recursion
//RETURN:	1 if the puzzle is solved
int try_numbers(int sudoku_puzzle[9][9])
{
	int cAssign1,cAssign2,value,num;
	int check=0;
	int i,j;
	for(cAssign1=0;cAssign1<9;cAssign1++)//looks through entire board for empty cells
	{
		for(cAssign2=0;cAssign2<9;cAssign2++)
		{
			value=sudoku_puzzle[cAssign1][cAssign2];
			if(value==0)
			{
				check++;
				i=cAssign1;//checks the location of the empty cell
				j=cAssign2;
			}
		}
	}
	//all cells are assigned by numbers
	if(check==0)
	{
		return 1;
	}
	for(num=1;num<=9;num++)//goes thru list of numbers to try
	{
		
		if(check_puzzle(num,i,j,sudoku_puzzle))
		{
			sudoku_puzzle[i][j]=num;//assigns number to cell
			if(try_numbers(sudoku_puzzle))//checks if solved
			{
				return 1;
			}
			sudoku_puzzle[i][j]=0;	//switch it back to unfilled because it does not work
		}
		
	}
	
	return 0;
}
