#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void initializeBoard(char board[3][3]) {
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            board[i][j] = '-';
}

void printBoard(char board[3][3]) {
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

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

int getUserInput() {
    int slot;
    cout << "Enter slot (1-9): ";
    cin >> slot;
    return slot;
}

void convertToIndex(int slot, int &row, int &col) {
    row = (slot - 1) / 3;
    col = (slot - 1) % 3;
}

int main() {
    char board[3][3];
    char currentPlayer, p1Symbol, p2Symbol;

    initializeBoard(board);
    printBoard(board);

    toss(currentPlayer, p1Symbol, p2Symbol);


    int slot = getUserInput();

    int row, col;
    convertToIndex(slot, row, col);

    cout << "Row: " << row << ", Column: " << col << endl;

    return 0;
}