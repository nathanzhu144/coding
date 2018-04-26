#include <iostream>
#include <utility>      //for std::pair
#include <vector>       //for std::vector
#include <stdlib.h>     // srand, rand
#include <time.h>       // time 
#include <stdio.h>      // for printf

//Number of rows and cols of board
const int NUM_ROWS = 8;
const int NUM_COLS = 8;
const int NUM_MOVES = 8;

static int row_change[NUM_MOVES] = {2, 1, -1, -2, -2, -1, 1, 2};
static int col_change[NUM_MOVES] = {1, 2, 2, 1, -1, -2, -2, -1};


//Board setup functions//

//Requires: Nothing.
//Modifies: Nothing
//Effects:  Prints board.
void print_board(int board[NUM_ROWS][NUM_COLS]);

//Requires: Nothing.
//Modifies: board
//Effects:  Sets all indices of board to -1
void initialize_board(int board[NUM_ROWS][NUM_COLS]);

//Requires: Nothing.
//Modifies: Nothing.
//Effects:  Checks if a location is off the board or already has been used before.
//          Returns false if either is true.
bool is_move_good(int row, int col, int board[NUM_ROWS][NUM_COLS]);

//Requires: Nothing.
//Modifies: Nothing.
//Effects:  Finds the degree of a node.  Degree is defined as number of possible
//          moves that a chess piece can make.
int find_degree_of_node(int row, int col, int board[NUM_ROWS][NUM_COLS]);


//Requires: Degree of node is not zero.
//Modifies: Nothing.
//Effects:  Returns -1, -1 in std::pair if every possible move is a move to
//          a node with 0 degrees.
//
//          Otherwise returns next optimal move to make.
//
//          If there is a tie, it should choose a random move of the optimal moves
//          in the form (row, col)
//
//Note:     This uses the Warnsdorf's heurstic.  It chooses the next open position
//          with the fewest number of moves from that position.

std::pair<int, int> next_move(int row, int col, int board[NUM_ROWS][NUM_COLS]);


// void kt(int row, int col, int board[NUM_ROWS][NUM_COLS]);

// bool kt_utility(int row, int col, int num_moves_made_already, int board[NUM_ROWS][NUM_COLS]);

