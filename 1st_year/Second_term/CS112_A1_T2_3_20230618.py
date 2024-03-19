# File: CS112_A1_T2_3_20230618.py

# Purpose: This is a two-player mathematical game of strategy. It is played by two 
#people with a pile of coins (or other tokens) between them. The players take turns removing 
#coins from the pile, always removing a non-zero square number of coins (1, 4, 9, 16, …). 
#The player who removes the last coin wins.

# Author: mohamed ayman afifi

# ID: 20230618

################################################################
import math
#functions to ensure players choise
def your_tern1():
    while True:
        strnum = input("Player1 -> Enter a square number to subtract: ")
        if(not strnum.isnumeric()):
            print("Please enter a number")
        else:
            num = int(strnum)
            if(math.sqrt(num).is_integer()):
                return num
            else:
                print('This is not a perfect square number')

def your_tern2():
    while True:
        strnum = input("Player2 -> Enter a square number to subtract: ")
        if(not strnum.isnumeric()):
            print("Please enter a number")
        else:
            num = int(strnum)
            if(math.sqrt(num).is_integer()):
                return num
            else:
                print('This is not a perfect square number')

##################################################

#loop to check if you want to play again
again = "yes"
while again == "yes":
#choose the number of coins in the pile and set it to be greater than zero
    while True:
        strcoins = input("Enter the number of coins in the pile: ")
        if not strcoins.isnumeric():
            print("Please enter a number")
        elif int(strcoins) <= 0:
            print("please enter a postive number")
        else:
            coins = int(strcoins)
            break
    #Display initial game status
    print("the number of coins in the pile is", coins)

    #game loop
    while True:
        player1 = your_tern1()
        coins=coins - player1
        if(coins <= 0):
            print("Player 2 wins")
            break
        print("coins:", coins)
        player2 = your_tern2()
        coins = coins - player2
        if(coins <= 0):
            print("Player 1 wins")
            break
        print("coins:", coins)
    again = input("if you want to play again press yes: ")