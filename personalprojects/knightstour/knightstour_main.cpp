#include "knightstour.h"
#include <fstream>

void print_menu()
{
    std::cout << "Welcome to the Knight's Path simulation." << std::endl;
    std::cout << "  1. Simulate a path in terminal." << std::endl;
    std::cout << "  2. Quit. " << std::endl;
    std::cout << ">> ";
}

int get_input()
{
    int temp = 0;
    std::cin >> temp;
    return temp;
}


int main()
{
    int menu_choice = 0;

    int board[MAX_NUM_ROWS][MAX_NUM_COLS];
    initialize_board(board);

    while (menu_choice != 2)
    {
        print_menu();

        menu_choice = get_input();

        if (menu_choice == 1)
        {
            std::pair<int, int> first_move;
            first_move = board_choice();
            initialize_board(board);
            board[first_move.first][first_move.second] = 0;

            if (kt_utility(first_move.first, first_move.second, 0, board))
            {
                std::cout << std::endl;
                print_board(board);
                std::cout << std::endl;
            }
            else
            {
                std::cout << "There is no solution." << std::endl;
                std::cout << std::endl;
            }
        }
        if (menu_choice == 2)
        {
            break;
        }

        initialize_board(board);
    }

    return 0;
}