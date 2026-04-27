// UC1: Display empty Tic Tac Toe board
#include <iostream>
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

int main() {
    char board[3][3];

    initializeBoard(board);
    printBoard(board);

    return 0;
}