# 2/18/2018 1:25 am znathan Nathan Zhu
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
        


def main():  
    #c1 = Card("Spades", 14)
    #print(c1)
    deck1 = Deck()
    for i in deck1.card_list:
        pass
       # print i

    deck1.shuffle()
    for i in deck1.card_list:
        pass
        #print i

    p1 = Player(deck1.card_list)
    p1.print_hand()

if __name__ == '__main__':
    main()
