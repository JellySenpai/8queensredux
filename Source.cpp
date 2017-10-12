/*
Raymond Harding
11/29/2015
Csc 275
*/
using namespace std;


#include<cmath>
#include<iostream>
#include<cstdio>
#include <cstdlib>
#define Q 8 //This lets the system know it

///This is the board, I found this idea online, utilized by a matrix
/// 

void printBoard(int board[Q][Q])
{
	for (int i = 0; i < Q; i++)  
	{
		for (int j = 0; j < Q; j++)
			cout << board[i][j];
		cout << endl;
	}
}
/// This fuction is the bool that continues to check if the queen is safe
bool queenSafe(int board[Q][Q], int row, int column)
{
	int i, j;       //Intializing the the two variables that will hold the parameters

	for (i = 0; i < column; i++) 
	{
		if (board[row][i])
			return false;
	}
	for (i = row, j = column; i > 0 && j >= 0; i--, j--) 
	{
		if (board[i][j])
			return false;
	}
	for (i = row, j = column; j >= 0 && i < Q; i++, j--) // If all queens havent been placed, and 
	{
		if (board[i][j])
			return false;
	}
}
bool solveProblem(int board[Q][Q], int column)
{
	if (column >= Q)
		return true;
	for (int i = 0; i < Q; i++)
	{
		if (queenSafe(board, i, column))  //If the queen is safe, place a 1 in the position
		{
			board[i][column] = 1;  //Places a one in the safe position
			if (solveProblem(board, column + 1) == true)
				return true;
			 board[i][column] = 0;  //Place a zero where the queen is not safe

		}
	}
	return false;
}
bool backtrackingQueen()  //Using back tracking/ recursion to loop through solveProblem 
{
	int board[Q][Q] = { 0 };
	if (solveProblem(board, 0) == false)   //If the program is not working this will usally show, 
		//If solveproblem doesn't work 
	{
		cout << "Solution does not exist" << endl;
		return false;
	}
	printBoard(board);
	return true;
}
int main()
{
	backtrackingQueen();

	system("PAUSE");
	return 0;
}