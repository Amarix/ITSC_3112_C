/**
TicTacToe Game in C++
Print board prompt players for their moves.
Skip the turn if player enters a move that is invalid.

@Author Allie Beckman
Class ITCS 3112 @ UNCC

Date: 9/7/18
**/

#include <iostream>
#include "TicTacToe.h"

using namespace std;

int main()
{

    int numbers[] = {10,20,30,40,50};

    cout << *(numbers + 3) << endl;

    int *ptr;

    *ptr = 23;

    TicTacToe game;

    cout << game.newGameHeader << endl; // prints new game header including welcome message and rules

    while (!game.gameOver){ // while game is not over this will loop will iterate through each turn using the basic functions of the TicTacToe.cpp and .h files.

        game.printBoard(game.gBrd); // first prints the current game board using the main array updated through the game.

        game.promptPlayer(game.turnCounter); // uses the turn counter to determine which turn it is then prompts that player to select their move.

        cout << "You entered: " << game.userInput << endl; // states back to the player what they entered as a move.

        game.checkMove(game.userInput, game.gBrd, game.turnCounter); // checks move based on user input, the current game board and whos turn it is.

        game.turnEnd(game.gBrd); // ends the turn saves the state of the game board, changes the state of the bool gameOver if the game is over.
    }

    game.printBoard(game.gBrd); // once the game is over this prints the final board with the winning marks on it.
    cout << "THE GAME IS OVER!" << endl; // signals that the game is over.
}
