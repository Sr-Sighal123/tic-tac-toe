#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// UC1: Initialize board
void initializeBoard(char board[3][3]) {
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            board[i][j] = '-';
}

// UC1: Print board
void printBoard(char board[3][3]) {
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// UC2: Toss function
void toss(char &currentPlayer, char &p1Symbol, char &p2Symbol) {
    srand(time(0));
    int result = rand() % 2;

    if(result == 0) {
        currentPlayer = '1';
        p1Symbol = 'X';
        p2Symbol = 'O';
        cout << "Player 1 starts and is X" << endl;
    } else {
        currentPlayer = '2';
        p2Symbol = 'X';
        p1Symbol = 'O';
        cout << "Player 2 starts and is X" << endl;
    }
}

// UC3: User input
int getUserInput() {
    int slot;
    cout << "Enter slot (1-9): ";
    cin >> slot;
    return slot;
}

// Main function
int main() {
    char board[3][3];
    char currentPlayer, p1Symbol, p2Symbol;

    // UC1
    initializeBoard(board);
    printBoard(board);

    // UC2
    toss(currentPlayer, p1Symbol, p2Symbol);

    // UC3
    int slot = getUserInput();
    cout << "You entered: " << slot << endl;

    return 0;
}