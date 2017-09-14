#include "prgm.h"

/*
============================================================================
 Function    : display_info
 Parameters  : none
 Return      : none
 Description : This function outputs a block header to the screen that dis-
	       plays the department, class, name, EUID, and myUNT email add-
	       ress.
============================================================================
*/

void display_info()
{
	cout << "+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+\n"
	     << "|       Computer Science and Engineering        |\n"
	     << "|        CSCE 1030 - Computer Science I         |\n"
	     << "|  Cole Dapprich  cwd0042  cwd0042@my.unt.edu   |\n"
 	     << "+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+\n";
}

/*
============================================================================
 Function    : give_instructions
 Parameters  : int mines
 Return      : none
 Description : This function displays details about the game, including the
	       size of the board, the number of mines placed on the board,
	       and the objective of the game.
============================================================================
*/

void give_instructions(int mines)
{
	cout << "\n----------------------------------------------------------\n"
	     << "This computer program will randomly assign " << mines << " mines to the\n"
	     << "5 by 5 board. Your objective will be to select ten squares\n"
	     << "on the board that do not contain mines using the given in-\n"
	     << "formation from the adjacent squares. The game is over when\n"
	     << "you either select 10 squares without hitting a mine or you\n"
	     << "select a square containing a mine.\n"
	     << "----------------------------------------------------------\n\n";
}

/*
=============================================================================
 Function    : initialize_board
 Parameters  : SquareArrayPtr *arr, const int SIZE
 Return      : none
 Description : This function fills the board with the initial value, COVERED.
=============================================================================
*/

void initialize_board(SquareArrayPtr *arr, const int SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			arr[i][j] = COVERED;
		}
	}
}

/*
============================================================================
 Function    : assign_mines
 Parameters  : SquareArrayPtr *arr, const int SIZE
 Return      : a boolean value indicating whether or not the assignment was
	       successful
 Description : This function assigns a mine to a randomly generated position
	       on the board, checking to make sure it does not already con-
	       tain one.
============================================================================
*/

bool assign_mines(SquareArrayPtr *arr, const int SIZE)
{
	srand(time(0)); // seeds the random number generator

	int row = rand() % 5; // randomly generated row position
	int col = rand() % 5; // randomly generated column position

	if (arr[row][col] != MINE) // checks to make sure the coordinates do not already contain a mine
	{
		arr[row][col] = MINE;
		return true;
	}
	else
	{
		return false;
	}
}

/*
============================================================================
 Function    : display_board
 Parameters  : SquareArrayPtr *arr, const int SIZE, bool reveal
 Return      : none
 Description : This function prints out the game board with row and column
	       headers, hiding the locations of mines unless reveal is true.
============================================================================
*/

void display_board(SquareArrayPtr *arr, const int SIZE, bool reveal)
{
	cout << "   0 1 2 3 4" << endl
	     << " +-----------+" << endl;

	for (int i = 0; i < SIZE; i++)
	{
		cout << i << "| ";

		if (reveal == false) // doesn't reveal location of mines
		{
			for (int j = 0; j < SIZE; j++)
			{
				switch (arr[i][j]) // maps the enumerated value to the desired printable character
				{
					case ZERO:
						cout << "0 ";
						break;
					case ONE:
						cout << "1 ";
						break;
					case TWO:
						cout << "2 ";
						break;
					case THREE:
						cout << "3 ";
						break;
					case FOUR:
						cout << "4 ";
						break;
					case FIVE:
						cout << "5 ";
						break;
					case SIX:
						cout << "6 ";
						break;
					case SEVEN:
						cout << "7 ";
						break;
					case EIGHT:
						cout << "8 ";
						break;
					default:
						cout << "* ";
				}
			}
		}
		else // does reveal location of mines
		{
			for (int j = 0; j < SIZE; j++)
			{
				switch (arr[i][j]) // maps the enumerated value to the desired printable character
				{
					case MINE:
						cout << "@ ";
						break;
					case KABLOOIE:
						cout << "X ";
						break;
					case ZERO:
						cout << "0 ";
						break;
					case ONE:
						cout << "1 ";
						break;
					case TWO:
						cout << "2 ";
						break;
					case THREE:
						cout << "3 ";
						break;
					case FOUR:
						cout << "4 ";
						break;
					case FIVE:
						cout << "5 ";
						break;
					case SIX:
						cout << "6 ";
						break;
					case SEVEN:
						cout << "7 ";
						break;
					case EIGHT:
						cout << "8 ";
						break;
					default:
						cout << "* ";
				}
			}
			
		}

			cout << "|" << endl;
	}	

	cout << " +-----------+" << endl;
}

/*
============================================================================
 Function    : hit_mine
 Parameters  : SquareArrayPtr *arr, coordinates move
 Return      : a boolean value indiciting whether or not a mine was hit
 Description : This function determines whether or not a mine was hit, up-
	       dating the board appropriately.
============================================================================
*/

bool hit_mine(SquareArrayPtr *arr, coordinates move)
{
	int adjacent_mine_counter = 0;

	if (arr[move.row][move.col] == MINE)
	{
		arr[move.row][move.col] = KABLOOIE;
		return true;
	}

	else if (move.row == 0 || move.row == 4 || move.col == 0 || move.col == 4)
	{
		if (move.row == 0 && move.col == 0)
		{
			if (arr[move.row + 1][move.col] == MINE)
			{
				adjacent_mine_counter++;
			}
			if (arr[move.row][move.col + 1] == MINE)
			{
				adjacent_mine_counter++;
			}
			if (arr[move.row + 1][move.col + 1] == MINE)
			{
				adjacent_mine_counter++;
			}	
		}
		
		else if (move.row == 0 && move.col == 4)
		{
			if (arr[move.row + 1][move.col] == MINE)
			{
				adjacent_mine_counter++;
			}
			if (arr[move.row][move.col - 1] == MINE)
			{
				adjacent_mine_counter++;
			}
			if (arr[move.row + 1][move.col - 1] == MINE)
			{
				adjacent_mine_counter++;
			}
		}	

		else if (move.row == 4 && move.col == 0)
		{
			if (arr[move.row - 1][move.col] == MINE)
			{
				adjacent_mine_counter++;
			}
			if (arr[move.row][move.col + 1] == MINE)
			{
				adjacent_mine_counter++;
			}
			if (arr[move.row - 1][move.col + 1] == MINE)
			{
				adjacent_mine_counter++;
			}
		}

		else if (move.row == 4 && move.col == 4)
		{
			if (arr[move.row - 1][move.col] == MINE)
			{
				adjacent_mine_counter++;
			}
			if (arr[move.row][move.col - 1] == MINE)
			{
				adjacent_mine_counter++;
			}
			if (arr[move.row - 1][move.col - 1] == MINE)
			{
				adjacent_mine_counter++;
			}
		}

		else if (move.row == 0 && move.col != 4 && move.col != 0)
		{
			if (arr[move.row][move.col - 1] == MINE)
			{
				adjacent_mine_counter++;
			}
			if (arr[move.row][move.col + 1] == MINE)
			{
				adjacent_mine_counter++;
			}
			if (arr[move.row + 1][move.col] == MINE)
			{
				adjacent_mine_counter++;
			}
			
			if (arr[move.row + 1][move.col - 1] == MINE)
			{
				adjacent_mine_counter++;
			}
			
			if (arr[move.row + 1][move.col + 1] == MINE)
			{
				adjacent_mine_counter++;
			}
		}

		else if (move.row == 4 && move.col != 4 && move.col != 0)
		{
			if (arr[move.row][move.col - 1] == MINE)
			{
				adjacent_mine_counter++;
			}
			if (arr[move.row][move.col + 1] == MINE)
			{
				adjacent_mine_counter++;
			}
			if (arr[move.row - 1][move.col] == MINE)
			{
				adjacent_mine_counter++;
			}
			
			if (arr[move.row - 1][move.col - 1] == MINE)
			{
				adjacent_mine_counter++;
			}
			
			if (arr[move.row - 1][move.col + 1] == MINE)
			{
				adjacent_mine_counter++;
			}
		}

		else if (move.col == 0 && move.row != 4 && move.row != 0)
		{
			if (arr[move.row - 1][move.col] == MINE)
			{
				adjacent_mine_counter++;
			}
			if (arr[move.row - 1][move.col + 1] == MINE)
			{
				adjacent_mine_counter++;
			}
			if (arr[move.row][move.col + 1] == MINE)
			{
				adjacent_mine_counter++;
			}
			
			if (arr[move.row + 1][move.col] == MINE)
			{
				adjacent_mine_counter++;
			}
			
			if (arr[move.row + 1][move.col + 1] == MINE)
			{
				adjacent_mine_counter++;
			}
		}

		else if (move.col == 4 && move.row != 4 && move.row != 0)
		{
			if (arr[move.row - 1][move.col] == MINE)
			{
				adjacent_mine_counter++;
			}
			if (arr[move.row - 1][move.col - 1] == MINE)
			{
				adjacent_mine_counter++;
			}
			if (arr[move.row][move.col - 1] == MINE)
			{
				adjacent_mine_counter++;
			}
			
			if (arr[move.row + 1][move.col] == MINE)
			{
				adjacent_mine_counter++;
			}
			
			if (arr[move.row + 1][move.col - 1] == MINE)
			{
				adjacent_mine_counter++;
			}
		}
	}

	else
	{
		if (arr[move.row - 1][move.col - 1] == MINE)
		{
			adjacent_mine_counter++;
		}
			
		if (arr[move.row - 1][move.col] == MINE)
		{
			adjacent_mine_counter++;
		}
			
		if (arr[move.row - 1][move.col + 1] == MINE)
		{
			adjacent_mine_counter++;
		}
			
		if (arr[move.row][move.col - 1] == MINE)
		{
			adjacent_mine_counter++;
		}
			
		if (arr[move.row][move.col + 1] == MINE)
		{
			adjacent_mine_counter++;
		}
			
		if (arr[move.row + 1][move.col - 1] == MINE)
		{
			adjacent_mine_counter++;
		}
			
		if (arr[move.row + 1][move.col] == MINE)
		{
			adjacent_mine_counter++;
		}
			
		if (arr[move.row + 1][move.col + 1] == MINE)
		{
			adjacent_mine_counter++;
		}
	}

	switch (adjacent_mine_counter)
	{
		case 1:
			arr[move.row][move.col] = ONE;
			break;
		case 2:
			arr[move.row][move.col] = TWO;
			break;
		case 3:
			arr[move.row][move.col] = THREE;
			break;
		case 4:
			arr[move.row][move.col] = FOUR;
			break;
		case 5:
			arr[move.row][move.col] = FIVE;
			break;
		case 6:
			arr[move.row][move.col] = SIX;
			break;
		case 7:
			arr[move.row][move.col] = SEVEN;
			break;
		case 8:
			arr[move.row][move.col] = EIGHT;
			break;
		default:
			arr[move.row][move.col] = ZERO;
	}
}
