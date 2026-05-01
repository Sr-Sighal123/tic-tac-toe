#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// UC1
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

// UC2
void toss(char &currentPlayer, char &p1Symbol, char &p2Symbol) {
    srand(time(0));
    int result = rand() % 2;

    if(result == 0) {
        currentPlayer = '1';
        p1Symbol = 'X';
        p2Symbol = 'O';
        cout << "Player starts and is X" << endl;
    } else {
        currentPlayer = '2';
        p2Symbol = 'X';
        p1Symbol = 'O';
        cout << "Computer starts and is X" << endl;
    }
}

// UC3
int getUserInput() {
    int slot;
    cout << "Enter slot (1-9): ";
    cin >> slot;
    return slot;
}

// UC4
void convertToIndex(int slot, int &row, int &col) {
    row = (slot - 1) / 3;
    col = (slot - 1) % 3;
}

// UC5
bool isValidMove(char board[3][3], int row, int col) {
    if(row < 0 || row > 2 || col < 0 || col > 2)
        return false;

    if(board[row][col] != '-')
        return false;

    return true;
}

// UC6
void placeMove(char board[3][3], int row, int col, char symbol) {
    board[row][col] = symbol;
}

// UC7
int getRandomSlot() {
    return rand() % 9 + 1;
}

// Main
int main() {
    char board[3][3];
    char currentPlayer, p1Symbol, p2Symbol;

    initializeBoard(board);
    printBoard(board);

    toss(currentPlayer, p1Symbol, p2Symbol);

    int row, col, slot;

    // -------- PLAYER TURN --------
    if(currentPlayer == '1') {

        slot = getUserInput();
        convertToIndex(slot, row, col);

        if(isValidMove(board, row, col)) {
            placeMove(board, row, col, p1Symbol);
        } else {
            cout << "Invalid Move!" << endl;
            return 0;
        }

        cout << "\nBoard after player move:\n";
        printBoard(board);

        currentPlayer = '2'; // switch to computer
    }

    // -------- COMPUTER TURN --------
    if(currentPlayer == '2') {

        do {
            slot = getRandomSlot();
            convertToIndex(slot, row, col);
        } while(!isValidMove(board, row, col));

        cout << "\nComputer chose slot: " << slot << endl;

        placeMove(board, row, col, p2Symbol);

        cout << "\nBoard after computer move:\n";
        printBoard(board);
    }

    return 0;
}