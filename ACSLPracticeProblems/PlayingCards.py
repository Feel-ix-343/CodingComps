from num2words import num2words as n


key = {**{'A': 'Ace', 'J': 'Jack', 'Q': 'Queen', 'K': 'King', 'D': 'Diamonds', 'H': 'Hearts', 'S': 'Spades',
          'C': 'Clubs'}, **{f'{i}': n(i)[0].upper() + n(i)[1:] for i in range(2, 11)}}

while True:
    print(' of '.join([key[val] for val in input('Enter Notation: ').upper()]))



