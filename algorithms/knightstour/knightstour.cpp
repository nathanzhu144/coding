// #include <iostream>
// #include <utility>      //for std::pair
// #include <vector>       //for std::vector
// #include <stdlib.h>     // srand, rand
// #include <time.h>       // time 
// #include <stdio.h>      // for printf
#include "knightstour.h"




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



//Board solver functions//


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
//Effects:  Finds the degree of a node.  Degree is defined as number of possible
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

std::pair<int, int> next_move(int row, int col, int board[NUM_ROWS][NUM_COLS])
{
    std::vector<std::pair<int, int>> optimal_moves;          
    int current_min_degree = NUM_MOVES;                           //stores lowest degree of node we have seen

    //Iterates through all 8 possible moves, finding node with least vertices
    for (int i = 0; i < NUM_MOVES; ++i)
    {
        if (is_move_good(row + row_change[i], col + col_change[i], board))
        {
            //If we find a valid vertex with fewer nodes (but greater than 0)
            if (find_degree_of_node(row + row_change[i], col + col_change[i], board) < current_min_degree &&
                find_degree_of_node(row + row_change[i], col + col_change[i], board) > 0)
            {
                //Clear all current moves, and add current move
                optimal_moves.clear();
                optimal_moves.push_back(std::make_pair(row + row_change[i], col + col_change[i]));
                current_min_degree = find_degree_of_node(row + row_change[i], col + col_change[i], board);
            }

            //If we find a valid vertex with same number of nodes as current min degree
            else if (find_degree_of_node(row + row_change[i], col + col_change[i], board) == current_min_degree)
            {
                optimal_moves.push_back(std::make_pair(row + row_change[i], col + col_change[i]));
            }
        }
    }

    if(optimal_moves.empty()){
        return std::make_pair(-1, -1);
    }else{
        //chooses random optimal move
        return optimal_moves[rand() % optimal_moves.size()];
    }
}


// void kt(int row, int col, int board[NUM_ROWS][NUM_COLS])
// {
//     board[0][0] = 0;

//     if (kt_utility(row, col, 0, board))
//     {
//         print_board(board);
//     }
//     else
//     {
//         std::cout << "No solution";
//     }
// }


// bool kt_utility(int row, int col, int num_moves_made_already, int board[NUM_ROWS][NUM_COLS])
// {
//     //Finished filling whole board.
//     if (num_moves_made_already >= NUM_COLS * NUM_ROWS)
//     {
//         return true;
//     }

//     //Tests out all 8 configurations for knight move
//     for (int i = 0; i < 8; ++i)
//     {
//         int new_row = row_change[i] + row;
//         int new_col = col_change[i] + col;
//         if (is_move_good(new_row, new_col, board))
//         {
//             board[new_row][new_col] = num_moves_made_already + 1;

//             if (kt_utility(new_row, new_col, num_moves_made_already + 1, board))
//             {
//                 return true;
//             }
//             else
//             {
//                 board[new_row][new_col] = -1;
//             }
//         }
//     }

//     return false;
// }

