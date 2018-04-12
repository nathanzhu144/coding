
# creating a basic framework for a card class
from collections import deque
import random

# Helper functions

# This function converts a numerical rank to its
# alphabetical representation in a string
def card_rank_to_string(rank):
    if rank == 11:
        return 'Jack'
    elif rank == 12:
        return 'Queen'
    elif rank == 13:
        return 'King'
    elif rank == 14:
        return 'Ace'
    else:
        return str(rank)
        

class Card:
    def __init__(self, suit, rank):
   
       self.suit = suit
       self.rank = rank

    def __str__(self):
        return card_rank_to_string(self.rank) + ' of ' + self.suit

    def __lt__(self, other):
        if self.rank < other.rank:
            return True
        else:
            return False

    def __gt__(self, other):
        if self.rank > other.rank:
            return True
        else:
            return False
    
    def __eq__(self, other):
        if self.rank == other.rank:
            return True
        else:
            return False



class Deck(Card):
    suits = ['Spades', 'Hearts', 'Diamonds', 'Clubs']
    ranks = [2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14]

    def __init__(self):
        self.card_list = []
        for suit_index, suit in enumerate(self.suits):
            for card_index, rank in enumerate(self.ranks):
                self.card_list.append(Card(suit, rank))

    def __bool__(self):
        if card_list:
            return True
        else:
            return False

    
    def shuffle(self):
        unshuffled_list = self.card_list
        shuffled_list = []
        while unshuffled_list:
            shuffled_list.append(unshuffled_list.pop(random.randrange(len(unshuffled_list))))
        self.card_list = shuffled_list


class Player: 
    def __init__(self, starting_hand):
        self.hand = deque(starting_hand)

    def play_card(self):
        return self.hand.pop()

    def win_play(self, won_cards):
        self.hand.append(won_card)

    def cannot_wage_war(self):
        if (len(self.hand) >= 4):
            return False
        else:
            return True

    def win_war(self, won_cards):
        self.hand.append(deque(won_cards))

    def has_lost_round(self):
        return not self.hand
        

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






 

def main():  
    print('Testing overloaded card printing for suit')
    print('-------------------------------------------')
    c1 = Card("Spades", 14)
    c2 = Card("Hearts", 13)
    c3 = Card("Hearts", 12)
    c4 = Card("Hearts", 11)
    c5 = Card("Hearts", 10)
    c6 = Card("Hearts", 9)
    c7 = Card("Hearts", 8)

    print(c1)
    print(c2)
    print(c3)
    print(c4)
    print(c5)
    print(c6)
    print(c7)
    print()
    
    print('Testing deck generation')
    print('-------------------------')
    deck1 = Deck()
    for i in deck1.card_list:
        print(i)
    print()


    print('Testing deck shuffle')
    print('-------------------------')
    deck1.shuffle()
    for i in deck1.card_list:
        print(i)
    print()

    p1 = Player(deck1.card_list)
    #p1.print_hand()

if __name__ == '__main__':
    main()
