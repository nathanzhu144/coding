import card

class Game:
    def __init__(self):
    
    def play_game(self):
        print_menu()
        menu_choice = input()

        while True:
            if not input_is_valid(menu_choice)
                while input_is_valid(menu_choice)
                   invalid_input_menu(menu_choice)
                   print_menu()
                   menu_choice = input()
            
            if menu_choice == 1 
                

                

        number_turns_to_win = 0


    def print_menu(self):
        print('Welcome to the simulator for card war!')
        print('--------------------------------------')
        print('Option 1: Run simulations.')
        print('Option 2: Quit.')


    def input_is_valid(self, input):
        if input != 2 and input != 1:
            return False
        else:
            return True

    def invalid_input_menu(self, input):
        print('Your input was ' + input)
        print('Invalid choice, please try again.')


    def simulation_menu(self):
        print('How many times would you like to simulate?')

    def start_simulation(self):


    def game_setup(self):
        deck = Deck()
        deck.shuffle()
        player1 = Player(deck[0 : len(deck) / 2])
        player2 = Player(deck[len(deck) / 2 : 0])

    def initialize_statistics(self):

