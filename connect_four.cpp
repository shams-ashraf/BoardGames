#include "connect_four.h"
using namespace std;
connect_four::connect_four () {
    n_rows =6, n_cols = 7;
    board = new char *[n_rows];
    for (int k = 0; k < n_rows; k++) {
        board[k] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[k][j] = 0;
    }
}
bool connect_four::update_board (int x, int y, char mark) {
    int c = 0;
    if (!(x < 0 || x > 5 || y < 0 || y > 6&&board[x][y]==0)) {
        if (board[n_rows - 1][y] == 0) {
            board[n_rows - 1][y] = toupper(mark);
        }
        else {
            for (int i = 0; i < n_rows; i++) {
                if (board[i][y] != 0) {
                    c++;
                }
            }
            board[5 - c][y] = toupper(mark);
        }
        n_moves++;
        return true;
    }
    else{
        cout<<"false position";
        return false;
    }
}
void connect_four::display_board(){
        for (int i: {0,1,2,3,4,5}) {
            cout << "\n| ";
            for (int j: {0,1,2,3,4,5,6}) {
                cout << "(" << i << "," << j << ")";
                cout << setw(2) << board [i][j] << " |";
            }
        }
        cout << endl;
}
bool connect_four::is_winner() {
        for (int i = 0; i < n_rows; i++) {
            for (int j = 0; j < n_cols; j++) {
                if (board[i][j] != 0) {
                    // Check horizontally
                    if (j + 3 < n_cols &&
                        board[i][j] == board[i][j + 1] &&
                        board[i][j] == board[i][j + 2] &&
                        board[i][j] == board[i][j + 3]) {
                        return true;
                    }
                    // Check vertically
                    if (i + 3 < n_rows &&
                        board[i][j] == board[i + 1][j] &&
                        board[i][j] == board[i + 2][j] &&
                        board[i][j] == board[i + 3][j]) {
                        return true;
                    }
                    // Check diagonally (up-right)
                    if (i + 3 < n_rows && j + 3 < n_cols &&
                        board[i][j] == board[i + 1][j + 1] &&
                        board[i][j] == board[i + 2][j + 2] &&
                        board[i][j] == board[i + 3][j + 3]) {
                        return true;
                    }
                    // Check diagonally (up-left)
                    if (i + 3 < n_rows && j - 3 >= 0 &&
                        board[i][j] == board[i + 1][j - 1] &&
                        board[i][j] == board[i + 2][j - 2] &&
                        board[i][j] == board[i + 3][j - 3]) {
                        return true;
                    }
                }
            }
        }
        return false;
}
bool connect_four::is_draw() {
    return (n_moves == 42 && !is_winner());
}
bool connect_four::game_is_over () {
    return n_moves >= 42;
}