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
        cout << "Player 1 starts and is X\n";
    } else {
        currentPlayer = '2';
        p2Symbol = 'X';
        p1Symbol = 'O';
        cout << "Player 2 starts and is X\n";
    }
}

int main() {
    char board[3][3];
    char currentPlayer, p1Symbol, p2Symbol;

    initializeBoard(board);
    printBoard(board);

    toss(currentPlayer, p1Symbol, p2Symbol);

    return 0;
}