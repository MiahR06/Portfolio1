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
void instructionsReg();
void display();
int chooseSquare(int player, char playerSymbol);
int checkInput(int i, int player, char playerSymbol);
int changeSquare(int i, int player, char playerSymbol);
void win(int player, char playerSymbol);

// Portfolio 2 functions
void instructionBattle(void);
bool checkMark(char mark, int player);
void chooseMark(int player);
bool checkClass(int classChoose, int player);
void chooseClass(int player);
void chooseMove(int player);
void alchemist(int player);
void paladinCheck(int player, int sq1, int sq2);
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


void instructionsReg(void){

    cout << "Let's start this regular game of Tic Tac Toe!\n\n";

    cout << "HOW TO PLAY\n";
    cout << "-------------------------------\n\n";
    cout << "This is a two player game where you will take turns choosing an available square until one player wins.\n\n";
    cout << "Player 1 is X, player 2 is O.\n\n";

    cout << "The game will start in a few seconds.\nHave fun!";
    this_thread::sleep_for(chrono::seconds(9));                // Pauses before moving on, allows time to read instructions
    cout << "\n";
}

void instructionBattle(void){

    cout << "Let's start this battle game of Tic Tac Toe!\n\n";

    cout << "HOW TO PLAY\n";
    cout << "-------------------------------\n\n";
    cout << "This is a two player game where you will take turns choosing an available square until one player wins.\nHowever, you will each have an ability to use.\n\n";

    cout << "You will choose your marks & classes in a few seconds.\nHave fun!";
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

    if (isalpha(mark) || mark != '?' || mark != '!' || mark != '*' || mark != '~' || mark != '$' || mark != '%' || mark != '#'){
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
            p1Class = "Alchemist";
        }else if (checkClass(p1ClassChoose, 2)){
            p1Class = "Paladin";
        }
    }else if (player == 2){
        cin >> p2ClassChoose;
        if (checkClass(p2ClassChoose, 1)){
            p2Class = "Alchemist";
        }else if (checkClass(p2ClassChoose, 2)){
            p2Class = "Paladin";
        }
    }
}

void chooseMove(int player){
    char ch;
    
    cout << "player " << player <<", would you like to choose a regular move or us ability?\n";
    cout << "(a) Regular move\n(b) Use ability\n\n";
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
    int sq1, sq2;
    
    cout << "Choose the first box to swap from: ";
    cin >> sq1;
    cout << "Choose the second box to swap with: ";
    cin >> sq2;

    if (box[sq1] == box[sq2]){
        cout << "Cannot swap the same marks. Try again.\n";
        clearInput(sq1);
        clearInput(sq2);
        alchemist(player);
    }else if (turn == 1 || turn == 2){
        cout << "There are not enough marks to swap. Please make a regular move.\n";
        if (player == 1){
            clearInput(sq1);
            clearInput(sq2);
            chooseSquare(player, p1Mark);
        }else if (player == 2){
            clearInput(sq1);
            clearInput(sq2);
            chooseSquare(player, p2Mark);
        }
    }else if (sq1 < 1 || sq1 > 9 || sq2 < 1 || sq2 > 9){
        cout << "Invalid positions. Try again.\n";
        clearInput(sq1);
        clearInput(sq2);
        alchemist(player);
    }else if (isdigit(box[sq1]) || isdigit(box[sq2])){
        cout << "\nThere is no mark in one or both of these squares. Try again.\n";
        clearInput(sq1);
        clearInput(sq2);
        alchemist(player);
    }else{
        swap(box[sq1], box[sq2]);
        if (player == 1){
            win(player, p1Mark);
        }else if (player == 2){
            win(player, p2Mark);
        }
        turn++;
    }
}

void paladinCheck(int player, int sq1, int sq2){
// To check adjacent squares

    // I don't know how to fix this grid to work
    int adjacency[10][4] = {
        {},
        {2, 4, 5},
        {1, 3, 5},
        {2, 5, 6},
        {1, 5, 7},
        {1, 2, 3, 4, 6, 7, 8, 9},
        {3, 5, 9},
        {4, 5, 8},
        {5, 7, 9},
        {5, 6, 8}
    };

    bool adj = false;
    for (int i=0; i<4; ++i){
        if (adjacency[sq1][i] == sq2){
            adj = true;
            break;
        }
    }
    
    int hold;

    if (adj == false){
        cout << "\nSquare " << sq2 << " is not adjacent to square " << sq1 << ". Try again.\n";
        paladin(player);
    }else if (adj == true){
        box[hold] = box[sq2];
        box[sq2] = box[sq1];
        box[sq1] = box[hold];
        if (player == 1){
            win(player, p1Mark);
        }else if (player == 2){
            win(player, p2Mark);
        }
        turn++;
    }

}

void paladin(int player){
    int sq1, sq2;
    
    cout << "Choose the first box to shift from: ";
    cin >> sq1;
    cout << "Choose the second box to shift to: ";
    cin >> sq2;

    if (isdigit(box[sq1])){
        cout << "\nThere is no mark in square " << sq1 << ". Try again.\n";
        clearInput(sq1);
        clearInput(sq2);
        paladin(player);
    }else if (!isdigit(box[sq2])){
        cout << "\nSquare " << sq2 << "is taken. Try again.\n";
        clearInput(sq1);
        clearInput(sq2);
        paladin(player);
    }else if (sq1 < 1 || sq1 > 9 || sq2 < 1 || sq2 > 9){
        cout << "Invalid positions. Try again.\n";
        clearInput(sq1);
        clearInput(sq2);
        paladin(player);
    }else{
        paladinCheck(player, sq1, sq2);
    }

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
    instructionsReg();

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
    instructionBattle();
    chooseMark(1);
    chooseMark(2);
    chooseClass(1);
    chooseClass(2);

    while (true){
        display();
        chooseMove(1);
        if (gameEnd == true){
            break;
        }

        display();
        chooseMove(2);
        if (gameEnd == true){
            break;
        }
    }
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
        return closingMenu(choice);
    }
    return 1;
}