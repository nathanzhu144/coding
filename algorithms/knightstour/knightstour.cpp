#include "knightstour.h"

//  Board setup functions  //

//Requires: Nothing.
//Modifies: Nothing
//Effects:  Prints board.
void print_board(const int board[NUM_ROWS][NUM_COLS])
{
    for (int r = 0; r < NUM_ROWS; ++r)
    {
        for (int c = 0; c < NUM_COLS; ++c)
        {
            // printf("%d\t", board[r][c]);
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

// Misc helper functions//

//Requires: Nothing.
//Modifies: Nothing.
//Effects:  Checks if a location is off the board or already has been used before.
//          Returns false if either is true.
bool is_move_good(int row, int col, int board[NUM_ROWS][NUM_COLS])
{
    return (row >= 0 && row < NUM_ROWS && col >= 0 && col < NUM_COLS && board[row][col] == -1);
}

//Requires: Nothing.
//Modifies: Nothing.
//Effects:  Returns the degree of a node indicated by row, col.  Degree is defined as number of possible
//          moves that a chess piece can make.
int find_degree_of_node(int row, int col, int board[NUM_ROWS][NUM_COLS])
{
    int num_degrees = 0;

    for (int i = 0; i < NUM_MOVES; ++i)
    {
        if (is_move_good(row + row_change[i], col + col_change[i], board))
        {
            ++num_degrees;
        }
    }

    return num_degrees;
}

//Requires: Nothing.
//Modifies: Nothing.
//Effects:  If move is good, makes a move on that square, marking it with the number
//          of moves done.
void make_move(int row, int col, int num, int board[NUM_ROWS][NUM_COLS])
{
    if (is_move_good(row, col, board))
    {
        board[row][col] = num;
    }
}

//Board solver functions//

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

std::vector<std::pair<int, std::pair<int, int>>> possible_moves(int row, int col, int board[NUM_ROWS][NUM_COLS])
{
    std::vector<std::pair<int, std::pair<int, int>>> optimal_moves;

    //Iterates through all 8 possible moves, finding node with least vertices
    for (int i = 0; i < NUM_MOVES; ++i)
    {
        if (is_move_good(row + row_change[i], col + col_change[i], board) &&
            find_degree_of_node(row + row_change[i], col + col_change[i], board) > 0)
        {
            optimal_moves.push_back(std::make_pair(find_degree_of_node(row + row_change[i], col + col_change[i], board),
                                                   std::make_pair(row + row_change[i], col + col_change[i])));
        }
    }

    std::sort(optimal_moves.begin(), optimal_moves.end());

    return optimal_moves;
}

void kt(int row, int col, int board[NUM_ROWS][NUM_COLS])
{
    board[row][col] = 0;

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
    if (num_moves_made_already >= NUM_COLS * NUM_ROWS - 2)
    {
        return true;
    }

    std::vector<std::pair<int, int> > possible_next_moves;

    for (const std::pair<int, std::pair<int, int> > &i : possible_moves(row, col, board))
    {
        possible_next_moves.push_back(i.second);
    }

    //Makes all knight moves in an order sorted by an increasing degree.
    for (auto i = possible_next_moves.begin(); i != possible_next_moves.end(); ++i)
    {
        board[i->first][i->second] = num_moves_made_already + 1;

        //If move later results in a successful knights tour
        if (kt_utility(i->first, i->second, num_moves_made_already + 1, board))
        {
            return true;
        }
        //If move later does not result in a successful knights tour
        else
        {
            board[i->first][i->second] = -1;
        }
    }

    return false;
}
