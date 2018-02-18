# 2/18/2018 1:25 am znathan Nathan Zhu
# creating a basic framework for a card class

class Card:
    suits = ['Spades', 'Hearts', 'Diamonds', 'Clubs']
    ranks = [2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14]

    def __init__(self, suit, rank):
       self.suit = suit
       self.rank = rank

    def __lt__(self, other):
        return 
    


class Deck(Card):
     def __init__(self):
         self.card_list[]
         for index, suit in enumerate(suits):
             for index, rank in enumerate(ranks):
                 card_list[i * len(rank) + j] = Card(suit, rank)
