#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <utility>
#include <cctype>
using namespace std;

template <typename T>
void clearInput(T input){   // Function to clear invalid input
    cin.clear();
    cin.ignore(10000, '\n');
}

// Portfolio 1 variables
char box[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
int i = 0;      // Used to choose a square
int turn = 1;   // Keeps track of turns
bool gameEnd = false;

// Portfolio 2 variables
char p1Mark, p2Mark, p1ClassChoose, p2ClassChoose, choice;
string p1Class, p2Class;

// Portfolio 1 functions
void instructions();
void display();
int chooseSquare(int player, char playerSymbol);
int checkInput(int i, int player, char playerSymbol);
int changeSquare(int i, int player, char playerSymbol);
void win(int player, char playerSymbol);

// Portfolio 2 functions
bool checkMark(char mark, int player);      // Helper function
void chooseMark(int player);
bool checkClass(int classChoose, int player);
void chooseClass(int player);
void chooseMove(int player);
void alchemist(int player);
void paladin(int player);
void menu();
void regularGame();
void battleGame();
char closingMenu(char choice);


int main(){

    do{
        menu();
        closingMenu(choice);
    }while (choice == 'y');

    return 0;
}


void instructions(void){

    cout << "Let's start this regular game of Tic Tac Toe!\n\n";

    cout << "HOW TO PLAY\n";
    cout << "-------------------------------\n\n";
    cout << "This is a two player game where you will take turns choosing an available square until one player wins.\n\n";
    cout << "Player 1 is X, player 2 is O.\n\n";

    cout << "The game will start in a few seconds.\nHave fun!";
    this_thread::sleep_for(chrono::seconds(9));                // Pauses before moving on, allows time to read instructions
    cout << "\n";
}

void display(void){

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
        clearInput(i);
        cout << "\nThat is not a valid square. Try again.\n\n";
        return chooseSquare(player, playerSymbol);
    }else if (i < 1 || i > 9){
        clearInput(i);
        cout << "\nThat is not a valid square. Try again.\n\n";
        return chooseSquare(player, playerSymbol);
    //}else if(){     // Condition that stops player from entering more than one number
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



bool checkMark(char mark, int player){
    if (mark != isalpha(mark) || mark != '?' || mark != '!' || mark != '*' || mark != '~' || mark != '$' || mark != '%' || mark != '#'){
        clearInput(mark);
        cout << "That is not a valid mark.";
        chooseMark(player);
    }else{
        return (isalpha(mark) || mark == '?' || mark == '!' || mark == '*' || mark == '~' || mark == '$' || mark == '%' || mark == '#');
    }
    return 1;
}

void chooseMark(int player){
    char mark;
    cout << "\nPlayer " << player << ", choose your mark for this game: ";
    cin >> mark;
    if (player == 1){
        if (checkMark(p1Mark, 1)){
            p1Mark = mark;
        }
    }else if (player == 2){
        cin >> p2Mark;
        if (checkMark(p2Mark, 2)){
            p2Mark = mark;
        }
    }
}

bool checkClass(int classChoose, int player){
    if (classChoose != 1 && classChoose != 2){
        clearInput(classChoose);
        cout << "That is not a valid class.";
        chooseClass(player);
    }else{
        if (classChoose == 1){
            if (player == 1){
                return p1Class == "Alchemist";
            }else if (player == 2){
                return p2Class == "Alchemist";
            }
        }else if (classChoose == 2){
            if (player == 1){
                return p1Class == "Paladin";
            }else if (player == 2){
                return p2Class == "Paladin";
            }
        }
    }
    return 1;
}

void chooseClass(int player){
    cout << "\nPlayer " << player << ", choose your archetype, (1) Alchemist, (2) Paladin: ";
    if (player == 1){
        cin >> p1ClassChoose;
        if (checkClass(p1ClassChoose, 1)){
            //return p1Class;
        }
    }else if (player == 2){
        cin >> p2ClassChoose;
        if (checkClass(p2ClassChoose, 2)){
            //return p2Class;
        }
    }
}

void chooseMove(int player){
    char ch;
    
    cout << "player " << player <<", would you like to choose a regular move or us ability?\n";
    cout << "(a) Regular move\n(b) Swap marks\n\n";
    cout << "Enter a or b: ";
    cin >> ch;

    if (cin.fail()){
        clearInput(ch);
        chooseMove(player);
    }else if (ch == 'a'){
        if (player == 1){
            if (p1Class == "Alchemist"){
                alchemist(1);
            }else if (p1Class == "Paladin"){
                paladin(1);
            }
        }else if (player == 2){
            if (p2Class == "Alchemist"){
                alchemist(2);
            }else if (p2Class == "Paladin"){
                paladin(2);
            }
        }
    }
}

void alchemist(int player){
    int box1, box2;
    
    cout << "Choose the first box to swap from: ";
    cin >> box1;
    cout << "Choose the second box to swap with: ";
    cin >> box2;

    if (box[box1] == box[box2]){
        cout << "Cannot swap the same marks. Try again.\n";
        alchemist(player);
    }else if (turn == 1 || turn == 2){
        cout << "There are not enough marks to swap. Please make a regular move.\n";
        if (player == 1){
            chooseSquare(player, p1Mark);
        }else if (player == 2){
            chooseSquare(player, p2Mark);
        }
    }else if (box1 < 1 || box1 > 9 || box2 < 1 || box2 > 9){
        cout << "Invalid positions. Try again.\n";
        alchemist(player);
    }else if (isdigit(box[box1]) || isdigit(box[box2])){
        cout << "";
    }else{
        swap(box[box1], box[box2]);
        if (player == 1){
            win(player, p1Mark);
        }else if (player == 2){
            win(player, p2Mark);
        }
        turn++;
    }
}

void paladin(int player){

}

void menu(){
    int chooseGame;

    cout << "Welcome! Please select which Tic Tac Toe game you want to play:\n";
    cout << "(1) Regular game\n";
    cout << "(2) Battle game\n";

    while(true){
        cin >> chooseGame;

        if (chooseGame != 1 && chooseGame != 2){
            cout << "\nThat is not a valid game. Try again: ";
            clearInput(chooseGame);
        }else if (chooseGame == 1){
            regularGame();
            break;
        }else if (chooseGame == 2){
            battleGame();
            break;
        }
    }
}

void regularGame(){
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

void battleGame(){
    
}

char closingMenu(char choice){
    cout << "\nWould you like to play again? (y/n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y'){
        choice = 'y';
        return choice;
    }else if (choice == 'n' || choice == 'N'){
        cout << "\nThanks for playing!";
        return choice;
    }else{
        cout << "\nInvalid choice.";
        clearInput(choice);
        closingMenu(choice);
    }
    return 1;
}