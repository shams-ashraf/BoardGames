#include "tic_tac_toe_5x5.h"
tic_tac_toe_5x5::tic_tac_toe_5x5 () {
    n_rows =5, n_cols = 5;
    board = new char *[n_rows];
    for (int k = 0; k < n_rows; k++) {
        board[k] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[k][j] = 0;
    }
}
bool tic_tac_toe_5x5::update_board (int x, int y, char mark) {
    if (!(x < 0 || x > 4 || y < 0 || y > 4) && board[x][y]==0) {
            board[x][y] = toupper(mark);
            n_moves++;
            return true;
    }
    else{
        cout<<"false position"<<endl;
        return false;}
}
void tic_tac_toe_5x5::display_board(){
        for (int i: {0,1,2,3,4}) {
            cout << "\n| ";
            for (int j: {0,1,2,3,4}) {
                cout << "(" << i << "," << j << ")";
                cout << setw(2) << board [i][j] << " |";
            }
        }
        cout << endl;
        if(n_moves==24) {
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    if (board[i][j] == 'X') {
                        if (i + 2 < 5 && board[i][j] == board[i + 1][j] && board[i][j] == board[i + 2][j])
                            count_x++;
                        else if (j + 2 < 5 && board[i][j] == board[i][j + 1] && board[i][j] == board[i][j + 2])
                            count_x++;
                        else if (i + 2 < 5 && j + 2 < n_cols && board[i][j] == board[i + 1][j + 1] &&
                                 board[i][j] == board[i + 1][j + 2])
                            count_x++;
                        else if (i + 2 < 5 && j - 2 < n_cols && board[i][j] == board[i + 1][j - 1] &&
                                 board[i][j] == board[i + 2][j - 2])
                            count_x++;
                    }
                    if (board[i][j] == 'O') {
                        if (i + 2 < 5 && board[i][j] == board[i + 1][j] && board[i][j] == board[i + 2][j]) count_o++;
                        if (j + 2 < 5 && board[i][j] == board[i][j + 1] && board[i][j] == board[i][j + 2]) count_o++;
                        if (i + 2 < 5 && j + 2 < n_cols && board[i][j] == board[i + 1][j + 1] &&
                            board[i][j] == board[i + 1][j + 2])
                            count_o++;
                        if (i + 2 < 5 && j - 2 < n_cols && board[i][j] == board[i + 1][j - 1] &&
                            board[i][j] == board[i + 2][j - 2])
                            count_o++;
                    }
                }
            }
        }
    if(count_x>count_o){
        cout<<"X wins with "<<count_x<<" points"<<endl;
        cout<<"O lose with "<<count_o<<" points"<<endl;
    }
    else if(count_x< count_o){
        cout<<"O wins with "<<count_o<<" points"<<endl;
        cout<<"X lose with "<<count_x<<" points"<<endl;
    }
}
bool tic_tac_toe_5x5::is_winner() {
            return false;
}
bool tic_tac_toe_5x5::is_draw() {
    return (n_moves == 24 && count_x==count_o && count_x!=0);
}
bool tic_tac_toe_5x5::game_is_over () {
    return n_moves >= 24;
}
