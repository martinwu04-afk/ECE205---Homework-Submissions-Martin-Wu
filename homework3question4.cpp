#include <iostream>
using namespace std;

char board[9];

void initboard() {
    for (int i = 0; i < 9; i++) {
        board[i] = '1' + i;
    }
}

void displayboard() {
    for (int i = 0; i < 9; i++) {
        cout << board[i];
        if ((i + 1) % 3 == 0) {
            cout << endl;
        } else {
            cout << "   ";
        }
    }
    cout << endl;
}

bool checkwin(char player) {
    int wins[8][3] = {{0,1,2}, {3,4,5}, {6,7,8}, {0,3,6}, {1,4,7}, {2,5,8}, {0,4,8}, {2,4,6}};
    for (int i = 0; i < 8; i++) {
        if (board[wins[i][0]] == player && board[wins[i][1]] == player && board[wins[i][2]] == player) {
            return true;
        }
    }
    return false;
}

bool boardfull() {
    for (int i = 0; i < 9; i++) {
        if (board[i] != 'X' && board[i] != 'O') {
            return false;
        }
    }
    return true;
}

int main() {
    initboard();
    char players[] = {'X', 'O'};
    int turn = 0;

    cout << "Tic-Tac-Toe!\n\n";
    displayboard();

    while (true) {
        char current = players[turn % 2];
        int pos;

        cout << "Player " << current << ", enter position (1-9): ";
        while (!(cin >> pos) || pos < 1 || pos > 9 || board[pos-1] == 'X' || board[pos-1] == 'O') {
            cout << "Invalid or taken, try again: ";
        }

        board[pos - 1] = current;
        displayboard();

        if (checkwin(current)) {
            cout << "Player " << current << " wins!\n";
            break;
        }
        if (boardfull()) {
            cout << "It's a draw!\n";
            break;
        }

        turn++;
    }
    return 0;
}
