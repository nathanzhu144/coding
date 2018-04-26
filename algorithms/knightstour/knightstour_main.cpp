#include "knightstour.h"

int main()
{

    int board[NUM_ROWS][NUM_COLS];
    initialize_board(board);
    kt(0, 0, board);

    return 0;
}