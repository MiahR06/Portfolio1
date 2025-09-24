#include <iostream>
#include <string>
#include <cctype>
using namespace std;

char box[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
int i = 0;
bool playerWin;

void display();
int choose(int player);
void win(int player);

int main(){

    while (true){
        display();
        choose(1);
        if (playerWin == true){
            break;
        }
        display();
        choose(2);
        if (playerWin == true){
            break;
        }
    }

    display();

}

void display(){

    cout << "\n " << box[1] << " | " << box[2] << " | " << box[3] << endl;
    cout << "-----------" << endl; 
    cout << " " << box[4] << " | " << box[5] << " | " << box[6] << endl;
    cout << "-----------" << endl; 
    cout << " " << box[7] << " | " << box[8] << " | " << box[9] << endl << endl;
}

int choose(int player){

    // Different output depending on player
    cout << "Player " << player <<", enter a number to choose a square: ";

    cin >> i;       // Choose a square

    if (cin.fail()){
        cout << "That is not a valid input. Try again." << endl;
        cin.clear();
        while (i){
            cin.ignore(1, '\n');
        }
        return choose(player);
    }

    if (i < 1 || i > 9){
        cout << "That is not a valid input. Try again." << endl;
        return choose(player);
    }else{
        if (box[i] == 'X' || box[i] == 'O'){
            cout << "That space is taken. Try again." << endl;
            return choose(player);
        }else if (box[i] != 'X' || box[i] != 'O'){
            if (player == 1){
                box[i] = 'X';
                win(1);
            }else if (player == 2){
                box[i] = 'O';
                win(2);
            }
        }
    }

    return 1;
}

void win(int player){

    if (player == 1){
        if (box[1] == 'X' && box[2] == 'X' && box[3] == 'X'){
            cout << "\nPlayer 1 wins!" << endl;
            playerWin = true;
        }else if(box[4] == 'X' && box[5] == 'X' && box[6] == 'X'){
            cout << "\nPlayer 1 wins!" << endl;
            playerWin = true;
        }else if(box[7] == 'X' && box[8] == 'X' && box[9] == 'X'){
            cout << "\nPlayer 1 wins!" << endl;
            playerWin = true;
        }else if(box[1] == 'X' && box[4] == 'X' && box[7] == 'X'){
            cout << "\nPlayer 1 wins!" << endl;
            playerWin = true;
        }else if(box[2] == 'X' && box[5] == 'X' && box[8] == 'X'){
            cout << "\nPlayer 1 wins!" << endl;
            playerWin = true;
        }else if(box[3] == 'X' && box[6] == 'X' && box[9] == 'X'){
            cout << "\nPlayer 1 wins!" << endl;
            playerWin = true;
        }else if(box[1] == 'X' && box[5] == 'X' && box[9] == 'X'){
            cout << "\nPlayer 1 wins!" << endl;
            playerWin = true;
        }else if(box[3] == 'X' && box[5] == 'X' && box[7] == 'X'){
            cout << "\nPlayer 1 wins!" << endl;
            playerWin = true;
        }else{
            playerWin = false;
        }

    }else if (player == 2){
        if (box[1] == 'O' && box[2] == 'O' && box[3] == 'O'){
            cout << "\nPlayer 2 wins!" << endl;
            playerWin = true;
        }else if(box[4] == 'O' && box[5] == 'O' && box[6] == 'O'){
            cout << "\nPlayer 2 wins!" << endl;
            playerWin = true;
        }else if(box[7] == 'O' && box[8] == 'O' && box[9] == 'O'){
            cout << "\nPlayer 2 wins!" << endl;
            playerWin = true;
        }else if(box[1] == 'O' && box[4] == 'O' && box[7] == 'O'){
            cout << "\nPlayer 2 wins!" << endl;
            playerWin = true;
        }else if(box[2] == 'O' && box[5] == 'O' && box[8] == 'O'){
            cout << "\nPlayer 2 wins!" << endl;
            playerWin = true;
        }else if(box[3] == 'O' && box[6] == 'O' && box[9] == 'O'){
            cout << "\nPlayer 2 wins!" << endl;
            playerWin = true;
        }else if(box[1] == 'O' && box[5] == 'O' && box[9] == 'O'){
            cout << "\nPlayer 2 wins!" << endl;
            playerWin = true;
        }else if(box[3] == 'O' && box[5] == 'O' && box[7] == 'O'){
            cout << "\nPlayer 2 wins!" << endl;
            playerWin = true;
        }else{
            playerWin = false;
        }
    }

    
}