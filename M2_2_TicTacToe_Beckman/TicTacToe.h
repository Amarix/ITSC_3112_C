/**
TicTacToe Game in C++
Print board prompt players for their moves.
Skip the turn if player enters a move that is invalid.

@Author Allie Beckman
Class ITCS 3112 @ UNCC

Date: 9/7/18
**/

#ifndef TICTACTOE_H
#define TICTACTOE_H
#include <string>

class TicTacToe
{
    public:

        TicTacToe();

        static std::string newGameHeader, userInputString; // New game header prints the rules and a welcome message. User input string is used to hold the initial value of each players input for their turn.

        static int turnCounter, userInput, winCondish; // Turn counter keeps track of whos turn it is. User input here is the converted integer value of the initial user input. winCondish is an int that defines who won and is passed to display the proper output.

        static int gBrd[3][3]; // contains the board and the space numbers. There are 9 spaces in a 3 by 3 tic tac toe board. This will also hold values 11 for an O and 13 for an X to track player moves.

        static bool catsGame, gameOver; // cats game is true if there are no more spaces for players to move on the board. gameOver is true if there is a winner or a cats game.

        void printBoard(int gB[3][3]); // method to print the game board for the users. Accepts the game board array as an argument

        void promptPlayer(int tCnter); // prompts the player for their turn. Accepts the turn counter as an argument.

        void checkMove(int uInpt, int gmBrd[3][3], int plrTurn); // accepts int user input, game board, and turn counter as an argument. Tests move to see if there is a winner or a cats game or if the move is invalid.

        int getWinCondish(int gamBrd[3][3]); // is used by turn end. accepts game board array, tests to see if there is a winner.

        bool checkForCats(int gameBrd[3][3]); // is used by turn end. accepts the board array as an argument. Tests to see if there are any moves left on the board.

        int conclusion(int wnnMrk); // is used by get win condish. Returns number corresponding to the winner.

        void nextTurn(); // is used by turn end. changes the turn counter in preperation for the next player.

        void turnEnd(int gmBoard[3][3]); // accepts the game board and uses getWinCondish, checkForCats, and nextTurn to determine game status to end game or set up next turn.

    protected:

    private:
};

#endif // TICTACTOE_H
