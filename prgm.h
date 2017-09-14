#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// declaration of the number of rows and columns in the game board
const int SIZE = 5;

// declaration of enumerated data type used to fill each square on the board
enum square
{ 
	COVERED, 
	MINE,
	KABLOOIE, 
	ZERO, 
	ONE, 
	TWO, 
	THREE, 
	FOUR, 
	FIVE, 
	SIX, 
	SEVEN, 
	EIGHT 
};

typedef square* SquareArrayPtr;

// declaration of structure that contains the coordinates to be entered by the user
struct coordinates
{
	int row;
	int col;
};

// function declarations (prototypes)
void display_info(); // prints out basic programmer info
void give_instructions(int mines); // prints out instructions on how to play the game
void initialize_board(SquareArrayPtr *arr, const int SIZE); // fills the array with the initial value
bool assign_mines(SquareArrayPtr *arr, const int SIZE); // randomly assigns mines to the array
void display_board(SquareArrayPtr *arr, const int SIZE, bool reveal); // prints out the array as a minesweeper board
bool hit_mine(SquareArrayPtr *arr, coordinates move); // determines if the square chosen by the user contains a mine or not and updates the board accordingly
