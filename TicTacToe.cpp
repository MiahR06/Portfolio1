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
    cout << "Press enter to continue: ";
    cin.ignore(10000, '\n');
    cin.get();
}

// Functions
void checkMark(char mark);
void chooseMark();
void changeSquare(int sq, int player, char mark);
void win(int player, char m);
void alchemist(int player);
void paladinCheck(int player, int sq1, int sq2);
void paladin(int player);
void oppAbility(int battleNum);
void story();
void battle(int battleNum);

// Game variables
int step = 0;                   // Keep track of each step of the game to progress story
char box[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
int sq = 0;      // Used to choose a square
int turn = 1;
bool battleEnd = false;
bool p1win, p2win;

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

// Opponent stats
int oppHealth;
int oppAttack;
int oppDefense;

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

void stats(){
    cout << endl << name << "'s Stats:" << endl << "--------------" << endl;
    cout << "Class:    " << classType << endl;
    cout << "Health:   " << health << endl;
    cout << "Attack:   " << attack << endl;
    cout << "Defense:  " << defense << endl;
    cout << "Money:    $" << money << endl << endl;
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

    cout << "Firstly, what is your name, hero?: ";
    cin >> name;
    if(cin.fail() || name.empty()){ 
        clearInput(name);
        setup();
    }

    chooseClass();
}

void chooseSquare(int player, char m){

    if(player == 1){
        cout << name <<", enter a number to choose a square: ";
        cin >> sq;       // Choose a square

        if (cin.fail()){
            clearInput(sq);
            cout << "\nThat is not a valid square. Try again.\n\n";
            chooseSquare(player, m);
        }else if (sq < 1 || sq > 9){
            clearInput(sq);
            cout << "\nThat is not a valid square. Try again.\n\n";
            chooseSquare(player, m);
        }else{
            changeSquare(sq, player, m);
        }
    }else if(player == 2){
        do{
            sq = rand() % 9 + 1;
        }while (!isdigit(box[sq]));

        cout << "Opponent chooses square " << sq << endl;
        changeSquare(sq, player, m);
    }
}

void changeSquare(int sq, int player, char m){

    if (!isdigit(box[sq])){
        cout << "\nThat space is taken. Try again.\n\n";
        chooseSquare(player, m);
    }else if (isdigit(box[sq])){
        box[sq] = m;
        win(player, m);
        turn++;
    }
}

void win(int player, char m){

    if(box[1] == m && box[2] == m && box[3] == m){
        battleEnd = true;
    }else if(box[4] == m && box[5] == m && box[6] == m){
        battleEnd = true;
    }else if(box[7] == m && box[8] == m && box[9] == m){
        battleEnd = true;
    }else if(box[1] == m && box[4] == m && box[7] == m){
        battleEnd = true;
    }else if(box[2] == m && box[5] == m && box[8] == m){
        battleEnd = true;
    }else if(box[3] == m && box[6] == m && box[9] == m){
        battleEnd = true;
    }else if(box[1] == m && box[5] == m && box[9] == m){
        battleEnd = true;
    }else if(box[3] == m && box[5] == m && box[7] == m){
        battleEnd = true;
    }else if (box[1] == m && box[2] == m && box[3] == m && box[4] == m && box[5] == m && box[6] == m && box[7] == m && box[8] == m && box[9] == m){
        battleEnd = true;
        p1win = false;
        p2win = false;
    }else{
        battleEnd = false;
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
        sq = rand() % 9 + 1;
    }while (!isdigit(box[sq]));

    if(box[sq] == mark){
        box[sq] = '0' + sq;
        cout << "A thief stole one of your marks!";
    }else{
        abilitySteal();
    }
    
}

void abilityJumble(){
    /*vector<char> marks;
    for(int j=1; j<=9; ++j){
        if (!isdigit(box[j])){
            marks.push_back(box[j]);
        }
    }
    random_shuffle(marks.begin(), marks.end());
    int index = 0;

    for(int j=1; j<=9; ++j) {
        if (!isdigit(box[j])) {
            box[j] = marks[index++];
        }
    }*/

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
        box[j] = '0' + j;
    }
    cout << "The Kind has erased all the marks!";
}

void oppAbility(int battleNum){
    int randomMove = rand()%100;
    if(battleNum == 1){
        chooseSquare(2, oppMark);
    }
    if(randomMove >= 25){
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
            }else{
                chooseSquare(2, oppMark);
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

void story(){

    if(step == 0){
        cout << "A group of thieves have stolen a precious family heirloom; A magical amulet.\nYou must go on a journey to find and retrieve that amulet before it is used for something terrible...\n\nIn this world, you have to use Tic-Tac-Toe to battle your opponents.\n\n";

        pressEnter();
    }else if(step == 1){
        cout << "You begin your journey when a wild beast jumps out and blocks your path. You ready your attack, when you remember you have to fight using Tic-Tac-Toe.\nSurprisingly, the beast knows how to play.\n\n";

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

void oppStats(int battleNum){

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
}

void gainMoney(int battleNum){
    int reward = 0;
    switch(battleNum){
        case 1:
            reward = 30;
            break;
        case 2:
            reward = 50;
            break;
        case 3:
            reward = 75;
            break;
        case 4:
            reward = 100;
            break;
        case 5:
            reward = 200;
            break;
    }

    money += reward;
    cout << "You earned $" << reward << ".\n";
}

void checkMoney(int m){

}

void eventShop(){
    while(true){
        cout << "Welcome to the shop! What would you like to buy?\nMoney: $" << money << endl;
        cout << "1) Potion (+50 health) ----------- $15\n";
        cout << "2) Protein (+20 attack) ---------- $20\n";
        cout << "3) Shield (+10 defense) ---------- $20\n";
        cout << "4) Strong Potion (+100 health) --- $30\n";
        cout << "5) Extra Protein (+30 attack) ---- $45\n";
        cout << "6) Great Shield (+25) ------------ $45\n";
        cout << "7) Leave Shop\n\n";

        cout << "Enter choice: ";
        cin >> item;

        if(cin.fail()){
            clearInput(item);
            cout << "That is not a valid option. Try again."
            eventShop();
        }else if(item == 1){
            cout << "You bought a Potion! -$15\n\n";
            money -= 15;
        }else if(item == 2){
            cout << "You bought a Protein! -$20\n\n";
            money -= 20;
        }else if(item == 3){
            cout << "You bought a Shield! -$20\n\n";
            money -= 20;
        }else if(item == 4){
            cout << "You bought a Strong Potion! -$30\n\n";
            money -= 30;
        }else if(item == 5){
            cout << "You bought an Extra Protein! -$45\n\n";
            money -= 45;
        }else if(item == 6){
            cout << "You bought a Great Shield! -$45\n\n";
            money -= 45;
        }else if(item == 7){
            cout << "Farewell, merchant.\n\n";
            break;
        }
    }
}

void events(int battleNum){

    switch(battleNum){
        case 1: // You trip
            cout << "\nYou trip on a rock and accidentally drop some money.\nA squirrel snatches it away before you could pick it up.\n\n";
            cout << "You lost $15...";
            money -= 15;
            
        case 2: // Event 2, you find an apple
            char ch;
            cout << "\nYou find a tasty looking apple alone in a tree.\nWill you eat it? (y/n): ";
            cin >> ch;

            if(cin.fail()){
                clearInput(ch);
                ch = 'n';
            }else if(ch == 'y' || ch == 'Y'){
                cout << "The apple was poisoned! You lose 15 health points...\n";
                health -= 15;
                if(health <= 0){
                    restart();
                }
            }else{
                cout << "You choose to not eat the apple and continue on your journey.\n\n"
            }
            pressEnter();

        case 3: // Shop event
            char ch, item;
            cout << "\nOn your journey, you stop by a merchant selling goods.\nWould you like to shop? (y/n): ";
            cin >> ch;

            if(cin.fail()){
                clearInput(ch);
                ch = 'n';
            }else if(ch == 'y' || ch == 'Y'){
                eventShop();
            }

        case 4: // Healing item
            cout << "";
    }

}

void restart(){
    cout << "\n[GAME OVER]\nYou blacked out... And woke up in your bed!\nIt was all a dream, but it's not over yet.";
    health = 300; 
    attack = 100; 
    defense = 100;
    money = 50;
    resetBox();
    step = 1;
    pressEnter();
    story();
}

void battle(int battleNum){

    oppStats(battleNum);
    resetBox();

    while(oppHealth > 0 && health > 0){
        chooseMove(1, battleNum);
        chooseMove(2, battleNum);

        if(battleEnd){
            display();

            if(p1win){
                cout << "You win the battle!";
                changeStats(oppHealth, attack, defense);
            }else if(p2win){
                cout << "You lose the battle!";
                changeStats(health, oppAttack, oppDefense);
            }else{
                cout << "The battle was a tie!";
            }

            cout << "Your health:       " << health << "\n\n";
            cout << "Opponent's health: " << oppHealth << "\n\n";
            pressEnter();
            resetBox();
        }
    }

    if(oppHealth <= 0){
        cout << "You have defeated your opponent!\n";
        gainMoney(battleNum);
        events(battleNum);
        step++;
    }else if(health <= 0){
        restart();
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