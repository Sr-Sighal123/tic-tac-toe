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

// UC8 helpers
// UC9: Check winning condition (rows, columns, diagonals)
bool checkWin(char board[3][3], char symbol) {
    // Rows & Columns
    for(int i=0;i<3;i++) {
        if(board[i][0]==symbol && board[i][1]==symbol && board[i][2]==symbol)
            return true;
        if(board[0][i]==symbol && board[1][i]==symbol && board[2][i]==symbol)
            return true;
    }

    // Diagonals
    if(board[0][0]==symbol && board[1][1]==symbol && board[2][2]==symbol)
        return true;

    if(board[0][2]==symbol && board[1][1]==symbol && board[2][0]==symbol)
        return true;

    return false;
}

bool checkDraw(char board[3][3]) {
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(board[i][j] == '-')
                return false;

    return true;
}

// Main
int main() {
    char board[3][3];
    char currentPlayer, p1Symbol, p2Symbol;

    initializeBoard(board);
    printBoard(board);

    toss(currentPlayer, p1Symbol, p2Symbol);

    bool gameOver = false;

    while(!gameOver) {

        int slot, row, col;

        // -------- PLAYER TURN --------
        if(currentPlayer == '1') {

            slot = getUserInput();
            convertToIndex(slot, row, col);

            if(isValidMove(board, row, col)) {
                placeMove(board, row, col, p1Symbol);
            } else {
                cout << "Invalid Move! Try again.\n";
                continue;
            }

            cout << "\nBoard after player move:\n";
            printBoard(board);

            // Check win
            if(checkWin(board, p1Symbol)) {
                cout << "\nPlayer Wins!\n";
                gameOver = true;
            }
            else if(checkDraw(board)) {
                cout << "\nGame Draw!\n";
                gameOver = true;
            }
            else {
                currentPlayer = '2'; // switch
            }
        }

        // -------- COMPUTER TURN --------
        else {

            do {
                slot = getRandomSlot();
                convertToIndex(slot, row, col);
            } while(!isValidMove(board, row, col));

            cout << "\nComputer chose slot: " << slot << endl;

            placeMove(board, row, col, p2Symbol);

            cout << "\nBoard after computer move:\n";
            printBoard(board);

            // Check win
            if(checkWin(board, p2Symbol)) {
                cout << "\nComputer Wins!\n";
                gameOver = true;
            }
            else if(checkDraw(board)) {
                cout << "\nGame Draw!\n";
                gameOver = true;
            }
            else {
                currentPlayer = '1'; // switch
            }
        }
    }

    return 0;
}