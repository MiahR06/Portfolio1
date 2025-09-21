#include <iostream>
using namespace std;

char box[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

void display();
void playerX(int i);

int main(){

    cout << display();

}

void display(){

    cout << "\n " << box[1] << " | " << box[2] << " | " << box[3] << endl;
    cout << "-----------" << endl; 
    cout << " " << box[4] << " | " << box[5] << " | " << box[6] << endl;
    cout << "-----------" << endl; 
    cout << " " << box[7] << " | " << box[8] << " | " << box[9] << endl << endl;
}

void playerX(int i){
    cout << "Player X, enter a number to choose a square: ";
    cin >> i;

    while (box[i]){
        if (box[i] == 'X' || box[i] == 'O'){
            cout << "That space is taken. Try again: " << endl;
        }else if (box[i] != 'X' || box[i] != 'O'){
        box[i] = 'X';
        break;
        }
    }
}