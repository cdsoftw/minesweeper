/*
============================================================================
 Name        : main.cpp
 Author      : Cole Dapprich
 Version     : 1.0
 Copyright   : 2015
 Description : This program creates and plays a 5-by-5 minesweeper game.
============================================================================
*/

#include "prgm.h"

int main ( )
{
	display_info(); // displays block header with basic info

	// variable declarations

	// number of mines randomly placed by the program and counters to keep track of number of mines placed and number of moves made
	int mines, mine_counter = 0, move_counter = 1;
	bool reveal = false, t_f, t_f2;
	coordinates move;

	SquareArrayPtr *board = new SquareArrayPtr[SIZE];

	for (int i = 0; i < SIZE; i++)
	{
		board[i] = new square[SIZE];
	}

	cout << "\n\t\tWelcome to Minesweeper!" << endl;

	do // read in the number of mines to be placed, checking for range
	{
		cout << "\nEnter number of mines to place on board (5 - 10): ";
		cin >> mines;
	} while (mines < 5 || mines > 10);

	// function calls
	give_instructions(mines); // print out game instructions

	cout << "Initializing board...";

	initialize_board(board, SIZE); // fill the array with the initial value

	cout << "assigning mines...";

	do // randomly assign the correct number of mines, checking to make sure the square does not already contain one
	{
		t_f = assign_mines(board, SIZE); // indicates whether or not the assignment was successful

		if (t_f == true) // if the assignment was successful, update the counter
		{
			mine_counter++;
		}
	} while (mine_counter < mines);

	cout << "now let's begin...\n\n";

	do // play the game until won or lost
	{
		display_board(board, SIZE, reveal); // print out the game board
		
		cout << "Enter position for move #" << move_counter << " (row[0-4] col[0-4]): ";
		cin >> move.row >> move.col; // read in move
		
		if ((board[move.row][move.col] == COVERED || board[move.row][move.col] == MINE) && ((move.row >= 0 && move.row <= 4) && (move.col >= 0 && move.col <= 4)))
		{
			move_counter++; // if move is valid, update the move counter and check for mines in and surrounding the coordinates
			t_f2 = hit_mine(board, move);
		}	
		else
		{
			cout << "Invalid position entered. Try again...\n";
		}
	} while (t_f2 == false && move_counter <= 10);

	if (t_f2 == false) // inform the user if they won or lost
	{
		cout << "Congratulations! No mine hit in 10 tries!\n";
	}
	else
	{
		cout << "Sorry, but you hit a mine. Tough break...\n";
	}

	reveal = true; // print out the game board without hiding mines
	display_board(board, SIZE, reveal);

	for (int i = 0; i < SIZE; i++)
	{
		delete [] board[i];
	}

	delete [] board;

	return 0;
}

