/**
TicTacToe Game in C++
Print board prompt players for their moves.
Skip the turn if player enters a move that is invalid.

@Author Allie Beckman
Class ITCS 3112 @ UNCC

Date: 9/7/18
**/

#include "TicTacToe.h"
#include <string>
#include <iostream>

using namespace std;

// The string that prints at the begining of the game with the rules.
string TicTacToe::newGameHeader = "Welcome to TicTacToe!\n\RULES:\n\To make your move type the number that matches the place on the board you wish to mark.\n\if you enter a number that is not available on the board your turn will be skipped.";

// the value that each player inputs when taking their turn
string TicTacToe::userInputString;

int
    TicTacToe::turnCounter = 1, // the counter that keeps track of whos turn it is. 0 is player B and 1 is player A
    TicTacToe::userInput = 0, // the value that will be compaired to the places in the game board to determin where the player wants to make their mark. This value is converted from the char version of the users input.
    TicTacToe::winCondish = 0; // The value that will be tested when determining if the game is over or if the game is still on. 1 means player A wins 2 means player B wins and 3 means it's a cats game. 0 means the game is still in session.

// game board each value stands for a spot on the board.
int TicTacToe::gBrd[3][3] = {{1,2,3},{4,5,6},{7,8,9}};

// boolean that will return true if all the spaces on the board are marked but there are no winners.
bool TicTacToe::catsGame = false;

// when the game is over this will change to true and end the loop in the main function.
bool TicTacToe::gameOver = false;

// class initialization
TicTacToe::TicTacToe(){

}

/**
takes the array containing the game board and prints it one value at a time in between lines to make a board within the console.
The initial values of the game board are 1 through 9.
If a value is 11 that means player B made their mark there and it will print an O.
If a value is 13 that means player A made their mark there and it will print an X.
**/
void TicTacToe::printBoard(int gmBd[3][3])
{
    for (int i = 0; i < 3; i++){ // iterates through the rows of the array
        cout << "__________" << endl; // prints a line to seperate rows
        for (int j = 0; j < 3; j++){ // iterates through the columns of the array
            if (gmBd[i][j]<10){ // if the value at this location in the array is less than 10 print the number value
                cout << "|" << gBrd[i][j] << "|";
            }else if (gmBd[i][j] < 12){ // if the value at this location in the array is greater than 10 but less than 10 it's player Bs mark. Print an O
                cout << "|" << "O" << "|";
            }else if (gmBd[i][j] > 12){ // if the value at this location in the array is greater than 12 it's player As mark. Print an X
                cout << "|" << "X" << "|";
            }
        }
        cout << endl;
    }
}

/**
If the turn counter is on 0 it's player B's turn if the counter is 1 the turn is player A's.
This prints out a prompt reminding the player that an incorrect move will result in them being skipped.
It then states whos turn it is and which mark belongs to that player.
Player B makes the mark O
Player A makes the mark X
**/
void TicTacToe::promptPlayer(int tCounter){

    string playerPrompt = "New turn! Please type a number for a space that is left on the board!\n\Don't forget, if you type one that doesn't exist you will be skipped.";
    string pBHeader = "Turn: Player B - (O)"; // player B header states it's their turn and their mark is an O
    string pAHeader = "Turn: Player A - (X)"; // player A header states it's their turn and their mark is an X

    cout << playerPrompt << endl; // prints the prompt to let the player know it's a new turn. Remindes player that if they enter an invalid number their turn will be skipped.

    if (tCounter == 0){ // if the turn counter == 0 it's player B's turn. Print their header.
        cout << pBHeader << endl;
    }
    else if (tCounter == 1){ // if the turn counter == 1 it's player A's turn. print their header.
        cout << pAHeader << endl;
    }
    else {
        cout << "ERROR WITH TURN COUNTER. function promptPlayer()" << endl; // prints if the counter is not 1 or 0. It means one of the functions was called out of order.
        TicTacToe::gameOver = true; // there was an error. End game.
    }

    cin >> userInputString; // accepts user input.

    if (userInputString.size() > 1){ // tests length of the user input. If it's more than one character it's invalid.
        cout << "Invalid input turn skipped." << endl;
    }else{
        try {
            userInput = stoi(userInputString); //attempts to turn the string into an integer. If the user inputed a letter or a symbol instead of a number between 0 and 10 their entry is invalid.
        }
        catch(const std::invalid_argument& ia){
            cout << "Invalid input turn skipped." << endl;
        }
    }
}

/**
takes the user input, the array containing the current game board and the int that determines whos turn it is.
depending on whos turn it is, if the move is valid (meaning the spot has not already been taken, and the number entered is between `1 and 9)
this method will insert an 11 (which means player B made a mark there and will result in an O) or a 13 (meaning player A made a mark here and will result in an X)
**/
void TicTacToe::checkMove(int uInput, int gmBrd[3][3], int plrTurn){

    int i; // an int created to shorten the number of iterations necessary each time a move is made.
    int j = 0;// made for the for loop. if the entry is invalid this will be changed to 3 so that the for loop doesn't run.

    if (uInput > 0 && uInput < 4){ // if the input is between 0 and 4 it's on the first row. Making i = 0 means it will only iterate through the first row in the for loop
        i = 0;
    }else if (uInput < 7){ // if the input is between 4 and 7 it's on the second row. Making i = 1 means it will only iterate through the second row in the for loop
        i = 1;
    }else if (uInput < 10){ // if the input is between 7 and 10 it's on the third row. Making i = 2 means it will only iterate through the third row in the for loop
        i = 2;
    }else{
        cout << "Input is invalid turn skipped." << endl; // if the char doesn't equal any of these numbers the entry is invalid.
        j = 3; // the for loop will not run. Turn has been skipped.
    }

    for (j; j < 3; j++){ // iterate through each column in the row corresponding to the int i (decided in the if else statements above)
        if (gmBrd[i][j] == uInput){ // if there is a value in the array corresponding to the users input that is where their mark will be placed in the array.
            if (plrTurn == 0){ // if the turn counters value is 0 it's player B's turn so the new value in the array will be 11.
                gmBrd[i][j] = 11;
            }else if (plrTurn == 1){ // if the turn counters value is 1 it's player A's turn so the new value in the array will be 13.
                gmBrd[i][j] = 13;
            }else{
                cout << "ERROR IN PLAYER TURN COUNTER. function checkMove()" << endl;// if the turn counter is not 1 or 0 there was an error in the program.
                TicTacToe::gameOver = true; // error in the program. End game.
            }
        }
    }

    TicTacToe::gBrd == gmBrd; // The board state is saved to the main board variable.
}

/**
Changes the value of the turn counter so that the correct player is prompted.
turn counter = 0 means it's player B's turn
turn counter = 1 means it's player A's turn
**/
void TicTacToe::nextTurn(){
    if (TicTacToe::turnCounter == 0){ // if the counter is 0 it was player B's turn.
        TicTacToe::turnCounter++; // Add 1 so the counter is now 1 and it becomes player A's turn.
    }else if (TicTacToe::turnCounter == 1){ // if the counter is 1 it was player A's turn.
        TicTacToe::turnCounter--; // Subtract 1 so the counter is now 0 and it becomes player B's turn.
    }else{
        cout << "ERROR IN TURN COUNTER. function nextTurn()" << endl; // the counter should be 1 or 0 if it is not there is an error in the program.
        TicTacToe::gameOver = true; // error in the program. End game.
    }
}

/**
This function accepts the current state of the game board array and tests the values using the getWinCondish() and checkForCats() functions.
If there are three of the same marks in a row the getWinCondish() function will announce it and this function will return true as the value for
the gameOver variable allowing the while loop in the main.cpp to stop going through the game processes.
If there is a cats game this function will also change the gameOver value to true. Otherwise the value will stay the same (false) and the game will continue
until one of these conditions are met.
**/
void TicTacToe::turnEnd(int gameBd[3][3]){

    int winCnd = getWinCondish(gameBd); // this function checks to see if there are any three marks in a row, column, or diagonal.
    bool ctsGm = checkForCats(gameBd); // this function checks to see that there are still spaces available to move on the board.

    if (winCnd == 1){ // winCondish # 1 means player A wins.
        cout << "PLAYER A WINS!____________________________________" << endl;
        TicTacToe::gameOver = true; // end game
    }else if (winCnd == 2){ // winCondish # 2 means player B wins.
        cout << "PLAYER B WINS!____________________________________" << endl;
        TicTacToe::gameOver = true; // end game
    }else if (ctsGm){ // if it's a cats game nobody wins it's a tie.
        cout << "IT'S A TIE!!!____________________________________" << endl;
        TicTacToe::gameOver = true; // end game
    }

    TicTacToe::nextTurn(); // Now that the turn is over and the mark has been placed on the board the nextTurn function is called to change the turn counter value
}

/**
Accepts the array/gameboard as an argument and tests all different winning condishions to see if there is a winner.
If it finds a row or column or diagnial that has three of the same values in a row it will call the function conclusion()
which sends back a 1 2 or 0. 1 means player A won 2 means player B won. It should not send back a 0 unless there has been an error in the game process.
**/
int TicTacToe::getWinCondish(int gb[3][3]){
    int winCond = 0; // a 0 means no one has won yet so this is the default value.
    for (int i = 0; i < 3; i++){
        if (gb[i][0]==gb[i][1]&&gb[i][0]==gb[i][2]){ // tests if the values in row i are a match (3 in a row)
            winCond = TicTacToe::conclusion(gb[i][0]); // if they match send the marks # to the conclusion() function to get the conclusion number 1 or 2 depending on which players mark matched.
        }else if(gb[0][i]==gb[1][i]&&gb[0][i]==gb[2][i]){ // tests if the values in column i are a match (3 in a row)
            winCond = TicTacToe::conclusion(gb[0][i]); // if they match send the marks # to the conclusion() function to get the conclusion number 1 or 2 depending on which players mark matched.
        }
    }
    if (gb[0][0]==gb[1][1]&&gb[0][0]==gb[2][2]){ // tests if the values in the diagonal top left to bottom right match (3 in a row)
        winCond = TicTacToe::conclusion(gb[0][0]); // if they match send the marks # to the conclusion() function to get the conclusion number 1 or 2 depending on which players mark matched.
    }else if (gb[2][0]==gb[1][1]&&gb[2][0]==gb[0][2]){ // tests if the values in the diagonal bottom left to top right match (3 in a row)
        winCond = TicTacToe::conclusion(gb[2][0]); // if they match send the marks # to the conclusion() function to get the conclusion number 1 or 2 depending on which players mark matched.
    }
    return winCond; // return the winning condition. 1 for player A. 2 for player B. 0 if there is no winner yet.
}

/**
accepts the value found to be in a row from the function getWinCondish()
if the value is an 11 the winner is player B
if the value is a 13 the winner is player A
This should not be called if three values are not found in a row.
**/
int TicTacToe::conclusion(int winningMark){
    if (winningMark == 11){ // if the value of the three matching numbers from the array in the function getWinCondish() is 11 the winner is B.
        return 2;
    }else if(winningMark == 13){ // if the value of the three matching numbers from the array in the function getWinCondish() is 13 the winner is A.
        return 1;
    }else{
        cout << "ERROR IN CONCLUSION TEST. function conclusion()" << endl; // conclusion() should not be called unless the program finds 3 matching marks in a row. If the marks value is not 11 or 13 there has been an error in the program.
        TicTacToe::gameOver = true; // error. End game.
    }
}

/**
This method is called before each turn to make sure there are still places available for play.
It is only called after the getWinCondish() method has been called and before the next turn starts.
If any of the values within the game board array are between 1 and 9 then there are still spaces available
so this will return false (it is not a cats game).
If after iterating through the entire board, there are no more values between 1 and 9 that means there are no more
spaces for the players to mark and there hasn't been a winner (since this was called after the winning condish check.
The game is over and it is a cats game. This will then return true.
**/
bool TicTacToe::checkForCats(int gmBoard[3][3]){
    for (int i = 0; i < 3; i++){ // loops through every row of the game array/board
        for (int j = 0; j < 3; j++){ // loops through every column of the game array/board
            if (gmBoard[i][j] < 10){ // if there is a value left in the array/board that is between 0 and 10 then there is still a space left to be marked.
                return false; // the game still has a space to be played. this is not a cats game yet. cats game = false.
            }
        }
    }
    return true; // all spaces have been checked. There are no more spaces for the players to move. Cats game = true;
}



