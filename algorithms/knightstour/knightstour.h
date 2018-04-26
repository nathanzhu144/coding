#include <iostream>
#include <utility>      //for std::pair
#include <algorithm>    //for std::sort
#include <vector>       //for std::vector
#include <map>          //for std::map
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


//Misc helper functions//

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

//Requires: Nothing.
//Modifies: Nothing.
//Effects:  If move is good, makes a move on that square, marking it with the number
//          of moves done.
void make_move(int row, int col, int num, int board[NUM_ROWS][NUM_COLS]);


//Requires: Nothing.
//Modifies: Nothing.
//Effects:  Returns a vector of pairs<int, std::pair<int, int > > of possible 
//          moves in form of (degree, coordinate).
//          Does not include moves to a node with 0 degrees.  
//
//          first = degree after a move
//          second = move position in std::pair(int row, int col)
//
//Note:     This uses the Warnsdorf's heurstic.  It chooses the next open position
//          with the fewest number of moves from that position.

std::vector<std::pair<int, std::pair<int, int> > > possible_moves(int row, int col, int board[NUM_ROWS][NUM_COLS]);

void kt(int row, int col, int board[NUM_ROWS][NUM_COLS]);

bool kt_utility(int row, int col, int num_moves_made_already, int board[NUM_ROWS][NUM_COLS]);

