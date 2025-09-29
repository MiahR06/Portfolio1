#include <iostream>
#include <string>
#include <chrono>
#include <thread>
using namespace std;

char box[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
int i = 0;      // Used to choose a square
int turn = 0;   // Keeps track of turns
bool gameEnd;

void instructions();            // Displays instructions
void display();                 // Displays board
int chooseSquare(int player, char playerSymbol);            // Allows player to choose square
int checkInput(int i, int player, char playerSymbol);       // Checks player input
int changeSquare(int i, int player, char playerSymbol);     // 

void checkTie(int player, char playerSymbol);
void win(int player, char playerSymbol);

int main(){

    instructions();

    while (true){
        display();
        chooseSquare(1, 'X');
        if (gameEnd == true){
            break;
        }
        display();
        chooseSquare(2, 'O');
        if (gameEnd == true){
            break;
        }
    }

}

void instructions(){

    cout << "Welcome! Let's start this game of Tic Tac Toe!\n\n";

    cout << "HOW TO PLAY\n";
    cout << "-------------------------------\n\n";
    cout << "This is a two player game where you will take turns choosing an available square until one player wins.\n\n";
    cout << "Player 1 is X, player 2 is O.\n\n";

    cout << "The game will start in a few seconds.\nHave fun!";
    this_thread::sleep_for(chrono::seconds(9));                // Pauses before moving on, allows time to read instructions
    cout << "\n";
}

void display(){

    cout << "\n " << box[1] << " | " << box[2] << " | " << box[3] << "\n";
    cout << "-----------" << "\n"; 
    cout << " " << box[4] << " | " << box[5] << " | " << box[6] << "\n";
    cout << "-----------" << "\n"; 
    cout << " " << box[7] << " | " << box[8] << " | " << box[9] << "\n\n";
}

int chooseSquare(int player, char playerSymbol){

    // Different output depending on player
    cout << "Player " << player <<", enter a number to choose a square: ";

    cin >> i;       // Choose a square   
    return checkInput(i, player, playerSymbol);
}

int checkInput(int i, int player, char playerSymbol){

    if (cin.fail()){
        cin.clear();
        cin.ignore(10000, '\n');        // Chose a large number to lessen the chances of a long input going through

        cout << "\nThat is not a valid square. Try again.\n\n";
        return chooseSquare(player, playerSymbol);
    }else if (i < 1 || i > 9){
        cout << "\nThat is not a valid square. Try again.\n\n";
        return chooseSquare(player, playerSymbol);
    }else{
        return changeSquare(i, player, playerSymbol);
    }

    return 1;
}

int changeSquare(int i, int player, char playerSymbol){

    if (box[i] == 'X' || box[i] == 'O'){
        cout << "\nThat space is taken. Try again.\n\n";
        return chooseSquare(player, playerSymbol);
    }else if (box[i] != 'X' || box[i] != 'O'){
        box[i] = playerSymbol;
        win(player, playerSymbol);
        turn++;
    }
    
    return 1;
}


void win(int player, char playerSymbol){

    if (box[1] == playerSymbol && box[2] == playerSymbol && box[3] == playerSymbol){
        display();
        cout << "Player " << player << " wins!\nThank you for playing!";
        gameEnd = true;
    }else if(box[4] == playerSymbol && box[5] == playerSymbol && box[6] == playerSymbol){
        display();
        cout << "Player " << player << " wins!\nThank you for playing!";
        gameEnd = true;
    }else if(box[7] == playerSymbol && box[8] == playerSymbol && box[9] == playerSymbol){
        display();
        cout << "Player " << player << " wins!\nThank you for playing!";
        gameEnd = true;
    }else if(box[1] == playerSymbol && box[4] == playerSymbol && box[7] == playerSymbol){
        display();
        cout << "Player " << player << " wins!\nThank you for playing!";
        gameEnd = true;
    }else if(box[2] == playerSymbol && box[5] == playerSymbol && box[8] == playerSymbol){
        display();
        cout << "Player " << player << " wins!\nThank you for playing!";
        gameEnd = true;
    }else if(box[3] == playerSymbol && box[6] == playerSymbol && box[9] == playerSymbol){
        display();
        cout << "Player " << player << " wins!\nThank you for playing!";
        gameEnd = true;
    }else if(box[1] == playerSymbol && box[5] == playerSymbol && box[9] == playerSymbol){
        display();
        cout << "Player " << player << " wins!\nThank you for playing!";
        gameEnd = true;
    }else if(box[3] == playerSymbol && box[5] == playerSymbol && box[7] == playerSymbol){
        display();
        cout << "Player " << player << " wins!\nThank you for playing!";
        gameEnd = true;
    }else if (turn == 8){
        cout << "\nThe game is a tie!\nThank you for playing!";
        gameEnd = true;
    }else{
        gameEnd = false;
    }  
}