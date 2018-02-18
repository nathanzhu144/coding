import card

class Game:
    def __init__(self):
    
    def play_game(self):
        print_menu()
        menu_choice = input()

        while True:
            if not input_is_valid(menu_choice):
                while input_is_valid(menu_choice):
                   invalid_input_menu(menu_choice)
                   print_menu()
                   menu_choice = input()
            
            if menu_choice == 1:
                while 

                

                

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


    def play_round(self, card_war_number):
        num_rounds = 0
        game_setup():
        while True:
            if (
                self.player1.has_lost_round() or 
                self.player2.has_lost_round() or
                self.player1.cannot_wage_war() or
                self.player2.cannot_wage_war()
                ):
                return num_rounds

            player1_card = self.player1.play_card()
            player2_card = self.player2.play_card()

            if player1_card < player2_card:
                self.player2.win_play([player1_card, player2_card])
            if player2_card < player1_card:
                self.player1.win_play([player2_card, player1_card])
            else:
                war_hand = []
                for x in range (0:3):
                   war_hand.append(self.player1.playcard())






    def simulation_menu(self):
        print('How many times would you like to simulate?')


    def start_simulation(self):


    def game_setup(self):
        deck = Deck()
        deck.shuffle()
        self.player1 = Player(deck[0 : len(deck) / 2])
        self.player2 = Player(deck[len(deck) / 2 : 0])

    def initialize_statistics(self):

