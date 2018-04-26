#include <iostream>
<<<<<<< HEAD
#include <utility>            //for std::pair

//Number of rows and cols of board
const int NUM_ROWS = 6;
const int NUM_COLS = 5;
const int NUM_MOVES = 8;


int row_change[NUM_MOVES] = {2, 1, -1, -2, -2, -1, 1, 2};
int col_change[NUM_MOVES] = {1, 2, 2, 1, -1, -2, -2, -1};
=======

//Number of rows and cols of board
const int NUM_ROWS = 8;
const int NUM_COLS = 8;

//All possible moves of a knight on a chessboard
// int row_change[8] = {2, 1, -1, -2, -2, -1, 1, 2};
// int col_change[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int row_change[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int col_change[8] = {1, 2, 2, 1, -1, -2, -2, -1};
>>>>>>> 7fceab19f267a9b884d14e2eeca4495ba2ebd6c7

//Board setup functions//

//Requires: Nothing.
//Modifies: Nothing
//Effects:  Prints board.
<<<<<<< HEAD
void print_board(int board[NUM_ROWS][NUM_COLS]);
=======
void print_board(const int board[NUM_ROWS][NUM_COLS]);
>>>>>>> 7fceab19f267a9b884d14e2eeca4495ba2ebd6c7

//Requires: Nothing.
//Modifies: board
//Effects:  Sets all indices of board to -1
void initialize_board(int board[NUM_ROWS][NUM_COLS]);


//Requires: Nothing.
//Modifies: Nothing.
//Effects:  Checks if a location is off the board or already has been used before.
//          Returns false if either is true.
bool is_move_good(int row, int col, int board[NUM_ROWS][NUM_COLS]);

<<<<<<< HEAD
//Requires: Nothing.
//Modifies: Nothing.
//Effects:  Finds the degree of a node.  Degree is defined as number of possible
//          moves that a chess piece can make.  
int find_degree_of_node(int row, int col, int board[NUM_ROWS][NUM_COLS]){
    int num_degrees = 0;

    for(int i = 0; i < NUM_MOVES; ++i){
        if(is_move_good(row + row_change[i], col + col_change[i], board)){
            ++num_degrees;
        }
    }

    return num_degrees;
}

//Requires: Degree of node is not zero.
//Modifies: Nothing.
//Effects:  
std::pair<int, int> next_move(int row, int col, int board[NUM_ROWS][NUM_COLS]){
    std::vector<int> valid_moves;
    

    for(int i = 0; i < NUM_MOVES; ++i){
        if(is_move_good(row + row_change[i], col + col_change[i], board)){
            
        }
    }

}
=======

>>>>>>> 7fceab19f267a9b884d14e2eeca4495ba2ebd6c7

void kt(int row, int col, int board[NUM_ROWS][NUM_COLS]);


bool kt_utility(int row, int col, int num_moves_made_already, int board[NUM_ROWS][NUM_COLS]);


int main()
{
    int board[NUM_ROWS][NUM_COLS];
    initialize_board(board);
    kt(0, 0, board);

    return 0;
}


//Board setup functions//

//Requires: Nothing.
//Modifies: Nothing
//Effects:  Prints board.
void print_board(const int board[NUM_ROWS][NUM_COLS])
{
    for (int r = 0; r < NUM_ROWS; ++r)
    {
        for (int c = 0; c < NUM_COLS; ++c)
        {
            std::cout << board[r][c] << " ";
        }
        std::cout << std::endl;
    }
}

//Requires: Nothing.
//Modifies: board
//Effects:  Sets all indices of board to -1
void initialize_board(int board[NUM_ROWS][NUM_COLS])
{
    for (int r = 0; r < NUM_ROWS; ++r)
    {
        for (int c = 0; c < NUM_COLS; ++c)
        {
            board[r][c] = -1;
        }
    }
}

//Requires: Nothing.
//Modifies: Nothing.
//Effects:  Checks if a location is off the board or already has been used before.
//          Returns false if either is true.
bool is_move_good(int row, int col, int board[NUM_ROWS][NUM_COLS])
{
    return (row >= 0 && row < NUM_ROWS && col >= 0 && col < NUM_COLS && board[row][col] == -1);
}

<<<<<<< HEAD
=======
//Requires: is_move_good is true
//Modifies: board
//Effects:  Makes a move on the board as specified by the row and col numbers.
void make_move(int row, int col, int num_moves_made_already, int board[NUM_ROWS][NUM_COLS])
{
    board[row][col] = num_moves_made_already;
}
>>>>>>> 7fceab19f267a9b884d14e2eeca4495ba2ebd6c7

void kt(int row, int col, int board[NUM_ROWS][NUM_COLS])
{
    board[0][0] = 0;

    if (kt_utility(row, col, 0, board))
    {
        print_board(board);
    }
    else
    {
        std::cout << "No solution";
    }
}

bool kt_utility(int row, int col, int num_moves_made_already, int board[NUM_ROWS][NUM_COLS])
{
    //Finished filling whole board.
    if (num_moves_made_already >= NUM_COLS * NUM_ROWS)
    {
        return true;
    }

    //Tests out all 8 configurations for knight move
    for (int i = 0; i < 8; ++i)
    {
        int new_row = row_change[i] + row;
        int new_col = col_change[i] + col;
        if (is_move_good(new_row, new_col, board))
        {
            board[new_row][new_col] = num_moves_made_already + 1;

            if (kt_utility(new_row, new_col, num_moves_made_already + 1, board))
            {
                return true;
            }else{
                board[new_row][new_col] = -1;
            }
        }
    }

    return false;
}