#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <ctime>
using namespace std;

template <typename T>
void clearInput(T input){   // Function to clear invalid input
    cin.clear();
    cin.ignore(99999, '\n');
}

void pressEnter(){
    cout << "Press enter twice to continue: ";
    cin.ignore(10000, '\n');
    cin.get();
}

// Functions
void checkMark(char mark);
void chooseMark();
void changeSquare(int i, int player, char mark);
void alchemist(int player);
void paladinCheck(int player, int sq1, int sq2);
void paladin(int player);
void oppAbility(int battleNum);
void battle(int battleNum);

// Game variables
int step = 0;                   // Keep track of each step of the game to progress story
char box[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
int i = 0;      // Used to choose a square
int turn = 1;
bool battleEnd = false;

// Player info
string name = "Name";
string classType = "Class";
char mark = 'X';
char oppMark = 'O';

// Player stats
int health = 300;
int attack = 100;
int defense = 100;
int money = 50;

void display(void){

    cout << "\n " << box[1] << " | " << box[2] << " | " << box[3] << "\n";
    cout << "-----------" << "\n"; 
    cout << " " << box[4] << " | " << box[5] << " | " << box[6] << "\n";
    cout << "-----------" << "\n"; 
    cout << " " << box[7] << " | " << box[8] << " | " << box[9] << "\n\n";
}

void resetBox() {
    for (int i = 1; i <= 9; ++i){
        box[i] = '0' + i;
    }
    battleEnd = false;
    turn = 1;
}

void events(){
    // After battle 1, 

    // After battle 2, find a tasty looking apple and give player option to eat it or not. it is poison

    // After battle 3, shop

    // After battle 4, 
}

void stats(){
    cout << endl << name << "'s Stats:" << endl << "--------------" << endl;
    cout << "Class:    " << classType << endl;
    cout << "Health:   " << health << endl;
    cout << "Attack:   " << attack << endl;
    cout << "Defense:  " << defense << endl;
    cout << "Money:     $" << money << endl << endl;
}

void win(int player, char mark){

    if(box[1] == mark && box[2] == mark && box[3] == mark){
        battleEnd = true;
    }else if(box[4] == mark && box[5] == mark && box[6] == mark){
        battleEnd = true;
    }else if(box[7] == mark && box[8] == mark && box[9] == mark){
        battleEnd = true;
    }else if(box[1] == mark && box[4] == mark && box[7] == mark){
        battleEnd = true;
    }else if(box[2] == mark && box[5] == mark && box[8] == mark){
        battleEnd = true;
    }else if(box[3] == mark && box[6] == mark && box[9] == mark){
        battleEnd = true;
    }else if(box[1] == mark && box[5] == mark && box[9] == mark){
        battleEnd = true;
    }else if(box[3] == mark && box[5] == mark && box[7] == mark){
        battleEnd = true;
    }else if (box[1] == mark && box[2] == mark && box[3] == mark && box[4] == mark && box[5] == mark && box[6] == mark && box[7] == mark && box[8] == mark && box[9] == mark){
        display();
        cout << "The battle was a tie!\n";
        battleEnd = true;
    }else{
        battleEnd = false;
    }

    if(battleEnd == true && player == 1){
        display();
        cout << "You win the battle!\n";
    }else if(battleEnd == true && player == 2){
        display();
        cout << "You lost the battle!\n";
    }
}

void chooseSquare(int player, char mark){

    if(player == 1){
        cout << name <<", enter a number to choose a square: ";
        cin >> i;       // Choose a square

        if (cin.fail()){
            clearInput(i);
            cout << "\nThat is not a valid square. Try again.\n\n";
            chooseSquare(player, mark);
        }else if (i < 1 || i > 9){
            clearInput(i);
            cout << "\nThat is not a valid square. Try again.\n\n";
            chooseSquare(player, mark);
        }else{
            changeSquare(i, player, mark);
        }
    }else if(player == 2){
        do{
            i = rand() % 9 + 1;
        }while (!isdigit(box[i]));

        cout << "Opponent chooses square " << i << endl;
        changeSquare(i, player, mark);
    }
}

void changeSquare(int i, int player, char mark){

    if (!isdigit(box[i])){
        cout << "\nThat space is taken. Try again.\n\n";
        chooseSquare(player, mark);
    }else if (isdigit(box[i])){
        box[i] = mark;
        win(player, mark);
        turn++;
    }
}

void story(){

    if(step == 0){
        cout << "A group of thieves have stolen a precious family heirloom; A magical amulet.\nYou must go on a journey to find and retrieve that amulet before it is used for something terrible...\n\nIn this world, you have to use Tic-Tac-Toe to battle your opponents.";

        pressEnter();
    }else if(step == 1){
        cout << "You begin your journey when a wild beast jumps out and blocks your path. You ready your attack, when you remember you have to fight using Tic-Tac-Toe. Surprisingly, the beast knows how to play.\n\n";

        pressEnter();
        battle(1);
    }else if(step == 2){
        cout << "\n\nYou make your way to a nearby town and spot the thieves sitting at a table with drinks, as if they're celebrating. You ask them what they did to your amulet.\n\n'Hah! We sold that ol' thing to those greedy sirens by the beach. For a good amount, too,' one of the thieves exclaim.\n\nYou don't have to, but you fight the thieves anyway.\n\n";

        pressEnter();
        battle(2);
    }else if(step == 3){
        cout << "\n\nAfter defeating the thieves, you leave to find the sirens that the thieves sold the amulet to. Who knows what those sirens will do.\n\n";

        cout << "Sitting by the beach, you find a group of sirens that seem to be in a mood. You approach them and ask to about the whereabouts of your amulet.\n\n'Go away! Can't you see we're upset?' The sirens initiate a battle with you out of frustration.";

        pressEnter();
        battle(3);

    }else if(step == 4){

        pressEnter();
        battle(4);
    }else if(step == 5){
        pressEnter();
        battle(5);
    }
    
}

void checkMark(char m){
    
    if (isalpha(m) || m == '?' || m == '!' || m == '*' || m == '~' || m == '$' || m == '%' || m == '#' || mark == 'O'){
        mark = m;
    }else{
        clearInput(mark);
        cout << "That is not a valid mark.\n";
        chooseMark();
    }
}

void chooseMark(){
    char m;
    cout << "\n" << name << ", choose your mark for this game\n(Note, opponents use 'O' and your default mark is 'X'): ";
    cin >> m;
    checkMark(m);
    
    stats();
    step++;
    story();
}

void chooseClass(){
    int classChoose;
    
    cout << "\n" << name << ", choose your archetype, (1) Alchemist, (2) Paladin: ";
    cin >> classChoose;
    if(classChoose == 1){
        classType = "Alchemist";
    }else if(classChoose == 2){
        classType = "Paladin";
    }else{
        clearInput(classChoose);
        cout << "Invalid class, try again.";
        chooseClass();
    }

    chooseMark();

}

void setup(){

    cout << "\n\nFirstly, what is your name, hero?: ";
    cin >> name;

    chooseClass();
}

void chooseMove(int player, int battleNum){

    if(player == 1){
        char ch;
    
        cout << "Would you like to choose a regular move or us ability?\n";
        cout << "(a) Regular move\n(b) Use ability\n\n";
        cout << "Enter a or b: ";
        cin >> ch;

        if (ch == 'b'){

            if(classType == "Alchemist"){
                alchemist(1);
            }else if(classType == "Paladin"){
                paladin(1);
            }
        }else if (ch == 'a'){
            chooseSquare(player, mark);
        }else{
            clearInput(ch);
            cout << "That is not a valid move.\n\n";
            chooseMove(player, battleNum);
        }
    }else if(player == 2){
        oppAbility(battleNum);
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
        cout << "There are not enough marks to swap. Please make a regular move. (Press enter)\n";
        if (player == 1){
            clearInput(sq1);
            clearInput(sq2);
            chooseSquare(player, mark);
        }else if (player == 2){
            clearInput(sq1);
            clearInput(sq2);
            chooseSquare(player, mark);
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
        win(player, mark);
        turn++;
    }
}

void paladinCheck(int player, int sq1, int sq2){
// To check adjacent squares

    bool adj = false;
    if (sq1 == 1 && (sq2 == 2 || sq2 == 4 || sq2 == 5)){
        adj = true;
    }else if (sq1 == 2 && (sq2 == 1 || sq2 == 3 || sq2 == 4 || sq2 == 5 || sq2 == 6)){
        adj = true;
    }else if (sq1 == 3 && (sq2 == 2 || sq2 == 5 || sq2 == 6)){
        adj = true;
    }else if (sq1 == 4 && (sq2 == 1 || sq2 == 2 || sq2 == 5 || sq2 == 7 || sq2 == 8)){
        adj = true;
    }else if (sq1 == 5 && (sq2 == 1 || sq2 == 2 || sq2 == 3 || sq2 == 4 || sq2 == 5 || sq2 == 6 || sq2 == 7 || sq2 == 8 || sq2 == 9)){
        adj = true;
    }else if (sq1 == 6 && (sq2 == 2 || sq2 == 3 || sq2 == 5 || sq2 == 8 || sq2 == 9)){
        adj = true;       
    }else if (sq1 == 7 && (sq2 == 4 || sq2 == 5 || sq2 == 8)){
        adj = true;
    }else if (sq1 == 8 && (sq2 == 4 || sq2 == 5 || sq2 == 6 || sq2 == 7 || sq2 == 9)){
        adj = true;
    }else if (sq1 == 9 && (sq2 == 5 || sq2 == 6 || sq2 == 8)){
        adj = true;
    }else{
        adj = false;
    }
    
    int hold = 0;

    if (adj == false){
        cout << "\nSquare " << sq2 << " is not adjacent to square " << sq1 << ". Try again.\n";
        paladin(player);
    }else if (adj == true){
        box[hold] = box[sq2];
        box[sq2] = box[sq1];
        box[sq1] = box[hold];
        win(player, mark);
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
        cout << "\nSquare " << sq2 << " is taken. Try again.\n";
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

void abilitySteal(){
    char takePlayer, takeOpp;
    do{
        i = rand() % 9 + 1;
    }while (!isdigit(box[i]));

    if(box[i] == mark){
        box[i] = i;
        cout << "A thief stole one of your marks!";
    }else{
        abilitySteal();
    }
    
}

void abilityJumble(){
    vector<char> allMarks;
    for(int j=1; j<=9; ++j){
        if (!isdigit(box[j])){
            allMarks.push_back(box[j]);
        }
    }
    //shuffle(allMarks.begin(), allMarks.end());
    int index = 0;

    for(int j=1; j<=9; ++j) {
        if (!isdigit(box[j])) {
            box[j] = allMarks[index++];
        }
    }

    cout << "The sirens use their strong voice and jumble up the marks!";
}

void abilityPlace(){
    int placed = 0;
    for(int tries=0; tries<20 % placed<2; ++tries){
        int j =rand()%9 + 1;
        if(isdigit(box[j])){
            box[j] = oppMark;
            placed++;
        }
    }
}

void abilitySwap(){
    for(int j=1; j<=9; ++j){
        if(box[j] == mark){
            box[j] = oppMark;
        }else if(box[j] == oppMark){
            box[j] = mark;
        }
    }
}

void abilityErase(){
    for(int j=1; j<=9; ++j){
        box[j] = j;
    }
}

void oppAbility(int battleNum){
    int randomMove = rand()%100;
    if (randomMove >= 25){
        chooseSquare(2, oppMark);
    }

    switch(battleNum){
        case 2: 
            abilitySteal();
            break;
        case 3:
            abilityJumble();
            break;
        case 4:
            if(turn % 3 == 0){
                abilityPlace();
            }
            break;
        case 5:
            int kingAbility = rand()%2;
            if(kingAbility == 0){
                abilitySwap();
            }else if(kingAbility == 1){
                abilityErase();
            }
            break;
    }
}

void battle(int battleNum){
    // Opponent stats
    int oppHealth;
    int oppAttack;
    int oppDefense;

    if(battleNum == 1){
        oppHealth = 250;
        oppAttack = 35;
        oppDefense = 15;
    }else if(battleNum == 2){
        oppHealth = 250;
        oppAttack = 45;
        oppDefense = 15;
    }else if(battleNum == 3){
        oppHealth = 250;
        oppAttack = 50;
        oppDefense = 20;
    }else if(battleNum == 4){
        oppHealth = 250;
        oppAttack = 50;
        oppDefense = 20;
    }else if(battleNum == 5){
        oppHealth = 300;
        oppAttack = 55;
        oppDefense = 30;
    }

    while(oppHealth > 0){
        display();
        chooseMove(1, battleNum);
        chooseMove(2, battleNum);

        //deduct points
        if(oppHealth <= 0){
            //end battle
            resetBox;
            break;
        }else if(health <= 0){
            //end battle
            //You lose message
        }
    }
}


void game(){

    story();
    setup();
    

}

int main(){

    srand(time(0));
    game();

    return 0;
}